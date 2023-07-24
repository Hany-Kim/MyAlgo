#include <iostream>
#include <queue>
using namespace std;

int Q;
priority_queue<int, vector<int>, greater<int>> findIt;
priority_queue<int> uglyNum;

void sol() {
	cin >> Q;
	int maxNum = 0;
	for (int i = 0; i < Q; i++) {
		int K;
		cin >> K;
		findIt.push(K);
		if (maxNum < K)maxNum = K;
	}

	// ugly num ¸¸µé±â
	int now = 1;
	int old = -1;
	uglyNum.push(1);
	int cnt = 0;
	while (1) {
		now = uglyNum.top();
		uglyNum.pop();
		if (now == old)continue;
		old = now;
		cnt++;

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