#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<vector<int>> v(200002, vector<int>());

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		v[y + 100001].push_back(x);
	}
	for (int i = 0; i < 200002; i++) {
		if (v[i].size() > 0)sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < 200002; i++) {
		if (v[i].size() > 0) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[i][j] << ' ' << i - 100001 << '\n';
			}
		}
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