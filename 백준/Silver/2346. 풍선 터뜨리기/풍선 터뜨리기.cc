#include <iostream>
#include <deque>
using namespace std;

int N;
deque<pair<int,int>> dq;

void sol() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num = 0;
		cin >> num;

		dq.push_back(make_pair(i + 1, num));
	}

	while (!dq.empty()) {
		pair<int,int> now = dq.front();
		cout << now.first << " ";
		dq.pop_front();

		if (dq.size() == 0) continue;
		if (now.second > 0) {
			for (int i = 0; i < now.second - 1; ++i) {
				pair<int,int> tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
		}
		else {
			int end = now.second * -1;
			for (int i = 0; i < end; ++i) {
				pair<int, int> tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}