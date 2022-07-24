#include <iostream>
using namespace std;

int arr[5];
int cnt;

void input() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
}

void func(int lv, int sum) {
	if (lv == 5) {
		if ((sum >= 10) && (sum <= 20)) {
			cnt++;
		}
		return;
	}
	func(lv + 1, sum + arr[lv]);
	func(lv + 1, sum + 0);
}

void sol() {
	input();
	func(0,0);
	cout<<cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}