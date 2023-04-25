clc;
clear all;
port_num = 17;
ts = 0.0005;
%DC 모터의 실제 parameter estimation

set_param('in_gps_estimation/voltage', 'Value', '12');
sim("in_gps_estimation.slx"); %모터구동 시작

%zero-phase filter를 전류, 전압 데이터에 적용하는 과정
filt_length = 10;
i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i);
w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w);

%추가적엔 zero-phase filter적용과정. 추후 더 효과적인 필터(kalman filter등)를 적용시켜야 함.
for j = 1:200
    i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i_filtered);
    w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w_filtered);
end


final_time = length(true_time);

%필터링 된 전류데이터 plot
figure(1);
plot(true_time, i_filtered, 'r');
title('current'); xlabel('time(sec)'); ylabel('current[A]');

%필터링 된 각속도 데이터 plot
figure(2);
plot(true_time, w_filtered,'r');
title('speed'); xlabel('time(sec)'); ylabel('speed[rad/sec]');

%각가속도, 전류의 도함수를 구하는 반복문
%central difference를 이용해서 구한다.
for index = 2:final_time-1
    w_dot(index) = (w_filtered(index+1)-w_filtered(index-1))/(true_time(index+1)-true_time(index-1));
    i_dot(index) = (i_filtered(index+1)-i_filtered(index-1))/(true_time(index+1)-true_time(index-1));
end

%각가속도, 전류 도함수에도 noise가 있으므로 zero-phase filter적용. 이것도 추후 더 나은 filter를 사용해야함.
for i = 1:1000
w_dot = filtfilt(ones(filt_length,1)/filt_length,1, w_dot);
i_dot = filtfilt(ones(filt_length,1)/filt_length,1, i_dot);
end

%최소자승법을 사용하기 위해서는 각속도와 전류의 이계도함수가 필요함. 따라서 이계도함수를 구하는 과정
for index = 3:final_time-2
    w_ddot(index) = (w_dot(index+1)-w_dot(index-1))/(true_time(index+1)-true_time(index-1));
    i_ddot(index) = (i_dot(index+1)-i_dot(index-1))/(true_time(index+1)-true_time(index-1));
    dudt(index) = (input_voltage(index+1)-input_voltage(index-1))/(true_time(index+1)-true_time(index-1)); %입력전압의 도함수도 최소자승법 적용을 통해 전류의 전달함수를 구할때 필요하므로 구한다.
end

%이계도함수의 값들에 zero-phase filter를 적용하는 과정
for i = 1:1000
w_ddot = filtfilt(ones(filt_length,1)/filt_length,1, w_ddot);
i_ddot = filtfilt(ones(filt_length,1)/filt_length,1, i_ddot);
dudt = filtfilt(ones(filt_length,1)/filt_length,1, dudt);
end

%각가속도 plot
figure(3);
plot(true_time(2:final_time), w_dot);
title('angle acceleration');

%각 가가속도 plot
figure(4);
plot(true_time(3:final_time), w_ddot);
title('angle jerk');

%전류 도함수 plot
figure(5);
plot(true_time(2:final_time), i_dot);
title('i_dot');

%전류 이계도함수 plot
figure(6);
plot(true_time(3:final_time), i_ddot);
title('i_ddot');

%최소자승법 적용을 위한 구간을 정의한다.
interval = 50:final_time-100; %최소자승법에 사용되는 시간 배열의 index를 저장.

X(:,1) = -w_dot(interval);
X(:,2) = -w_filtered(interval);
X(:,3) = input_voltage(interval);
Y(:,1) = w_ddot(interval);

param = (X'*X)^-1*X'*Y;

a2 = param(1);
a1 = param(2);
a0 = param(3);

Xc(:,1) = -i_dot(interval);
Xc(:,2) = -i_filtered(interval);
Xc(:,3) = -dudt(interval);
Xc(:,4) = -input_voltage(interval);
Yc(:,1) = i_ddot(interval);

param = (Xc'*Xc)^-1*Xc'*Yc;

b3 = param(1);
b2 = param(2);
b1 = param(3);
b0 = param(4);


sim("dcsimul.slx");

figure(7);
plot(true_time, w_filtered); hold on;
plot(true_time, w_sim); hold on;
title('simulation speed and real speed');
xlabel('time(sec)');
ylabel('rad/sec')

figure(8);
plot(true_time, i_filtered); hold on;
plot(true_time, i_sim); hold on;
title('simulation current and real current');
legend('real','sim');