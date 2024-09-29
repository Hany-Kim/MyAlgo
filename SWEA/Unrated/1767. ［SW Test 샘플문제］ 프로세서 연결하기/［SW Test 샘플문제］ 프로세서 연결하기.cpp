#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

#define N_MAX (12 + 1)

struct NODE
{
	int y, x;
	bool isConnect;
};

int TC, N;
int map[N_MAX][N_MAX];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
NODE coreList[N_MAX];
int coreCnt;
int checkCnt;
int path[N_MAX];
int used[N_MAX];
pair<int, int> ans;

void dfs(int usedCoreCnt, int coreNum, int curMap[N_MAX][N_MAX], int lineCnt) {
	if (usedCoreCnt > 0) {
		if (ans.first < usedCoreCnt) {
			ans.first = max(ans.first, usedCoreCnt);
			ans.second = lineCnt;
		}
		else if (ans.first == usedCoreCnt) {
			if (ans.second > lineCnt) {
				ans.first = max(ans.first, usedCoreCnt);
				ans.second = min(ans.second, lineCnt);
			}
		}
	}

	for (int i = coreNum; i < coreCnt; ++i) {
		if (coreList[i].isConnect) continue;
		if (used[i]) continue;

		for (int dir = 0; dir < 4; ++dir) {
			int tmp[N_MAX][N_MAX] = { 0, };
			memcpy(tmp, curMap, sizeof(tmp));
			bool isConnect = false;
			int ny = coreList[i].y;
			int nx = coreList[i].x;
			int lines = 0;

			while (1) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];

				if (ny<1 || ny>N || nx<1 || nx>N) {
					isConnect = true;
					break;
				}
				if (tmp[ny][nx] != 0) break;

				tmp[ny][nx] = 2;
				lines += 1;
			}

			if (!isConnect) continue;

			used[i] = 1;
			coreList[i].isConnect = true;

			dfs(usedCoreCnt + 1, i + 1, tmp, lines + lineCnt);

			used[i] = 0;
			coreList[i].isConnect = false;
		}
	}
}

void sol() {
	dfs(0, 0, map, 0);
	cout << ans.second;
}

void init() {
	coreCnt = 0;
	checkCnt = 0;
	ans.first = 0;
	ans.second = INT_MAX;
	memset(used, 0, sizeof(used));
	memset(map, 0, sizeof(map));
}
bool checkConnect(int y, int x) {
	if (y == 1 || x == 1 || y == N || x == N) return true;
	return false;
}
void in() {
	cin >> N;
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				NODE now;
				now.y = y;
				now.x = x;
				now.isConnect = checkConnect(y, x);
				if (!now.isConnect) ++checkCnt;
				coreList[coreCnt++] = now;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> TC;
	for (int test_case = 1; test_case <= TC; ++test_case) {
		cout << "#" << test_case << " ";
		init();
		in();
		sol();
		cout << "\n";
	}

	return 0;
}