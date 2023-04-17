clc;
clear all;
port_num = 17;
ts = 0.0005;
%DC 모터의 실제 parameter estimation

set_param('in_gps_estimation/voltage', 'Value', '12');
sim("in_gps_estimation.slx"); %모터구동 시작

filt_length = 10;
i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i);
w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w);

for j = 1:200
    i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i_filtered);
    w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w_filtered);
end

final_time = length(true_time);

figure(1);
plot(true_time, i_filtered, 'r');
title('current'); xlabel('time(sec)'); ylabel('current[A]');

figure(2);
plot(true_time, w_filtered,'r');
title('speed'); xlabel('time(sec)'); ylabel('speed[rad/sec]');

% i_dot = filtfilt(ones(filt_length,1)/filt_length, 1, i_dot); %무부하 구동을 통해 구한 전류값을 필터링
% w_dot = filtfilt(ones(filt_length,1)/filt_length,1, w_dot); %무부하 구동을 통해 구한 회전속도를 필터링

for index = 2:final_time-1
    w_dot(index) = (w_filtered(index+1)-w_filtered(index-1))/(true_time(index+1)-true_time(index-1));
    i_dot(index) = (i_filtered(index+1)-i_filtered(index-1))/(true_time(index+1)-true_time(index-1));
end

for i = 1:1000
w_dot = filtfilt(ones(filt_length,1)/filt_length,1, w_dot);
i_dot = filtfilt(ones(filt_length,1)/filt_length,1, i_dot);
end

for index = 3:final_time-2
    w_ddot(index) = (w_dot(index+1)-w_dot(index-1))/(true_time(index+1)-true_time(index-1));
    i_ddot(index) = (i_dot(index+1)-i_dot(index-1))/(true_time(index+1)-true_time(index-1));
    dudt(index) = (input_voltage(index+1)-input_voltage(index-1))/(true_time(index+1)-true_time(index-1));
end

for i = 1:1000
w_ddot = filtfilt(ones(filt_length,1)/filt_length,1, w_ddot);
i_ddot = filtfilt(ones(filt_length,1)/filt_length,1, i_ddot);
dudt = filtfilt(ones(filt_length,1)/filt_length,1, dudt);
end

figure(3);
plot(true_time(2:final_time), w_dot);
title('angle acceleration');

figure(4);
plot(true_time(3:final_time), w_ddot);
title('angle jerk');


figure(5);
plot(true_time(2:final_time), i_dot);
title('i_dot');


figure(6);
plot(true_time(3:final_time), i_ddot);
title('i_ddot');


interval = 50:final_time-100;

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