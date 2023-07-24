#include <iostream>
using namespace std;

int N;
bool han_num[1001];
int cnt;

void input() {
	cin >> N;
}

int one(int n) {
	int res = 0;
	res = n % 10;
	
	return res;
}

int ten_to_one(int n) {
	int res = 0;
	res = (n % 100) / 10;

	return res;
}

int hun_to_one(int n) {
	int res = 0;
	res = (n / 100);

	return res;
}

void find_han_num() {
	for (int i = 1; i <= N; i++) {
		if (i < 10) {
			han_num[i] = true;
		}
		else if (i < 100) {
			han_num[i] = true;
		}
		else if (i < 1000) {
			int a = hun_to_one(i) - ten_to_one(i);
			int b = ten_to_one(i) - one(i);
			if (a == b) {
				han_num[i] = true;
			}
		}
	}
}

void sol() {
	input();
	find_han_num();
	for (int i = 1; i < 1000; i++) {
		if (han_num[i] == true)cnt++;
	}
	cout << cnt;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}