#include <iostream>
#include <vector>
using namespace std;

// 100x + 10y + z => 101x + 11y + 2z
// 100 + 90 + 8 => 101 + 99 + 16

int N, M;
int sum;

void input() {
	cin >> N;
}

void func(int num) {
	sum = num;
	while (num) {
		sum += num % 10;
		num = num / 10;
	}
}

void sol() {
	input();
	for (int i = 0; i <= N; i++) {
		func(i);
		if (N == sum) {
			M = i;
			break;
		}
	}
	cout << M;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}