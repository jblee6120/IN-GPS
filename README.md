# IN-GPS
IN-GPS 프로젝트로 Motor의 R,L,K,J,B를 실제 모터를 구동하여 정확한 값을 구하는 시스템을 만드는 프로젝트.
현재까지 진행상황(2023/04/18)
1. 최소자승법을 이용한 parameter estimation으로 각속도 모델의 정확한 parameter를 구했음.
2. 다만, 전류모델은 발산하는 결과가 나올 뿐더러 정확하지 않은 값이 측정됨.
3. 영위상 필터를 여러번 적용시킨 데이터를 활용하는데, 더 간단한 방법을 찾아야 함.
4. 입력전압-전류 사이의 정확한 전달함수의 형태를 미분방정식을 통해 구해야 함.
5. 전류 센싱 보드의 정확성 문제가 매번 발생함. 항상 calibration을 진행시키는 번거로움 존재.
6. 5개의 값(R,L,K,J,B)를 구할 수 있는 연립방정식을 찾는다면 해결이 가능할 것으로 보임.