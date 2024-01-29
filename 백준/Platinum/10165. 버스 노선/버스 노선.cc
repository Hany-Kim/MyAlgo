#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> bus_line;
vector<vector<int>> ans;

bool cmp(vector<int>& l, vector<int>& r) {
	if (l[0] == r[0]) return l[1] > r[1];
	return l[0] < r[0];
}
bool cmpnum(vector<int>& l, vector<int>& r) { return l[2] < r[2]; }

void sol() {
	cin >> N >> M;
	bus_line = vector<vector<int>>(M, vector<int>(3));
	int circle_max = 0;
	for (int i = 0; i < M; i++) {
		cin >> bus_line[i][0] >> bus_line[i][1];

		if (bus_line[i][0] > bus_line[i][1]) {
			circle_max = max(circle_max, bus_line[i][1]);
			bus_line[i][1] += N;
		}

		bus_line[i][2] = i + 1;
	}

	sort(bus_line.begin(), bus_line.end(), cmp);

	for (int j = 0; j < M; ++j) {
		if (bus_line[j][1] <= circle_max) continue;

		if (ans.empty() || (ans.size() && ans.back()[1] < bus_line[j][1]))
			ans.push_back(bus_line[j]);
	}

	sort(ans.begin(), ans.end(), cmpnum);
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][2] << ' ';
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}