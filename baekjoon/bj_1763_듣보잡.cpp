#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int N, M;
map<string, pair<int, int>> ddbo;
int cnt;
vector<string> nameArr;

void sol() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		ddbo.insert(make_pair(temp, make_pair(1, 0)));
	}
	for (int i = 0; i < M; i++) {
		string temp = "";
		cin >> temp;
		if (ddbo[temp].first) {
			ddbo[temp].second = 1;
		}
		else ddbo.insert(make_pair(temp, make_pair(0, 1)));
	}
	for (const auto& item : ddbo) {
		if (item.second.first == 1 && item.second.second == 1) {
			cnt++;
			nameArr.push_back(item.first);
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < nameArr.size(); i++) {
		cout << nameArr[i] << '\n';
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