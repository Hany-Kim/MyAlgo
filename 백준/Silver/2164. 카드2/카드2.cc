#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

#define FOR(i,s,e) for(register int i=(s); i<(e); ++i)

int N;
queue<int> q;

void throwCard() {
	q.pop();
}
void putBottom() {
	int tmp = q.front();
	q.pop();
	q.push(tmp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> N;
	FOR(i, 1, (N + 1)) {
		q.push(i);
	}

	while (q.size() > 1) {
		throwCard();
		putBottom();
	}
	cout << q.front();

	return 0;
}