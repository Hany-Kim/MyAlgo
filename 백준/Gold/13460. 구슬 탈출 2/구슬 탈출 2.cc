#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[11][11];
struct Point {
	int y;
	int x;
};
Point R;
Point B;
struct Step {
	int Ry, Rx;
	int By, Bx;
	int cnt;
};

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'R') R = { y, x };
			if (map[y][x] == 'B') B = { y, x };
		}
	}
}

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void move(Point colorR, Point colorB) {
	queue<Step> q;
	int used[11][11][11][11] = {0,};
	q.push({ colorR.y, colorR.x, colorB.y, colorB.x, 0 });
	used[colorR.y][colorR.x][colorR.y][colorR.x] = 1;

	while (!q.empty()) {
		Step now = q.front();
		q.pop();

		if (now.cnt >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nry = now.Ry;
			int nrx = now.Rx;
			int nby = now.By;
			int nbx = now.Bx;
			int rc = 0;
			int bc = 0;
			int ncnt = now.cnt + 1;
		
			while (map[nry + dr[i]][nrx + dc[i]] != '#' && map[nry][nrx] != 'O') {
				nry += dr[i];
				nrx += dc[i];
				rc += 1;
			}
			while (map[nby + dr[i]][nbx + dc[i]] != '#' && map[nby][nbx] != 'O') {
				nby += dr[i];
				nbx += dc[i];
				bc += 1;
			}

			if (map[nby][nbx] == 'O') continue;
			if (map[nry][nrx] == 'O') {
				cout << ncnt;
				return;
			}
			if (nry == nby && nrx == nbx) {
				if (rc > bc) {
					nry -= dr[i];
					nrx -= dc[i];
				}
				else {
					nby -= dr[i];
					nbx -= dc[i];
				}
			}

			if (used[nry][nrx][nby][nbx]) continue;
			used[nry][nrx][nby][nbx] = 1;
			q.push({ nry, nrx, nby, nbx, ncnt });
		}
	}
	cout << -1;
}

void sol() {
	input();
	move(R,B);
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}