#include <iostream>
using namespace std;

int N;
int A[500][500];
int dy[4] = { 0,1,0,-1 }; // 왼 아 오 위 순환
int dx[4] = { -1,0,1,0 };
int score;

int test[7][7];

void input() {
	cin >> N;
	for (register int y = 0; y < N; ++y) {
		for (register int x = 0; x < N; ++x) {
			cin >> A[y][x];
		}
	}
}

void spread_sand(int r, int c, int dir) { // r,c 모래 쌓인 위치
	int nDir = 0;
	int std = A[r][c];

	// 1%
	int std_1 = (std * 1) / 100;
	if (std_1 > 0) {
		if (dir == 0) {
			nDir = 2;
		// 왼
		// r-1 c+1
		// r+1 c+1
			int ny1 = r + 1 + dy[nDir];
			int ny2 = r - 1 + dy[nDir];
			int nx = c + dx[nDir];

			if (ny1 < 0 || ny1 >= N || nx < 0 || nx >= N) score += std_1; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny1][nx] += std_1;
			A[r][c] -= std_1;

			if (ny2 < 0 || ny2 >= N || nx < 0 || nx >= N) score += std_1; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny2][nx] += std_1;
			A[r][c] -= std_1;
		}
		else if (dir == 1) {
			nDir = 3;
		// 아
		// r-1 c-1
		// r-1 c+1
			int ny = r + dy[nDir];
			int nx1 = c - 1 + dx[nDir];
			int nx2 = c + 1 + dx[nDir];

			if (ny < 0 || ny >= N || nx1 < 0 || nx1 >= N) score += std_1; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx1] += std_1;
			A[r][c] -= std_1;

			if (ny < 0 || ny >= N || nx2 < 0 || nx2 >= N) score += std_1; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny][nx2] += std_1;
			A[r][c] -= std_1;
		}
		else if (dir == 2) {
			nDir = 0;
		// 오
		// r-1 c-1
		// r+1 c-1
			int ny1 = r + 1 + dy[nDir];
			int ny2 = r - 1 + dy[nDir];
			int nx = c + dx[nDir];

			if (ny1 < 0 || ny1 >= N || nx < 0 || nx >= N) score += std_1; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny1][nx] += std_1;
			A[r][c] -= std_1;

			if (ny2 < 0 || ny2 >= N || nx < 0 || nx >= N) score += std_1; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny2][nx] += std_1;
			A[r][c] -= std_1;
		}
		else if (dir == 3) {
			nDir = 1;
		// 위
		// r+1 c-1
		// r+1 c+1
			int ny = r + dy[nDir];
			int nx1 = c - 1 + dx[nDir];
			int nx2 = c + 1 + dx[nDir];

			if (ny < 0 || ny >= N || nx1 < 0 || nx1 >= N) score += std_1; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx1] += std_1;
			A[r][c] -= std_1;

			if (ny < 0 || ny >= N || nx2 < 0 || nx2 >= N) score += std_1; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny][nx2] += std_1;
			A[r][c] -= std_1;
		}
	}

	// 2%
	int std_2 = (std * 2) / 100;
	if (std_2 > 0) {
		if (dir == 0) {
			// 왼
			// r-2 c+0
			// r+2 c+0
			int ny1 = r + 2;
			int ny2 = r - 2;
			int nx = c;

			if (ny1 < 0 || ny1 >= N || nx < 0 || nx >= N) score += std_2; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny1][nx] += std_2;
			A[r][c] -= std_2;

			if (ny2 < 0 || ny2 >= N || nx < 0 || nx >= N) score += std_2; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny2][nx] += std_2;
			A[r][c] -= std_2;
		}
		else if (dir == 1) {
			// 아
			// r-0 c-2
			// r-0 c+2
			int ny = r;
			int nx1 = c - 2;
			int nx2 = c + 2;

			if (ny < 0 || ny >= N || nx1 < 0 || nx1 >= N) score += std_2; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx1] += std_2;
			A[r][c] -= std_2;

			if (ny < 0 || ny >= N || nx2 < 0 || nx2 >= N) score += std_2; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny][nx2] += std_2;
			A[r][c] -= std_2;
		}
		else if (dir == 2) {
			nDir = 0;
			// 오
			// r-2 c-0
			// r+2 c-0
			int ny1 = r + 2;
			int ny2 = r - 2;
			int nx = c;

			if (ny1 < 0 || ny1 >= N || nx < 0 || nx >= N) score += std_2; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny1][nx] += std_2;
			A[r][c] -= std_2;

			if (ny2 < 0 || ny2 >= N || nx < 0 || nx >= N) score += std_2; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny2][nx] += std_2;
			A[r][c] -= std_2;
		}
		else if (dir == 3) {
			nDir = 1;
			// 위
			// r+0 c-2
			// r+0 c+2
			int ny = r;
			int nx1 = c - 2;
			int nx2 = c + 2;

			if (ny < 0 || ny >= N || nx1 < 0 || nx1 >= N) score += std_2; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx1] += std_2;
			A[r][c] -= std_2;

			if (ny < 0 || ny >= N || nx2 < 0 || nx2 >= N) score += std_2; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny][nx2] += std_2;
			A[r][c] -= std_2;
		}
	}

	// 5%
	int std_5 = (std * 5) / 100;
	if (std_5 > 0) {
		if (dir == 0) {
			// 왼
			// r+0 c-2
			int ny = r;
			int nx = c - 2;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) score += std_5; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx] += std_5;
			A[r][c] -= std_5;
		}
		else if (dir == 1) {
			// 아
			// r+2 c+0
			int ny = r + 2;
			int nx = c;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) score += std_5; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx] += std_5;
			A[r][c] -= std_5;
		}
		else if (dir == 2) {
			// 오
			// r+0 c+2
			int ny = r;
			int nx = c + 2;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) score += std_5; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx] += std_5;
			A[r][c] -= std_5;
		}
		else if (dir == 3) {
			// 위
			// r-2 c+2
			int ny = r - 2;
			int nx = c;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) score += std_5; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx] += std_5;
			A[r][c] -= std_5;
		}
	}

	// 7%
	int std_7 = (std * 7) / 100;
	if (std_7 > 0) {
		if (dir == 0) {
			// 왼
			// r-1 c+0
			// r+1 c+0
			int ny1 = r + 1;
			int ny2 = r - 1;
			int nx = c;

			if (ny1 < 0 || ny1 >= N || nx < 0 || nx >= N) score += std_7; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny1][nx] += std_7;
			A[r][c] -= std_7;

			if (ny2 < 0 || ny2 >= N || nx < 0 || nx >= N) score += std_7; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny2][nx] += std_7;
			A[r][c] -= std_7;
		}
		else if (dir == 1) {
			// 아
			// r-0 c-1
			// r-0 c+1
			int ny = r;
			int nx1 = c - 1;
			int nx2 = c + 1;

			if (ny < 0 || ny >= N || nx1 < 0 || nx1 >= N) score += std_7; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx1] += std_7;
			A[r][c] -= std_7;

			if (ny < 0 || ny >= N || nx2 < 0 || nx2 >= N) score += std_7; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny][nx2] += std_7;
			A[r][c] -= std_7;
		}
		else if (dir == 2) {
			// 오
			// r-1 c-0
			// r+1 c-0
			int ny1 = r + 1;
			int ny2 = r - 1;
			int nx = c;

			if (ny1 < 0 || ny1 >= N || nx < 0 || nx >= N) score += std_7; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny1][nx] += std_7;
			A[r][c] -= std_7;

			if (ny2 < 0 || ny2 >= N || nx < 0 || nx >= N) score += std_7; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny2][nx] += std_7;
			A[r][c] -= std_7;
		}
		else if (dir == 3) {
			// 위
			// r+0 c-1
			// r+0 c+1
			int ny = r;
			int nx1 = c - 1;
			int nx2 = c + 1;

			if (ny < 0 || ny >= N || nx1 < 0 || nx1 >= N) score += std_7; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx1] += std_7;
			A[r][c] -= std_7;

			if (ny < 0 || ny >= N || nx2 < 0 || nx2 >= N) score += std_7; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny][nx2] += std_7;
			A[r][c] -= std_7;
		}
	}

	// 10%
	int std_10 = (std * 10) / 100;
	if (std_10 > 0) {
		if (dir == 0) {
			// 왼
			// r-1 c-1
			// r+1 c-1
			int ny1 = r + 1;
			int ny2 = r - 1;
			int nx = c - 1;

			if (ny1 < 0 || ny1 >= N || nx < 0 || nx >= N) score += std_10; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny1][nx] += std_10;
			A[r][c] -= std_10;

			if (ny2 < 0 || ny2 >= N || nx < 0 || nx >= N) score += std_10; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny2][nx] += std_10;
			A[r][c] -= std_10;
		}
		else if (dir == 1) {
			// 아
			// r+1 c-1
			// r+1 c+1
			int ny = r + 1;
			int nx1 = c - 1;
			int nx2 = c + 1;

			if (ny < 0 || ny >= N || nx1 < 0 || nx1 >= N) score += std_10; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx1] += std_10;
			A[r][c] -= std_10;

			if (ny < 0 || ny >= N || nx2 < 0 || nx2 >= N) score += std_10; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny][nx2] += std_10;
			A[r][c] -= std_10;
		}
		else if (dir == 2) {
			// 오
			// r-1 c+1
			// r+1 c+1
			int ny1 = r + 1;
			int ny2 = r - 1;
			int nx = c + 1;

			if (ny1 < 0 || ny1 >= N || nx < 0 || nx >= N) score += std_10; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny1][nx] += std_10;
			A[r][c] -= std_10;

			if (ny2 < 0 || ny2 >= N || nx < 0 || nx >= N) score += std_10; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny2][nx] += std_10;
			A[r][c] -= std_10;
		}
		else if (dir == 3) {
			nDir = 1;
			// 위
			// r-1 c-1
			// r-1 c+1
			int ny = r - 1;
			int nx1 = c - 1;
			int nx2 = c + 1;

			if (ny < 0 || ny >= N || nx1 < 0 || nx1 >= N) score += std_10; // 맵을 벗어나면 밖으로 나간 모래양 증가
			else
				A[ny][nx1] += std_10;
			A[r][c] -= std_10;

			if (ny < 0 || ny >= N || nx2 < 0 || nx2 >= N) score += std_10; // 중복이 생길 수 있나(????) <--------------
			else
				A[ny][nx2] += std_10;
			A[r][c] -= std_10;
		}
	}

	// 알파
	int alpha = A[r][c];
	int ay = r + dy[dir];
	int ax = c + dx[dir];

	if (ay < 0 || ay >= N || ax < 0 || ax >= N) score += alpha;
	else {
		A[r][c] = 0;
		A[ay][ax] += alpha;
	}
}

