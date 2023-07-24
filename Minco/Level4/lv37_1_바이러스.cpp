#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> v;

int dy[4] = {0, 1, 0, -1};
int dx[4] = { 1, 0, -1, 0 };

void diffusion(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;

		if (v[ny][nx] < v[y][x] && v[ny][nx]==0) {
			v[ny][nx] = v[y][x] + 1;

		}
	}

}

void sol() {
	cin >> N;
	v = vector<vector<int>>(N, vector<int> (N));

	for (int i = 0; i < 2; i++) {
		int y, x;
		cin >> y >> x;
		v[y][x] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if(v[y][x] == i)
					diffusion(y, x);
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << v[y][x];
		}
		cout << '\n';
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}