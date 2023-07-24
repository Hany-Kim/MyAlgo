#include <iostream>
using namespace std;

// 1   1 => 1
// 2   2 3 4 5 6 7 => 6
// 3   8 9 10 11 12 13 14 15 16 17 18 19 => 12
// 4   20 ... 37 => 18
// 5   38 ... 61 => 24
// 6   62 ... 91 => 30

//       1          2           3
// n 0          1          3          6
// 1(6n+1) -> 7(6n+1) -> 19(6n+1) -> 37 -> ...
long long room;
long long n=1;
int cnt=1;

void input() {
	cin >> room;
}

void sol() {
	input();

	while (room > n) {
		n += 6 * cnt;
		cnt++;
	}
	cout << cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}