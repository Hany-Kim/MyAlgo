#include <iostream>
using namespace std;

int f[50];
int n;
int cd1_cnt, cd2_cnt;	

int fib(int n) {
	if ((n == 1) || (n == 2)) {
		cd1_cnt++;
		return 1;
	}
	else return (fib(n - 1) + fib(n - 2));
}

int fibo(int n) {
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		cd2_cnt++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n-1];
}

void sol() {
	cin >> n;
	fib(n);
	fibo(n);
	cout << cd1_cnt << " " << cd2_cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}