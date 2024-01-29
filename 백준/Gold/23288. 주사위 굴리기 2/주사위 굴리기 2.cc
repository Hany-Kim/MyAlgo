#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N_MAX 20 + 1
#define M_MAX 20 + 1
#define FOR(i,s,e) for(int i=s; i<e; ++i)

struct DICE {
	int y;
	int x;
	int dir;
	vector<vector<int>> dice_num{
		{0, 2, 0, 0},
		{ 4,1,3,6 },
		{ 0,5,0,0 },
		{ 0,6,0,0 }
	};
};
int N, M, K;
int map[N_MAX][M_MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
DICE dice;
int score;

void init_dice() {
	dice.y = 1;
	dice.x = 1;
	dice.dir = 0; // 시작은 동쪽
}

bool isMove() {
	int ny = dice.y + dy[dice.dir];
	int nx = dice.x + dx[dice.dir];

	if (ny < 1 || ny > N || nx < 1 || nx > M) return false;

	return true;
}

void roll_dice() {
	if (dice.dir == 0 || dice.dir == 2) {
		if (dice.dir == 0) {
			vector<int> tmp = dice.dice_num[1];
			tmp = { tmp[3], tmp[0], tmp[1], tmp[2] };
			dice.dice_num[1] = tmp;
		}
		else if (dice.dir == 2) {
			vector<int> tmp = dice.dice_num[1];
			tmp = { tmp[1], tmp[2], tmp[3], tmp[0] };
			dice.dice_num[1] = tmp;
		}
		dice.dice_num[3][1] = dice.dice_num[1][3];
	}
	else if (dice.dir == 1 || dice.dir == 3) {
		if (dice.dir == 1) {
			vector<int> tmp = { dice.dice_num[0][1], dice.dice_num[1][1], dice.dice_num[2][1], dice.dice_num[3][1] };
			tmp = { tmp[3], tmp[0], tmp[1], tmp[2] };
			dice.dice_num[0][1] = tmp[0];
			dice.dice_num[1][1] = tmp[1];
			dice.dice_num[2][1] = tmp[2];
			dice.dice_num[3][1] = tmp[3];
		}
		else if (dice.dir == 3) {
			vector<int> tmp = { dice.dice_num[0][1], dice.dice_num[1][1], dice.dice_num[2][1], dice.dice_num[3][1] };
			tmp = { tmp[1], tmp[2], tmp[3], tmp[0] };
			dice.dice_num[0][1] = tmp[0];
			dice.dice_num[1][1] = tmp[1];
			dice.dice_num[2][1] = tmp[2];
			dice.dice_num[3][1] = tmp[3];
		}
		dice.dice_num[1][3] = dice.dice_num[3][1];
	}
}

int bfs() {
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
	if (isMove() == false) {
		if (dice.dir == 0) dice.dir = 2;
		else if (dice.dir == 2) dice.dir = 0;
		else if (dice.dir == 1) dice.dir = 3;
		else if (dice.dir == 3) dice.dir = 1;
	}

	dice.y = dice.y + dy[dice.dir];
	dice.x = dice.x + dx[dice.dir];

	roll_dice();

	int s = bfs();
	score += (map[dice.y][dice.x] * s);

	int A = dice.dice_num[3][1];
	int B = map[dice.y][dice.x];

	if (A > B) {
		dice.dir += 1;
		if (dice.dir >= 4) dice.dir = 0;
	}
	else if (A < B) {
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

	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (M + 1)) {
			cin >> map[y][x];
		}
	}
	sol();

	return 0;
}