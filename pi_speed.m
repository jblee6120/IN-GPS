close all;

set_param('pi_speed_control/Manual Switch', 'sw', '0');
sim("pi_speed_control.slx");
figure(1);
plot(time, w_ref); hold on;
plot(time, w_real); hold on;
title('PI speed control based on estimated parameter');
xlabel('time(sec)'); ylabel('speed(rad/sec)');
legend('reference speed', 'real speed');

set_param('pi_speed_control/Manual Switch', 'sw', '1');
sim("pi_speed_control.slx");
figure(2);
plot(time, w_ref); hold on;
plot(time, w_real); hold on;
title('PI speed control based on estimated parameter');
xlabel('time(sec)'); ylabel('speed(rad/sec)');
legend('reference speed', 'real speed');

%사용된 계수
%Kps = 0.1354
%Kis = 17.0110
%Kas = 7.3872