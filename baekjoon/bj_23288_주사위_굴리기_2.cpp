#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N_MAX 20 + 1
#define M_MAX 20 + 1
#define FOR(i,s,e) for(int i=s; i<e; ++i)

struct DICE { // 주사위의 정보를 담은 구조체
	int y;
	int x;
	int dir;
	vector<vector<int>> dice_num{ // 주사위 전개도
		{0, 2, 0, 0},
		{ 4,1,3,6 },
		{ 0,5,0,0 },
		{ 0,6,0,0 }
	};
};
int N, M, K;
int map[N_MAX][M_MAX];
int dy[4] = { 0,1,0,-1 }; // 동 남 북 서
int dx[4] = { 1,0,-1,0 };
DICE dice;
int score;

void init_dice() {
	dice.y = 1;
	dice.x = 1;
	dice.dir = 0; // 시작은 동쪽
}

bool isMove() {
	/*
	주사위가 설정한 방향으로 이동이 가능한지 확인

	가능하다면 true
	불가능하다면 false
	*/
	int ny = dice.y + dy[dice.dir];
	int nx = dice.x + dx[dice.dir];

	if (ny < 1 || ny > N || nx < 1 || nx > M) return false;

	return true;
}

void roll_dice() {
	if (dice.dir == 0 || dice.dir == 2) {
		if (dice.dir == 0) { // 주사위를 동쪽으로 굴린다.
			vector<int> tmp = dice.dice_num[1];
			tmp = { tmp[3], tmp[0], tmp[1], tmp[2] };
			dice.dice_num[1] = tmp;
		}
		else if (dice.dir == 2) { // 주사위를 서쪽으로 굴린다.
			vector<int> tmp = dice.dice_num[1];
			tmp = { tmp[1], tmp[2], tmp[3], tmp[0] };
			dice.dice_num[1] = tmp;
		}
		dice.dice_num[3][1] = dice.dice_num[1][3]; // 주사위 전개도상 '아랫면'에 해당하는 부분 업데이트
	}
	else if (dice.dir == 1 || dice.dir == 3) {
		if (dice.dir == 1) { // 주사위를 남쪽으로 굴린다.
			vector<int> tmp = { dice.dice_num[0][1], dice.dice_num[1][1], dice.dice_num[2][1], dice.dice_num[3][1] };
			tmp = { tmp[3], tmp[0], tmp[1], tmp[2] };
			dice.dice_num[0][1] = tmp[0];
			dice.dice_num[1][1] = tmp[1];
			dice.dice_num[2][1] = tmp[2];
			dice.dice_num[3][1] = tmp[3];
		}
		else if (dice.dir == 3) { // 주사위를 북쪽으로 굴린다.
			vector<int> tmp = { dice.dice_num[0][1], dice.dice_num[1][1], dice.dice_num[2][1], dice.dice_num[3][1] };
			tmp = { tmp[1], tmp[2], tmp[3], tmp[0] };
			dice.dice_num[0][1] = tmp[0];
			dice.dice_num[1][1] = tmp[1];
			dice.dice_num[2][1] = tmp[2];
			dice.dice_num[3][1] = tmp[3];
		}
		dice.dice_num[1][3] = dice.dice_num[3][1]; // 주사위 전개도상 '아랫면'에 해당하는 부분 업데이트
	}
}

int bfs() {
	/*
	지도상에서 주사위가 이동한 위치의 정수 값과 
	동서남북으로 인접한 좌표에 일치하는 값이 있는지 탐색

	val은 지도상에서 주사위가 이동한 위치의 정수 값 저장
	cnt는 동일한 값이 인접한 좌표에 몇개가 존재하는지 찾음
	*/
	queue<pair<int, int>> q;
	int used[N_MAX][M_MAX] = { 0, };

	int val = map[dice.y][dice.x];
	int cnt = 1;

	q.push(make_pair(dice.y, dice.x));
	used[dice.y][dice.x] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		FOR(i, 0, 4) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny<1 || ny>N || nx<1 || nx>M) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] != val)continue;

			used[ny][nx] = 1;
			++cnt;
			q.push(make_pair(ny, nx));
		}
	}

	return cnt;
}

void move_dice() {
	/*
	주사위를 이동시켰을 때,
	주사위의 좌표, 방향, 전개도, 획득한 점수 등을
	업데이트 해주는 함수
	*/
	if (isMove() == false) {
		// 주사위가 이동할 수 없는 방향이라면 반대 방향으로 바꿔줌
		if (dice.dir == 0) dice.dir = 2;
		else if (dice.dir == 2) dice.dir = 0;
		else if (dice.dir == 1) dice.dir = 3;
		else if (dice.dir == 3) dice.dir = 1;
	}

	// 주사위가 이동한 좌표 업데이트
	dice.y = dice.y + dy[dice.dir];
	dice.x = dice.x + dx[dice.dir];

	// 주사위를 굴렸을 때 바뀐 전개도 업데이트
	roll_dice();

	// 주사위가 획득한 점수 계산
	int s = bfs();
	score += (map[dice.y][dice.x] * s);

	// A는 주사위의 '아랫면'의 눈의 값을 저장
	// B는 지도상에서 주사위가 이동한 위치의 정수 값
	int A = dice.dice_num[3][1];
	int B = map[dice.y][dice.x];

	if (A > B) { // A > B 라면 시계 방향으로 90도 회전
		dice.dir += 1;
		if (dice.dir >= 4) dice.dir = 0;
	}
	else if (A < B) { // A < B 라면 반시계 방향으로 90도 회전
		dice.dir -= 1;
		if (dice.dir < 0) dice.dir = 3;
	}
}

void sol() {
	init_dice();
	FOR(i, 0, K) {
		move_dice();
	}
	cout << score;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (M + 1)) {
			cin >> map[y][x];
		}
	}
	sol();

	return 0;
}