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

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		map[now.first][now.second] = -2;
		used[now.first][now.second] = 1;

		for (register int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == -2) continue;
			if (map[ny][nx] == -1)continue;
			if (map[ny][nx] != 0 && map[ny][nx] != ans.normal_block_num) continue;

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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	
	cin >> N >> M;
	for (register int y = 0; y < N; ++y) {
		for (register int x = 0; x < N; ++x) {
			cin >> map[y][x];
		}
	}
	while (1) {
		ans = { -1,-1,-1,-1,-1 };
		for (register int normal_block_num = 1; normal_block_num <= M; ++normal_block_num) {
			for (register int y = 0; y < N; ++y) {
				for (register int x = 0; x < N; ++x) {
					if (normal_block_num == map[y][x]) {
						int area = 0;
						int rb_block = 0;
						queue<pair<int, int>> q;
						int used[20][20] = { 0, };

						q.push({ y,x });

						while (!q.empty()) { // O(N*N)
							pair<int, int> now = q.front();
							q.pop();

							used[now.first][now.second] = 1;

							for (register int i = 0; i < 4; ++i) {
								int ny = now.first + dy[i];
								int nx = now.second + dx[i];

								if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
								if (used[ny][nx] == 1) continue;
								if (map[ny][nx] == -1)continue;
								if (map[ny][nx] == -2)continue;
								if (map[ny][nx] != 0 && map[ny][nx] != normal_block_num) continue;

								q.push({ ny,nx });
							}
						}

						int std_y = 999;
						int std_x = 999;
						for (register int cy = 0; cy < N; ++cy) { // 블록카운팅 & 기준블록세팅
							for (register int cx = 0; cx < N; ++cx) {
								if (used[cy][cx] == 1 && map[cy][cx] == 0) ++rb_block;
								if (used[cy][cx] == 1 && map[cy][cx] >= 0) {
									++area;
									if (map[cy][cx] != 0) { // 기준 블록세팅
										if (std_y > cy) {
											std_y = cy;
											std_x = cx;
										}
										else if (std_y == cy) {
											if (std_x > cx) {
												std_y = cy;
												std_x = cx;
											}
										}
									}
								}

							}
						}

						if (area > ans.max_area) {
							ans.sy = std_y;
							ans.sx = std_x;
							ans.max_area = area;
							ans.rainbow_block_num = rb_block;
							ans.normal_block_num = normal_block_num;
						}
						else if (area == ans.max_area) {
							if (ans.rainbow_block_num < rb_block) {
								ans.sy = std_y;
								ans.sx = std_x;
								ans.max_area = area;
								ans.rainbow_block_num = rb_block;
								ans.normal_block_num = normal_block_num;
							}
							else if (ans.rainbow_block_num == rb_block) {
								if (ans.sy < std_y) {
									ans.sy = std_y;
									ans.sx = std_x;
									ans.max_area = area;
									ans.rainbow_block_num = rb_block;
									ans.normal_block_num = normal_block_num;
								}
								else if (ans.sy == std_y) {
									if (ans.sx < std_x) {
										ans.sy = std_y;
										ans.sx = std_x;
										ans.max_area = area;
										ans.rainbow_block_num = rb_block;
										ans.normal_block_num = normal_block_num;
									}
								}
							}
						}
					}
				}
			}
		}
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