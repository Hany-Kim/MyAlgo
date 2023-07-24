#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> v;

void sol() {
	cin >> N;
	v = vector<vector <int>>(200002, vector<int>());
	for (int i = 0; i < N; i++) {
		int ix = 0, iy = 0;
		cin >> ix >> iy;
		v[ix+100001].push_back(iy);
	}
	for (int i = 0; i <= 200001; i++) {
		if (v[i].size() > 1) sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i <= 200001; i++) {
		if (v[i].size() >= 1) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << i-100001 << ' ' << v[i][j] << '\n';
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