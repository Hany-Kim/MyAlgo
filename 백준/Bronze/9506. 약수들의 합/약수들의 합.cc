#include <iostream>
#include <set>
using namespace std;

int N;
set<int> s;

void sol() {
	while (true) {
		cin >> N;
		if (N == -1) break;
		for (int i = 1; i <= (N / 2) + 1; ++i) {
			if (N % i == 0) {
				s.insert(i);
				s.insert((N / i));
			}
		}

		int sum = 0;
		for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
			if (*itr == N) continue;
			sum += *itr;
		}

		if (sum == N) {
			cout << N << " = ";
			for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
				if (*itr == N) continue;
				if(itr != s.begin()) cout << " + ";
				cout << *itr;
			}
			cout << "\n";
		}
		else {
			cout << N << " is NOT perfect.\n";
		}
		s.clear();
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}