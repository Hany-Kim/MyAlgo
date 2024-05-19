#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

#define FOR(i,s,e) for(register int i=(s); i<(e); ++i)

int N, K;
deque<int> dq;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	FOR(i, 1, (N + 1)) {
		dq.push_back(i);
	}
	while (!dq.empty()) {
		int tmp = 0;
		FOR(i, 0, (K - 1)) {
			tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
		}
		
		v.push_back(dq.front());
		dq.pop_front();
	}

	cout << "<";
	FOR(i, 0, v.size()) {
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << ">";

	return 0;
}