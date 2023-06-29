clc;
clear all;
close all;
port_num = 12;
ts = 0.0005;
cpr = 4096;

set_param('in_gps_estimation/Manual Switch', 'sw', '0');
% set_param('in_gps_estimation/voltage', 'Value', '12');
sim("in_gps_estimation.slx"); %모터구동 시작

%zero-phase filter를 전류, 전압 데이터에 적용하는 과정
filt_length = 10;
w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w);

%추가적인 zero-phase filter적용과정. 추후 더 효과적인 필터(kalman filter등)를 적용시켜야 함.
for j = 1:2
    w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w_filtered);
end
w_real = w_filtered;

L = 0.00033;
R=1.13;
K=0.0603;
B=6.48e-06;
J=0.0000137;

%시뮬링크로 추정된 파라미터로 구한 결과와 실제 결과를 비교
A = [ -R/L -K/L 0;
    K/J -B/J 0;
      0     1    0]; %3차 시스템의 계수행렬 A

B = [ 1/L; 0 ; 0]; %3차 시스템의 B

C = eye(3); %3*3 단위행렬

D = [0;0;0;];

sim("dcsimul.slx");
w_given= w_ss;



L_hat = 0.0295;
R_hat = 4.6077;
K_hat = 0.0585;
B_hat = 0.0000222;
J_hat = 0.0000126;

%시뮬링크로 추정된 파라미터로 구한 결과와 실제 결과를 비교
A = [ -R_hat/L_hat -K_hat/L_hat 0;
    K_hat/J_hat -B_hat/J_hat 0;
      0     1    0]; %3차 시스템의 계수행렬 A

B = [ 1/L_hat; 0 ; 0]; %3차 시스템의 B

C = eye(3); %3*3 단위행렬

D = [0;0;0;];   

sim("dcsimul.slx");
w_est = w_ss;
plot(tout,w_real,tout,w_given,tout,w_est);
legend('w real','w given','w estimation');

