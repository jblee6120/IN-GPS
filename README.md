# IN-GPS(Caution: 제작자가 주로 사용한 언어는 Matlab script임. C언어는 시뮬링크 파일 생성시 생긴 것을 그대로 커밋/푸쉬해서 생긴 것)
IN-GPS 프로젝트로 Motor의 R,L,K,J,B를 실제 모터를 구동하여 정확한 값을 구하는 시스템을 만드는 프로젝트.
현재까지 진행상황(2023/04/18)
1. 최소자승법을 이용한 parameter estimation으로 각속도 모델의 정확한 parameter를 구했음.
2. 다만, 전류모델은 발산하는 결과가 나올 뿐더러 정확하지 않은 값이 측정됨.
3. 영위상 필터를 여러번 적용시킨 데이터를 활용하는데, 더 간단한 방법을 찾아야 함.
4. 입력전압-전류 사이의 정확한 전달함수의 형태를 미분방정식을 통해 구해야 함.
5. 전류 센싱 보드의 정확성 문제가 매번 발생함. 항상 calibration을 진행시키는 번거로움 존재.
6. 5개의 값(R,L,K,J,B)를 구할 수 있는 연립방정식을 찾는다면 해결이 가능할 것으로 보임.

2023/04~2023/05/24 진행상황
in_gps_est.m
1. 시뮬레이션에 쓰이는 상태공간 행렬 만들었음
2. zero-phase를 2번만 적용시켰음
3. 인덕턴스를 더 정확하게 구하기 위해서 전기적 시정수를 통해 인덕턴스 구하는 방식을 시도해봤음.(line 179~)
4. 논문 참고하여(Parameter Identification of a DC Motor: An Experimental Approach) 모든 파라미터를 최소자승법으로 구함(line128~177)
5. 속도모델은 정확하게 구했지만, motor encoder의 cpr(counter per revolution)을 잘못 적용시켰다. 따라서 정확한 cpr을 통한 parameter estimation을 수행시키면 정확한 parameter값이 나올 것으로 기대됨.
6. 추정결과를 토대로(cpr이 잘못되어 실제 회전속도값 자체가 뻥튀기된 값이지만) 실제속도와 시뮬레이션 속도, 실제 전류와 시뮬레이션 전류를 비교하는 plot도 만들었음.(estimation_speed_result.fig, estimation_current_result.fig)

parameter estimation으로 구한 파라미터들로 PI 속도 제어기를 구성해 모터의 속도제어를 수행하는 시뮬링크 파일 pi_speed_control.slx 만들었음.
중간발표성과로 추정된 파라미터로 구한 P,I 계수로 만든 PI제어기가 fine tuning만 거치면 원활한 모터제어가 가능하다는 것을 증명하면 됨.(제어기 구성이 간편함)

이후 최종발표에서는 BLDC의 파라미터를 구해서 정확한 파라미터 추정값을 기반으로 한 시뮬레이션과 실측값의 유사성을 증명해야 함.
또한 제어기(전류, 속도, 위치)를 구성해서 우리가 구한 파라미터들이 정확하며, 빠르고 낮은 가격으로 파라미터를 구할 수 있으며, BLDC의 파라미터를 성공적으로 구할 수 있다면,
동기전동기, 유도전동기의 파라미터를 정확히 구해 벡터제어에 필요한 파라미터들을 구할 수 있다는 가능성을 증명해야 함.

2023/05/25 진행상황
in_gps_est.m
1. 추정한 파라미터로 모터 속도제어에 필요한 P,I 계수를 구하는 스크립트 추가.
2. 시정수를 활용한 방법은 주석처리해서 아직 사용하지 않음.
3. 제어기 계수를 이용해서 바로 속도제어를 실행하는 m파일도 만들었음.

pi_speed.m (new_file)
1. 실제 모터(Maxon RE40)의 속도제어 시뮬링크 파일 pi_speed.slx을 실행하고 그 결과를 플롯하는 스크립트 작성완료.
2. 결과들은 fig파일로 저장했음.(speed_result.fig)

pi_control_sim.slx
1. parameter estimation으로 구한 모터의 파라미터들을 기반으로 한 상태공간과 제어기 계수를 통해 시뮬레이션으로 모터의 속도, 전류제어를 하는 시뮬링크 파일
2. 시뮬레이션 결과는 speed_sim_result_const_input.fig, speed_sim_result_sine_input.fig, current_sim_const_input.fig, current_sim_result_sine_input.fig으로 저장했음.
3. 전류제어의 경우, 원래 샘플링 주파수가 10kHz정도는 되어야 제어가 가능하다. 하지만 LW-RCP의 최대 샘플링 주파수가 2kHz이므로 발산하지 않는 제어가 어렵다고 판단해 안전상의 이유로 실제 모터에 대한 전류제어는 하지 않았음.
