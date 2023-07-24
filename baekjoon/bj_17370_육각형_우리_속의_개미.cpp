#include <iostream>

using namespace std;

int N;
bool visited[101][101];

int answer = 0;

//dir =>  0:↑, 1:↗, 2:↘, 3:↓, 4:↙, 5:↖
int direct[6][2][2] = {
	{{-1,-1},{-1,1}},	// ↖↗
	{{-1,0},{1,1}},		// ↑↘
	{{-1,1},{1,0}},		// ↗↓
	{{1,-1},{1,1}},		// ↙↘
	{{1,0},{-1,-1}},	// ↓↖
	{{1,-1},{-1,0}}		// ↙↑
};
int lasts[6][2] = { {4, 2}, {3, 5}, {0, 5}, {1, 4}, {3, 0}, {2, 1} };


void DFS(int r, int c, int count, int last) {

	for (int i = 0; i < 2; i++) {
		int dr = direct[last][i][0];
		int dc = direct[last][i][1];
		int now = lasts[last][i];

		int nextR = r + dr;
		int nextC = c + dc;

		if (count + 1 == N) {
			if (visited[nextR][nextC]) answer++;
			continue;
		}
		if (!visited[nextR][nextC]) {
			visited[nextR][nextC] = 1;
			DFS(nextR, nextC, count + 1, now);
			visited[nextR][nextC] = 0;
		}

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	//0 번째 이동 50,50 -> 49,50
	visited[50][50] = 1;
	visited[49][50] = 1;
	DFS(49, 50, 0, 0);

	cout << answer << endl;
	return 0;
}