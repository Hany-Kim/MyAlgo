#include <iostream>
#include <cmath>
using namespace std;

int N_digit;
// 소수 : 2,3,5,7
int sosu_arr[4] = { 2,3,5,7 };
int res;

bool sosu(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

void add_num(int n, int digit) {
	if (digit == N_digit) {
		cout << n << '\n';
		return;
	}

	for (int i = 1; i < 10; i++) {
		//if (i % 2 == 0)continue;
		// 소수 판별
		if (sosu((n * 10) + i)) {
			// 소수
			add_num((n * 10) + i,digit+1);
		}
	}

	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N_digit;

	for (int i = 0; i < 4; i++) {
		add_num(sosu_arr[i],1);
	}

	return 0;
}