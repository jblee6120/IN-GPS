clc;
clear all;
port_num = 17;
ts = 0.0005;
V = 1.8;
lpf = designfilt('lowpassiir','FilterOrder',4,'StopbandFrequency',10,'StopbandAttenuation',60,'SampleRate',2000);
%DC 모터의 실제 parameter estimation

%input voltage = 1.4 인가 후, 전류센서장치로 전류를 측정하는 과정
%시뮬링크 동작시간은 10초이므로 반드시 모터의 샤프트를 꽉 잡고 있어야 함.
%시험단계에서는 손으로 잡지만, 자동화로 완성되면 자동으로 잡는 장치 마련해야 함.
set_param('in_gps_estimation/voltage', 'Value', '1.5');
sim("in_gps_estimation.slx"); %모터구동 시작

filt_length = 10;
i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i);
%i_filtered = filtfilt(lpf,i);
w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w);
%w_filtered = filtfilt(lpf, w);
%vo_filtered = filtfilt(ones(filt_length,1)/filt_length,1, vo);

figure(1);
plot(true_time, i_filtered, 'r');

figure(2);
plot(true_time, w_filtered,'r');

%plot(true_time, w, 'b');


final_time = length(true_time)-1;
i_avg = mean(i_filtered(final_time-100: final_time));
R = abs(input_voltage(final_time)/i_avg);

%Kb, Km 구하기. 샤프트를 멈춘 후 stall torque와 전류를 이용해 Tm = Km*i를 이용해 구하거나
%무부하 운전을 하고 Kb = (v-i*R)/w로 구하거나
%무부하 운전에서 최소자승법을 사용한다.
%무부하 운전 시, 커플링까지 반드시 제거한 뒤 측정해야 함.
set_param('in_gps_estimation/voltage', 'Value', '10');
sim("in_gps_estimation.slx");

i_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, i); %무부하 구동을 통해 구한 전류값을 필터링
w_filtered = filtfilt(ones(filt_length,1)/filt_length,1, w); %무부하 구동을 통해 구한 회전속도를 필터링

i_avg = mean(i_filtered(final_time-100:final_time)); %최종값을 구하기 위해 마지막 100개의 값들을 평균낸다
w_avg = mean(w_filtered(final_time-100:final_time));

i_dot = filtfilt(ones(filt_length,1)/filt_length, 1, i_dot); %무부하 구동을 통해 구한 전류값을 필터링
w_dot = filtfilt(ones(filt_length,1)/filt_length,1, w_dot); %무부하 구동을 통해 구한 회전속도를 필터링
%최소자승법을 사용해서 K를 구한다
b = input_voltage-i_filtered*R;
Kb_lsq = (w_filtered'*w_filtered)^-1*w_filtered'*b; %최소자승법을 통해 구한 Kb
Kb_hat = (input_voltage-i_avg*R)/w_avg; %비교를 위해 Kb = (v-i*R)/w로 구함

%Stall torque를 인가한다
%Km_hat = Ts/i(final_time);

K_hat = Kb_lsq; %K값을 저장

%Bm 구하기
Bm = K_hat*input_voltage(final_time-1)/(R*w_filtered(final_time-1))-K_hat^2/R;

interval = 100:final_time;
%L 구하기
% len = final_time -2; %didt를 구하기 위한 배열의 길이 저장
% 
% didt = zeros(len, 1); %didt를 저장하기 위한 배열 생성
% dwdt = zeros(len, 1); %dwdt를 저장하기 위한 배열 생성
% 
% %didt, dwdt를 구하기 위해 반복문을 수행
% for index = 2:final_time-1
%     didt(index) = (i_filtered(index+1)-i_filtered(index-1))/(true_time(index+1)-true_time(index-1));
%     dwdt(index) = (w_filtered(index+1)-w_filtered(index-1))/(true_time(index+1)-true_time(index-1));
% end
% 
% i_filtered(1) = []; i_filtered(final_time) = []; %행렬계산을 위해 필터링 된 데이터의 양 끝을 없앤다
% w_filtered(1) = []; w_filtered(final_time) = []; 
% input_voltage(1) = []; input_voltage(final_time) = [];
% 
% didt_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, didt); %didt에 노이즈가 있으므로 필터링
% dwdt_filtered = filtfilt(ones(filt_length,1)/filt_length, 1, dwdt); %dwdt에 노이즈가 있으므로 필터링

% didt = (-R/L)*i + (-Kb/L)*w + (1/L)*V를 이용해 최소자승법으로 L을 구하자
X(:,1) = i_filtered(interval);
X(:,2) = w_filtered(interval);
X(:,3) = input_voltage(interval);
Y(:,1) = i_dot(interval);

mat_L = (X'*X)^-1*X'*Y; %L은 바로 나오는 것이 아니라 3가지 성분에 섞여서 나옴

L_hat_a = -R / mat_L(1,1); %첫번째 성분으로 구한 L
L_hat_b = -Kb_hat / mat_L(2,1); %두번째 성분으로 구한 L
L_hat_c = 1 / mat_L(3,1); %세번째 성분으로 구한 L
L_hat = (L_hat_a + L_hat_b + L_hat_c) / 3; %세가지를 성분들을 평균내서 정확한 추정값을 구한다

%Jm구하기
% w dot = (Km/Jm)*i + (-Bm/Jm)*w 의 식을 least square를 사용하기 위해 새로운 matrix 형태로 만들어준다, (-1/Jm)*TL 텀은 TL = 0이므로 제외
X_Jm(:,1) = i_filtered; X_Jm(:,2) = w_filtered;
mat_Jm = (X_Jm'*X_Jm)^-1*X_Jm'*w_dot;
Jm_hat_a = K_hat / mat_Jm(1,1);
Jm_hat_b = -Bm / mat_Jm(2,1);
Jm_hat = (Jm_hat_a + Jm_hat_b) / 2;