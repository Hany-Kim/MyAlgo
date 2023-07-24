#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> down_score;
priority_queue<long long> up_score;
int n;

void sol() {
	cin >> n;
	up_score.push(500);
	for (int i = 0; i < n; i++) {
		long long in1 = 0, in2 = 0;
		cin >> in1 >> in2;
		down_score.push(in1);
		up_score.push(in2);

		if (up_score.top() > down_score.top()) {
			long long uptemp = up_score.top();
			long long downtemp = down_score.top();

			up_score.pop();
			down_score.pop();

			up_score.push(downtemp);
			down_score.push(uptemp);
		}
		cout << up_score.top() << "\n";
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