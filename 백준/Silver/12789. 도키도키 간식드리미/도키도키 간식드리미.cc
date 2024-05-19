#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define FOR(i,s,e) for(register int i=(s); i<(e); ++i)

int N;
queue<int> q;
stack<int> s;
int lineCnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> N;
	FOR(i, 0, N) {
		int num = 0;
		cin >> num;
		q.push(num);
	}

	while (!q.empty() || !s.empty()) {
		if ((!q.empty()) && (q.front() - 1 == lineCnt)) {
			++lineCnt;
			q.pop();
		}
		else if ((!s.empty()) && (s.top() - 1 == lineCnt)) {
			++lineCnt;
			s.pop();
		}
		else if (q.empty() && (s.top() - 1 > lineCnt)) {
			cout << "Sad";
			break;
		}
		else {
			s.push(q.front());
			q.pop();
		}
	}
	if (q.empty() && s.empty()) cout << "Nice";

	return 0;
}