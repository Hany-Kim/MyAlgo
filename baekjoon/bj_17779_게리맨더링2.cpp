#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
최대한 공평하게 선거구를 획정
구역을 다섯 개의 선거구로 나눠야 하고, 각 구역은 다섯 선거구 중 하나에 포함
선거구는 구역을 적어도 하나 포함해야 하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다.
*/
/*
2,4 2,2
2,2 >= 1
1<= 2 < 6 <= 7
1<= 2 < 4 < 6 <= 7
---
1번 선거구
1 <= r < 4
1 <= c <= 4

2번선거구
1 <= r <= 4
4 < c <= 7

3번선거구
4 <= r <= 7
1 <= c < 4

4번선거구
4 < r <= 7
4 <= c <= 7
*/
int N;
int A[21][21];
struct COORD {
	int x;
	int y;
};
COORD Pos[4]; // 경계선 꼭지점
int Label[21][21];
int Answer = 213456789;

bool CanMakeLine(int x, int y, int d1, int d2) {
	// 경계선 그릴 수 있는지
	if (x + d1 >= N || y - d1 < 0)return false;
	if (x + d2 >= N || y + d2 >= N) return false;
	if (x + d1 + d2 >= N || y - d1 + d2 >= N)return false;
	if (x + d2 + d1 >= N || y + d2 - d1 < 0)return false;
	return true;
}

void Calc() {
	int Sum[6] = { 0, };
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			Sum[Label[x][y]] = Sum[Label[x][y]] + A[x][y];
		}
	}
	sort(Sum, Sum + 6);
	int Diff = Sum[5] - Sum[1];
	Answer = min(Answer, Diff);
}

void Labeling(int a, int b, int c, int d) {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			Label[x][y] = 5;
		}
	}

	// 1번선거구
	int SubArea = 0;
	for (int x = 0; x < Pos[1].x; x++) {
		if (x >= Pos[0].x) SubArea++;
		for (int y = 0; y <= Pos[0].y - SubArea; y++) {
			Label[x][y] = 1;
		}
	}
	// 2번선거구
	int PlusArea = 0;
	for (int x = 0; x <= Pos[2].x; x++) {
		if (x > Pos[0].x)PlusArea++;
		for (int y = Pos[0].y + 1 + PlusArea; y < N; y++) {
			Label[x][y] = 2;
		}
	}
	// 3번 선거구
	SubArea = 0;
	for (int x = N - 1; x >= Pos[1].x; x--) {
		if (x < Pos[3].x)SubArea++;
		for (int y = 0; y < Pos[3].y - SubArea; y++) {
			Label[x][y] = 3;
		}
	}
	// 4번 선거구
	PlusArea = 0;
	for (int x = N - 1; x > Pos[2].x; x--) {
		if (x <= Pos[3].x) PlusArea++;
		for (int y = Pos[3].y + PlusArea; y < N; y++) {
			Label[x][y] = 4;
		}
	}
	Calc();
}

void sol() {
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> A[x][y];
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 1; y < N; y++) {
			for (int d1 = 1; d1 <= y; d1++) {
				for (int d2 = 1; d2 <= (N-d1); d2++) {
					if (CanMakeLine(x, y, d1, d2) == true) {
						Pos[0].x = x;
						Pos[0].y = y;
						Pos[1].x = x + d1;
						Pos[1].y = y - d1;
						Pos[2].x = x + d2;
						Pos[2].y = y + d2;
						Pos[3].x = x + d1 + d2;
						Pos[3].y = y - d1 + d2;
						Labeling(x, y, d1, d2);
					}
				}
			}
		}
	}
	cout << Answer;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}