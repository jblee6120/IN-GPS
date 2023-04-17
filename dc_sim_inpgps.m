ts = 0.0005; %sampling time = 0.0001s
%R = 3.0391; %resistance
L = L_hat(1); %inductance
%Km = 0.0101; %Torque constant
Jm_hat = 8.0583e-06; %inertia
%Bm = 1.9182e-06; %friction constant
%Kb = Km; %bemf와 토크상수는 동일
A = [ -R/L -K_hat/L 0;
    K_hat/Jm_hat -Bm/Jm_hat 0;
      0     1    0]; %3차 시스템의 계수행렬 A

B = [ 1/L; 0 ; 0]; %3차 시스템의 B

C = eye(3); %3*3 단위행렬

D = [0;0;0;];