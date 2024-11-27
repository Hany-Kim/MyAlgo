#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
unordered_map<string, int> um;
vector<pair<string, int>> v;

bool mstrcmp(string s1, string s2) {
	int len = min(s1.size(), s2.size());

	for (int i = 0; i < len; ++i) {
		if (i >= s1.size()) return false;
		if (i >= s2.size()) return true;

		if (s1[i] > s2[i]) return false;
		else if (s1[i] < s2[i]) return true;
	}

	return false;
}

bool cmp(pair<string, int> left, pair<string, int> right) {
	if (left.second > right.second) return true;
	if (left.second < right.second) return false;

	if (left.first.size() > right.first.size()) return true;
	if (left.first.size() < right.first.size()) return false;

	if (mstrcmp(left.first, right.first)) return true;

	return false;
}

void solution() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string str = "";
		cin >> str;

		if (str.size() < M) continue;

		unordered_map<string, int>::iterator itr = um.find(str);
		int idx = -1;
		if (itr != um.end()) {
			idx = um[str];
			v[idx].second += 1;
		}
		else {
			idx = v.size();
			um[str] = idx;
			v.push_back(make_pair(str, 1));
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}