void sol() {
	input();

	// 시작 위치 sy, sx
	int sy = (N - 1) / 2;
	int sx = (N - 1) / 2;
	
	// 시작 방향
	int sDir = 0;

	int cnt = 0;
	for (register int max_len = 1; max_len < N; ++max_len) { // 1 1 2 2 3 3 4 4 5 5 6 6 6(마지막은 한번더)
		for (register int omt = 0; omt < 2; ++omt) { // One More Time => 1 두번 2 두번 3 두번 ...
			// 왼1번 아래1번 오른2번 위2번 왼3번 아래3번
			for (register int keep_dir = 0; keep_dir < max_len; ++keep_dir) {
				int ny = sy + dy[sDir];
				int nx = sx + dx[sDir];

				/* 여기 */
				// test[ny][nx] = ++cnt;
				
				if (A[ny][nx] > 0) { //바람의 방향 끝에 모래가 있다.
					spread_sand(ny, nx, sDir);
				}

				/* 여기 */

				sy = ny;
				sx = nx;
			}
			++sDir;
			if (sDir >= 4) sDir = 0;
		}
		if (max_len == (N - 1)) { // 마지막은 한번더
			for (register int keep_dir = 0; keep_dir < max_len; ++keep_dir) {
				int ny = sy + dy[sDir];
				int nx = sx + dx[sDir];

				/* 여기 */
				// test[ny][nx] = ++cnt;
				if (A[ny][nx] > 0) { //바람의 방향 끝에 모래가 있다.
					spread_sand(ny, nx, sDir);
				}
				/* 여기 */

				sy = ny;
				sx = nx;
			}
		}
	}
	cout << score;
	int de = 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}