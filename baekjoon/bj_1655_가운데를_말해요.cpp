#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> down_q; // 오름차순
priority_queue<long long> up_q; // 내림차순
int N;

void sol() {
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt++;
		int shout = 0;
		cin >> shout;
		if (cnt % 2 == 1) {
			up_q.push(shout);
		}
		else if (cnt % 2 == 0) {
			down_q.push(shout);
		}

		if (down_q.empty()) {
			cout << up_q.top() << "\n";
			continue;
		}

		if (up_q.top() > down_q.top()) {
			long long uptemp = up_q.top();
			long long downtemp = down_q.top();

			up_q.pop();
			down_q.pop();

			up_q.push(downtemp);
			down_q.push(uptemp);
		}

		
		cout << up_q.top() << "\n";
		
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