clc;
clear all;
close all;
port_num = 3;
ts = 0.0005;
ts_control = ts*10;
cpr = 4096; %각 모터에 장착된 encoder의 cpr을 적어준다. RE40의 경우 4096, pololu의 경우 64
sw_freq = 20e+03;
%DC 모터의 실제 parameter estimation

A = eye(3);
B = [ 1; 0 ; 0]; %3차 시스템의 B

C = eye(3); %3*3 단위행렬

D = [0;0;0;];

set_param('in_gps_estimation/Manual Switch', 'sw', '0');
% set_param('in_gps_estimation/voltage', 'Value', '12');
sim("in_gps_estimation.slx"); %모터구동 시작

%zero-phase filter를 전류, 전압 데이터에 적용하는 과정
filt_length = 10;
i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i);
w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w);

%추가적인 zero-phase filter적용과정. 추후 더 효과적인 필터(kalman filter등)를 적용시켜야 함.
for j = 1:2
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
for i = 1:2
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
for i = 1:2
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

%최소자승법으로 각속도 전달함수의 파라미터를 구하는 과정
X(:,1) = -w_dot(interval);
X(:,2) = -w_filtered(interval);
X(:,3) = input_voltage(interval);
Y(:,1) = w_ddot(interval);

param = (X'*X)^-1*X'*Y; %최소자승법으로 구한 각속도 전달함수의 파라미터 배열

a2 = param(1);
a1 = param(2);
a0 = param(3); %W/U = a0/(s^2 + a1*s + a2*s)의 형태로 나온다. 이 파라미터들을 시뮬링크를 이용한 전달함수에 사용함.

sim("dcsimul.slx");

figure(7);
plot(true_time, w_filtered); hold on;
plot(true_time, w_sim); hold on;
title('simulation speed and real speed');
xlabel('time(sec)');
ylabel('rad/sec')

figure(8);
plot(true_time, i_filtered); hold on;
% plot(true_time, i_sim); hold on;
title('simulation current and real current');
legend('real','sim');

%Parameter Identification of a DC Motor: An Experimental Approach 논문을 참고하여
%모든 파라미터를 구하는 부분
%참고: 전류 센싱보드의 정확한 calibration이 필요함. 나머지는 문제없음.
%단자전압의 경우 시뮬링크 상의 지령치를 그대로 사용할 것.
%사실, 정확한 parameter estimation을 하려면 단자전압도 ADC로 읽어와서 계산해야 함.
%단자전압이 최대 12V로 높기 때문에, 전압의 scaling을 해주는 pcb 제작이 필요함.

M = zeros(2,5);
Rm = zeros(5,5);
Rmy = zeros(5,1);
y = zeros(2,1);

%Rm, Rmy를 구하는 과정
for j = interval
    M(1,1) = i_dot(j);
    M(1,2) = i_filtered(j);
    M(1,3) = w_filtered(j);
    M(2,3) = -i_filtered(j);
    M(2,4) = w_dot(j);
    M(2,5) = w_filtered(j);
    y = [input_voltage(j); 0];

    Rm = Rm + M'*M;
    Rmy = Rmy + M'*y;
end

%Rm*K_hat = Rmy이므로 최소자승법으로 K_hat을 추정한다.
K_hat = inv(Rm'*Rm)*Rm'*Rmy;

L_hat = K_hat(1); R_hat = K_hat(2); K = K_hat(3); J_hat = K_hat(4); B_hat = K_hat(5);

%시뮬링크로 추정된 파라미터로 구한 결과와 실제 결과를 비교
A = [ -R_hat/L_hat -K/L_hat 0;
    K/J_hat -B_hat/J_hat 0;
      0     1    0]; %3차 시스템의 계수행렬 A

B = [ 1/L_hat; 0 ; 0]; %3차 시스템의 B

C = eye(3); %3*3 단위행렬

D = [0;0;0;];

sim("dcsimul.slx");

figure(9);
plot(true_time, w_filtered); hold on;
plot(true_time, w_sim); hold on;
plot(true_time, w_ss, 'm'); hold on;
title('simulation speed and real speed');
xlabel('time(sec)');
ylabel('rad/sec'); legend('w-real', 'w-tf', 'w-ss');

figure(10);
plot(true_time, i_filtered); hold on;
plot(true_time, i_ss); hold on;
title('simulation current and real current');
legend('i-real','i-ss');

%속도제어기 대역폭
wcs = 1/(ts*20)*2*pi;
%속도제어기의 P계수
Kps = J_hat*wcs/K;
%속도제어기의 I계수
Kis = J_hat*wcs^2/(5*K);
%속도제어기의 anti-windup 계수
Kas = 1/Kps;

% %인덕턴스 추정? 시정수를 통해 정확한 인덕턴스를 구하는 과정
% set_param('in_gps_estimation/Manual Switch', 'sw', '1');
% sim("in_gps_estimation.slx"); %모터구동 시작
% 
% %zero-phase filter를 전류, 전압 데이터에 적용하는 과정
% filt_length = 10;
% i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i);
% w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w);
% 
% %추가적인 zero-phase filter적용과정. 추후 더 효과적인 필터(kalman filter등)를 적용시켜야 함.
% for j = 1:2
%     i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i_filtered);
%     w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w_filtered);
% end
% 
% %각가속도, 전류의 도함수를 구하는 반복문
% %central difference를 이용해서 구한다.
% for index = 2:final_time-1
%     w_dot(index) = (w_filtered(index+1)-w_filtered(index-1))/(true_time(index+1)-true_time(index-1));
%     i_dot(index) = (i_filtered(index+1)-i_filtered(index-1))/(true_time(index+1)-true_time(index-1));
% end
% 
% %각가속도, 전류 도함수에도 noise가 있으므로 zero-phase filter적용. 이것도 추후 더 나은 filter를 사용해야함.
% for i = 1:2
% w_dot = filtfilt(ones(filt_length,1)/filt_length,1, w_dot);
% i_dot = filtfilt(ones(filt_length,1)/filt_length,1, i_dot);
% end
% 
% voltage = input_voltage(2:final_time);
% X_L = i_dot'; Y = voltage - R_hat*i_filtered(2:final_time);
% 
% L_1 = -inv(X_L'*X_L)*X_L'*Y;
% 
% A = [ -R_hat/L_1 -K/L_1 0;
%     K/J_hat -B_hat/J_hat 0;
%       0     1    0]; %3차 시스템의 계수행렬 A
% 
% B = [ 1/L_1; 0 ; 0]; %3차 시스템의 B
% 
% sim("dcsimul.slx");