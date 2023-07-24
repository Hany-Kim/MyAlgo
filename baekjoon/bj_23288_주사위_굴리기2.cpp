#include <iostream>

using namespace std;

// N x M 지도

//처음 주사위 이동 방향은 "동쪽"
//주사위가 이동 방향으로 한 칸 굴러간다.
// 만약, 이동 방향에 칸이 없다면, 이동 방향을 "반대"로 한 다음 한 칸 굴러간다.
//주사위가 "도착한 칸(x, y)에 대한 점수를 획득"한다.
//주사위 바닥면(A) & 지도 좌표위 정수 값 비교(B)
//	A > B인 경우 이동 방향을 90도 시계 방향으로 회전시킨다.
//	A < B인 경우 이동 방향을 90도 반시계 방향으로 회전시킨다.
//	A = B인 경우 이동 방향에 변화는 없다.

int N, M, K;
int map[21][21];
int dice[4][3] = {
	0,2,0,
	4,1,3,
	0,5,0,
	0,6,0
};

void input() {
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> map[y][x];
		}
	}
}


void solution() {
	input();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}