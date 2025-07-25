# [Gold I] 수학 미로 - 16475 

[문제 링크](https://www.acmicpc.net/problem/16475) 

### 성능 요약

메모리: 33548 KB, 시간: 316 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 7월 26일 11:30:55

### 문제 설명

<p>성일이는 성동구에서 미로탈출을 제일 잘하는 사람이다. 자신의 실력을 검증해보고 싶었던 성일이는, 세상의 모든 어려운 미로를 정복하기 위해 여행을 떠났다. 세계 각국의 어렵다 하는 미로를 손쉽게 정복하던 성일이는, 어느 날 난관에 부딪혔다. 이전과 다른 특징의 미로에 성일이는 혼란스러운 나머지 기절해버렸다. 미로의 특징은 다음과 같았다.</p>

<ol>
	<li>총 N개의 지역이 M개의 길로 이어져 있고, M개의 길은 통행할 수 있는 방향이 하나로 정해져 있다.</li>
	<li>각 지역의 번호는 1~N 사이의 정수이다.</li>
	<li>N개의 지역 중 K개의 지역에는 스위치가 있다. 스위치가 있는 지역에 방문할 때에는 스위치를 무조건 눌러야 한다. 이 지역들을 '함정 지역'이라고 부른다. M개의 길 중 L개의 길은 스위치를 P번 누를 때마다 방향이 거꾸로 변한다. 이 길들을 '함정 길'이라고 부른다. 스위치를 누른 횟수가 P번이 되면 함정 길들의 방향은 거꾸로 변하고, 스위치를 누른 횟수는 0으로 변한다. </li>
</ol>

<p>잠시 후 깨어난 성일이는, 너무 어려운 미로여서 우리에게 약간의 힌트를 얻고자 한다. 그가 필요로 하는 힌트는 출발지점에서 도착지까지 도달할 수 있는 가장 짧은 거리다. 성일이가 미로를 시작하는 출발점이 S, 도착점이 E라 할 때, 성일이가 미로를 탈출할 수 있도록 성일이가 원하는 힌트의 답을 알려주자.</p>

### 입력 

 <p>첫 번째 줄에 N, M, K, L, P, 값이 차례로 주어진다. (1 ≤ N, M ≤ 10,000, 0 ≤ K ≤ N, 0 ≤ L ≤ M, 1 ≤ P ≤ 10)</p>

<p>두 번째 줄에, K개의 함정지역의 번호가 주어진다.</p>

<p>세 번째 줄부터, M-L줄에 걸쳐, 일반 길의 정보가 A, B, C 값으로 주어진다. 이후 L줄에 걸쳐서, 함정 길의 정보가 A,B,C 값으로 주어진다. 이때 A지역에서 B지역으로 이어진 일방통행길 의 거리가 C이다. (0 < C ≤ 10,000)</p>

<p>마지막 줄에는 출발지 번호 S와 도착지 번호 E가 주어진다. 출발지점은 함정지역이 아니다.</p>

### 출력 

 <p>출발 지점에서 도착 지점으로 가는 최단경로를 출력한다.</p>

<p>경로가 없을 경우 -1을 출력한다.</p>

