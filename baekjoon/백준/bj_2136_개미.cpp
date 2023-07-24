#include <iostream>
#include <queue>

using namespace std;
// 길이가 L(2 ≤ L ≤ 1,000,000,000(십억))인 막대기 위에 
// 개미 N(1 ≤ N ≤ 100,000)마리
// 0 ≤ 죄표 ≤L
// 1초에 1칸씩 이동 (좌우) - 부딪히는 경우 O
// 개미가 부딪히면 즉시 방향을 바꿔 이동
// 좌표를 벗어나면 떨어짐
// 
// ouput
// 1. 가장 마지막에 떨어지는 개미
// 2. 그 개미가 떨어진 시간
//
// 초기 위치: +X (X는 개미위치) / ->
// 초기 위치: -X (X는 개미위치) / <-

int N, L;
int init_pos;
int stick[7][2]; // 0과 L+1이되면 낙사시키기위해 L+2배열 생성, 개미번호(num)저장
queue <int> pos;
int turn;
int num = 1;
int rightMax;
int leftMax;
int leftNum, rightNum;

int ans;

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> init_pos;
		pos.push(init_pos);
	}
}

void arrangement() {
	// 배치
	while (!pos.empty()) {
		int ant_pos = pos.front();

		// 방향 저장
		if (ant_pos < 0) {
			stick[abs(ant_pos)][0] = -1; // 초기 위치: -X (X는 개미위치) / <-
			stick[abs(ant_pos)][1] = num;
		}
		else {
			stick[abs(ant_pos)][0] = 1; // 초기 위치: +X (X는 개미위치) / ->
			stick[abs(ant_pos)][1] = num;
		}
		num++;
	}
}

int compare() {
	for (int i = 1; i <= L; i++) {
		if (stick[i][0] == -1) {
			leftMax = i;
		}
	}
	for (int i = L; i >= 1; i--) {
		if (stick[i][0] == 1) {
			rightMax = i;
		}
	}

	if (leftMax >= (L - rightMax)) {
		return rightMax;
	}
	else if (leftMax < (L - rightMax)) {
		return (L - leftMax);
	}
}

void solution() {
	input();
	arrangement();
	ans = compare();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}