#include <iostream>
#include<queue>

using namespace std;

int N, M;
int queueStack[100000];
long long arr1[100000];
long long arr2[100000];
queue<long long> q;

void solution() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> queueStack[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> arr1[i];
	}

	cin >> M;

	for (int i = 0; i < M; ++i) {
		cin >> arr2[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if(queueStack[i] == 0) q.push(arr1[i]);
	}

	for (int i = 0; i < M; ++i) {
		long long curNum = arr2[i];
		q.push(curNum);

		cout << q.front() << " ";
		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}