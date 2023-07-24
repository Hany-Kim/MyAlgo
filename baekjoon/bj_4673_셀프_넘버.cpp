#include <iostream>
using namespace std;

bool not_selfNum[10001];

void not_self_num() {
	for (int i = 1; i <= 10000; i++) {
		int sum = 0;
		// i가 일의 자리
		if (i < 10) {
			sum = i + i;
			if (sum <= 10000) {
				not_selfNum[sum] = true;
			}
		}
		// i가 십의 자리
		else if (i >= 10 && i < 100) {
			sum = i + (i / 10) + (i % 10);
			if (sum <= 10000) {
				not_selfNum[sum] = true;
			}
		}
		// i가 백의 자리
		else if (i >= 100 && i < 1000) {
			int hundred = i / 100;
			int ten = (i % 100) / 10;
			int one = i % 10;
			sum = i + hundred + ten + one;
			if (sum <= 10000) {
				not_selfNum[sum] = true;
			}
		}
		// i가 천의 자리
		else if (i >= 1000 && i < 10000) {
			int thou = i / 1000;
			int hundred = (i % 1000) / 100;
			int ten = (i % 100) / 10;
			int one = i % 10;
			sum = i + thou + hundred + ten + one;
			if (sum <= 10000) {
				not_selfNum[sum] = true;
			}
		}
		// i가 만의 자리
		else if (i == 10000) {
			int milli = i / 10000;
			int thou = (i % 10000) / 1000;
			int hundred = (i % 1000) / 100;
			int ten = (i % 100) / 10;
			int one = i % 10;
			sum = i + milli + thou + hundred + ten + one;
			if (sum <= 10000) {
				not_selfNum[sum] = true;
			}
		}
	}
}

void find_self_num() {
	for (int i = 1; i < 10001; i++) {
		if (not_selfNum[i] == false) {
			cout << i << '\n';
		}
	}
}

void sol() {
	not_self_num();
	find_self_num();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	sol();

	return 0;
}