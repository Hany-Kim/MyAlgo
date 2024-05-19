#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,s,e) for(register int i=(s); i<(e); ++i)
#define PII pair<int, int>

int N, M;
int basket[101];

void init() {
	FOR(i, 1, N + 1) {
		basket[i] = i;
	}
}

void myReverse(PII idx) {
	reverse(basket + idx.first, basket + idx.second + 1);
}

int main() {
	cin >> N >> M;
	init();

	FOR(i, 0, M) {
		int s = 0, e = 0;
		cin >> s >> e;
		
		PII idx;
		idx = make_pair(s, e);

		myReverse(idx);
	}

	FOR(i, 1, N + 1) {
		cout << basket[i] << ' ';
	}

	return 0;
}