#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define Dummy 213456789

int TC;
int N, M;
vector<vector<int>> d;
int min_dist = Dummy;
vector<int> v;

void init() {
	d.clear();
	min_dist = Dummy;
}
void input() {
	cin >> N >> M;

	d = vector<vector<int>>(N + 1, vector<int>(N + 1, Dummy));

	for (register int i = 1; i <= N; ++i) {
		d[i][i] = 0;
	}

	for (register int i = 0; i < M; ++i) {
		int from = 0, to = 0, dist = 0;
		cin >> from >> to >> dist;

		if (from == to) {
			min_dist = min(min_dist, dist);
		}

		else d[from][to] = dist;
	}
}
void ex_input() {
	cin >> N >> M;
	N = 400;
	M = 400;

	d = vector<vector<int>>(N + 1, vector<int>(N + 1, Dummy));

	/*for (int from = 1; from <= 400; ++from) {
		for (int to = 1; to <= 400; ++to) {
			if (from == to) d[from][to] = 0;
			else {
				int dist = 10000;
				d[from][to] = dist;
			}
		}
	}*/
	//graph[399].push_back({ 399, 1999 });

	
	for (int i = 0; i < 399; ++i) {
		for (int from = 1 + i; from < i + 2; ++from) {
			for (int to = from + 1; to < from + 2; ++to) {
				int a = 0, b = 0, c = 0;
				cin >> a >> b >> c;
				int dist = 1;
				d[from][to] = dist;
			}
		}
	}
	d[400][1] = 1;

	// O ( N )
	
}
void floyd() {
	for (register int B = 1; B <= N; ++B) {
		for (register int A = 1; A <= N; ++A) {
			for (register int C = 1; C <= N; ++C) {
				if (d[A][C] > d[A][B] + d[B][C]) {
					d[A][C] = d[A][B] + d[B][C];
				}
			}
		}
	}
}

void come_back() {
	v = vector<int>(N + 1, Dummy);

	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= N; ++x) {
			if (y == x) continue;
			v[y] = min(v[y], d[y][x] + d[x][y]);
		}
	}

	for (register int i = 1; i <= N; ++i) {
		min_dist = min(min_dist, v[i]);
	}
}

void sol() {
	floyd();
	come_back();
	if (min_dist == Dummy) cout << -1;
	else cout << min_dist;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> TC;
	for (register int testcase = 1; testcase <= TC; ++testcase) {
		cout << "#" << testcase << " ";
		init();
		input();
		//ex_input(); // O (M)
		sol(); // O (N * M * log N)
		cout << "\n";
	}
	return 0;
}