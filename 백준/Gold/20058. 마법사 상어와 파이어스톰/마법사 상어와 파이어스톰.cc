#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N, Q;
int A[70][70];
int sum;
int ans;
int zip[70][70];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void input() {
	cin >> N >> Q;
	for (register int y = 0; y < pow(2, N); ++y) {
		for (register int x = 0; x < pow(2, N); ++x) {
			cin >> A[y][x];
		}
	}
}

void rotate(int sy, int sx, int L) {
	int num = pow(2, L) / 2;
	for (register int square = num; square > 0; --square) {
		int len = 2 * square;

		vector<int> tmp;

		for (register int y = sy; y < (sy + 1); ++y) {
			for (register int x = sx; x < (len + sx - 1); ++x) {
				tmp.push_back(A[y + (num - square)][x + (num - square)]);
			}
		}
		int ny = sy + (num - square);
		int nx = sx + (num - square);

		for (register int i = 0; i < (len - 1); ++i) {
			A[ny][i + nx] = A[len + ny - (1 + i)][nx];
		}
		for (register int i = 0; i < (len - 1); ++i) {
			A[len + ny - (1 + i)][nx] = A[len + ny - 1][len + nx - (1 + i)];
		}
		for (register int i = 0; i < (len - 1); ++i) {
			A[len + ny - 1][len + nx - (1 + i)] = A[i + ny][len + nx - 1];
		}
		for (register int i = 0; i < (len - 1); ++i) {
			A[i + ny][len + nx - 1] = tmp[i];
		}

		// #1
		/* A[0][0] = A[0][1];
		// 
		// A[0][1] = A[1][1];
		// 
		// A[1][1] = A[1][0];
		// 
		// A[1][0] = tmp;
		// 
		// 
		// A[0][2] = A[0][3];
		// 
		// A[0][3] = A[1][3];
		// 
		// A[1][3] = A[1][2];
		// 
		// A[1][2] = tmp;
		// 
		// 
		// A[2][0] = A[2][1];
		// 
		// A[2][1] = A[3][1];
		// 
		// A[3][1] = A[3][0];
		// 
		// A[3][0] = tmp;
		*/
		// #2
		/* A[0][0] = A[0][2]
		// A[0][1] = A[1][2]
		// 
		// A[0][2] = A[2][2]
		// A[1][2] = A[2][1]
		// 
		// A[2][2] = A[2][0]
		// A[2][1] = A[1][0]
		// 
		// A[2][0] = tmp[0]
		// A[1][0] = tmp[1]
		*/

		/* #3
		// A[0][0] = A[0][3]
		// A[0][1] = A[1][3]
		// A[0][2] = A[2][3]
		*/

	}
}

bool check_ice(int nowY, int nowX, int maxN) {
	int cnt = 0; // 얼음이 없으면 cnt++

	for (register int i = 0; i < 4; ++i) {
		int ny = nowY + dy[i];
		int nx = nowX + dx[i];

		if (ny < 0 || ny >= maxN || nx < 0 || nx >= maxN) {
			++cnt;
			continue;
		}
		if (A[ny][nx] <= 0) ++cnt;
	}

	if (cnt >= 2) return true;
	else return false;
}

void find_zip(int sy, int sx, int maxN, int flag) {
	queue < pair<int, int>> q;
	int used[70][70] = { 0, };

	q.push({ sy,sx });
	used[sy][sx] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		zip[now.first][now.second] = flag;
		q.pop();

		for (register int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= maxN || nx < 0 || nx >= maxN) continue;
			if (zip[ny][nx] != 0) continue;
			if (used[ny][nx] == 1) continue;

			if (A[ny][nx] > 0) {
				used[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
}

void find_ans(int flag, int maxN) {
	int cnt = 0;
	for (register int y = 0; y < maxN; ++y) {
		for (register int x = 0; x < maxN; ++x) {
			if (zip[y][x] == flag) ++cnt;
		}
	}

	if (cnt > ans) ans = cnt;
}

void sol() {
	input();
	int maxN = pow(2, N);
	for (register int num = 0; num < Q; ++num) {
		int L = 0;
		cin >> L;

		int len_cut = pow(2, L);

		for (register int y = 0; y < maxN; y += len_cut) { // 90도 회전
			for (register int x = 0; x < maxN; x += len_cut) {
				rotate(y, x, L);
				// y -> 회전시킬 맵 행시작
				// x -> 회전시킬 맵 열시작
				// L -> 회전시킬 맵 가로, 세로 길이 결정 요소
			}
		}

		int cpy[64][64] = { 0, };

		for (register int y = 0; y < maxN; ++y) { // 맵 복사
			for (register int x = 0; x < maxN; ++x) {
				cpy[y][x] = A[y][x];
			}
		}

		for (register int y = 0; y < maxN; ++y) {
			for (register int x = 0; x < maxN; ++x) {
				if (check_ice(y, x, maxN) == true) {
					cpy[y][x] = A[y][x] - 1;
				}
				else cpy[y][x] = A[y][x];
			}
		}

		for (register int y = 0; y < maxN; ++y) { // 맵 복사
			for (register int x = 0; x < maxN; ++x) {
				A[y][x] = cpy[y][x];
			}
		}
	}
	for (register int y = 0; y < maxN; ++y) { // 남은 얼음
		for (register int x = 0; x < maxN; ++x) {
			if (A[y][x] > 0) sum += A[y][x];
		}
	}

	int flag = 1;
	for (register int y = 0; y < maxN; ++y) { // 가장 큰 덩어리 찾기
		for (register int x = 0; x < maxN; ++x) {
			if ((zip[y][x] == 0)&&(A[y][x] > 0)) {
				find_zip(y, x, maxN, flag);
				++flag;
			}
		}
	}

	for (register int i = 1; i <= flag; ++i) {
		find_ans(i, maxN);
	}

	if (ans <= 1) cout << sum << '\n' << 0;
	else cout << sum << '\n' << ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}