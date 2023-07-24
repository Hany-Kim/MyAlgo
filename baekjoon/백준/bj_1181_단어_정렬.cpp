#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<string>> v(51,vector<string>());

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		v[temp.size()].push_back(temp);
	}
	for (int i = 1; i < 51; i++) {
		if (v[i].size() > 0) {
			sort(v[i].begin(), v[i].end());
		}
	}
	for (int i = 1; i < 51; i++) {
		if (v[i].size() > 0) {
			for (int j = 0; j < v[i].size(); j++) {
				if ((j>0)&&(v[i][j-1] == v[i][j])) continue;
				cout << v[i][j] << '\n';
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