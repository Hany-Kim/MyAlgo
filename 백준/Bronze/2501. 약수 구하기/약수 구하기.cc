#include <iostream>
#include <set>
using namespace std;

int N, K;
set<int> s;

void sol() {
	cin >> N >> K;
	for (int i = 1; i <= (N / 2) + 1; ++i) {
		if (N % i == 0) {
			s.insert(i);
			s.insert((N / i));
		}
	}

	int cnt = 1;
	int ans = 0;
	for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
		if (cnt == K) {
			ans = *itr;
			break;
		}
		cnt++;
	}
	cout << ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}