#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[20][20];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct ANS {
	int max_area;
	int sy;
	int sx;
	int rainbow_block_num;
	int normal_block_num;
};
ANS ans;
int score;

void delete_block() {
	int area = 0;
	queue<pair<int, int>> q;
	int used[20][20] = { 0, };

	q.push({ ans.sy,ans.sx });
	map[ans.sy][ans.sx] = -2;
	used[ans.sy][ans.sx] = 1;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (register int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == -2) continue;
			if (map[ny][nx] == -1)continue;
			if (map[ny][nx] != 0 && map[ny][nx] != ans.normal_block_num) continue;

			map[ny][nx] = -2;
			used[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}

	for (register int cy = 0; cy < N; ++cy) { // 블록카운팅
		for (register int cx = 0; cx < N; ++cx) {
			if (used[cy][cx] == 1) ++area;
		}
	}

	score += (area * area);
}
void gravity_effect() {
	for (register int y = (N - 2); y >= 0; --y) {
		for (register int x = (N - 1); x >= 0; --x) {
			if (map[y][x] >= 0 && map[y + 1][x] == -2) {
				int ny = y + 1;
				while (map[ny][x] == -2) {
					if (ny >= N) break;
					int tmp = map[ny][x];
					map[ny][x] = map[ny - 1][x];
					map[ny - 1][x] = tmp;
					++ny;
				}
			}
		}
	}
}
void rotate() {
	int times = N / 2;

	for (register int num = 0; num < times; ++num) { // 맵 크기별 돌리는 횟수
		vector<int> tmp;
		for (register int i = num; i < (N - (1 + num)); ++i) {
			tmp.push_back({ map[i][num] });
		}
		for (register int i = num; i < (N - (1 + num)); ++i) {
			map[i][num] = map[num][N - (i + 1)];
		}
		for (register int i = num; i < (N - (1 + num)); ++i) {
			map[num][N - (i + 1)] = map[N - (i + 1)][(N - (1 + num))];
		}
		for (register int i = num; i < (N - (1 + num)); ++i) {
			map[N - (i + 1)][(N - (1 + num))] = map[(N - (1 + num))][i];
		}
		for (register int i = num; i < (N - (1 + num)); ++i) {
			map[(N - (1 + num))][i] = tmp[i - num];
		}
	}
}
void output() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (map[y][x] == -2) cout << "_\t";
			else cout << map[y][x] << "\t";
		}
		cout << '\n';
	}
	cout << '\n';
}

void find_block(int (&used)[6][20][20]) {
	for (register int nb_num = 1; nb_num <= M; ++nb_num) { // normal block 숫자
		for (register int y = 0; y < N; ++y) {
			for (register int x = 0; x < N; ++x) {
				if (used[nb_num][y][x] == 1) continue; // 이미 그룹이 있는 블록
				if (map[y][x] == -1 || map[y][x] == -2 || map[y][x] == 0)continue;
				
				if (map[y][x] == nb_num) {
					queue<pair<int, int>> q;

					q.push({ y,x });
					used[nb_num][y][x] = 1;
					
					while (!q.empty()) {
						pair<int, int> now = q.front();
						q.pop();

						for (register int i = 0; i < 4; ++i) {
							int ny = now.first + dy[i];
							int nx = now.second + dx[i];

							if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 맵 벗어남
							if (used[nb_num][ny][nx] == 1) continue; // 이미 지나온 곳
							if (map[ny][nx] == -1)continue; // 검정 블록
							if (map[ny][nx] == -2)continue; // 빈칸
							if (map[ny][nx] != nb_num && map[ny][nx] != 0)continue; // 일반 블록 숫자가 다르고, 무지개 블록이 아니면

							used[nb_num][ny][nx] = 1;
							q.push({ ny,nx });
						}
					}
				}
			}
		}
	}
}

void bfs(int (&used)[6][20][20], int(&check)[20][20], int num, int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	check[y][x] = 1;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (register int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (used[num][ny][nx] != 1) continue;
			if (check[ny][nx] == 1) continue;

			check[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

void update_block(int(&used)[6][20][20], int(&check)[20][20], int num) {
	int area = 0; // 면적
	int rb_num = 0; // 무지개 블록 수
	int stdY = 999;
	int stdX = 999;
	for (register int y = 0; y < N; ++y) {
		for (register int x = 0; x < N; ++x) {
			if (check[y][x] != 1) continue;
			if (map[y][x] == 0) ++rb_num; // 무지개 블록 증가
			++area; // 면적 증가
			if (map[y][x] > 0) { // 일반 블록이라면
				if (stdY > y) {
					stdY = y;
					stdX = x;
				}
				else if (stdY == y) {
					if (stdX > x) {
						stdY = y;
						stdX = x;
					}
				}
			}
			used[num][y][x] = -2; // 이미 처리 끝난 그룹이면 다시 볼 필요 없음
		}
	}

	if (ans.max_area < area) {
		ans.max_area = area;
		ans.rainbow_block_num = rb_num;
		ans.normal_block_num = num;
		ans.sy = stdY;
		ans.sx = stdX;
	}
	else if (ans.max_area == area) {
		if (ans.rainbow_block_num < rb_num) {
			ans.max_area = area;
			ans.rainbow_block_num = rb_num;
			ans.normal_block_num = num;
			ans.sy = stdY;
			ans.sx = stdX;
		}
		else if (ans.rainbow_block_num == rb_num) {
			if (ans.sy < stdY) {
				ans.max_area = area;
				ans.rainbow_block_num = rb_num;
				ans.normal_block_num = num;
				ans.sy = stdY;
				ans.sx = stdX;
			}
			else if (ans.sy == stdY) {
				if (ans.sx < stdX) {
					ans.max_area = area;
					ans.rainbow_block_num = rb_num;
					ans.normal_block_num = num;
					ans.sy = stdY;
					ans.sx = stdX;
				}
			}
		}
	}
}

void select_block(int(&used)[6][20][20]) {
	for (register int nb_num = 1; nb_num <= M; ++nb_num) {
		for (register int y = 0; y < N; ++y) {
			for (register int x = 0; x < N; ++x) {
				if (used[nb_num][y][x] == 1) {
					int check[20][20] = { 0, };
					bfs(used, check, nb_num, y, x); // O(400)

					update_block(used, check, nb_num); // O(400)
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (register int y = 0; y < N; ++y) {
		for (register int x = 0; x < N; ++x) {
			cin >> map[y][x];
		}
	}
	while (1) {
		ans = { -1,-1,-1,-1,-1 };
		
		int used[6][20][20] = { 0, };
		find_block(used); // O(6 * 400 * 400)
		select_block(used); // O(6 * 400 * 400)

		//cout << ans.max_area;

		if (ans.max_area < 2) break;

		/*cout << "점수 : " << score << "\n";
		cout << "시작\n";
		output();
		delete_block();
		cout << "블록제거\n"<< "블록 수 : " << ans.max_area << "\n";
		output();
		gravity_effect();
		cout << "중력작용\n";
		output();
		rotate();
		cout << "회전\n";
		output();
		gravity_effect();
		cout << "중력작용\n";
		output();*/

		delete_block(); // O(N*N)
		gravity_effect(); // O(19 * 20)
		rotate(); // O(10 * 9)
		gravity_effect(); // O(19 * 20)
	}

	cout << score;


	return 0;
}