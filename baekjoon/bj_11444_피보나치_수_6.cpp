#include <iostream>
#include <map>
#include <utility>
using namespace std;

#define MOD 1000000007
#define LL long long

long long n;
map<LL, LL> m;
/*
0 1 2 3 4 5 6 7  8  9  10 11 12  13  14  15  16  17   18 19 20 21 22 23 24 25
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597
*/

LL fibo(LL x) {
	if (m[x]) return m[x];

	LL result = 0;
	if (x % 2 == 0) result = (fibo(x / 2) * (fibo(x / 2 + 1) + fibo(x / 2 - 1))) % MOD;
	else result = ((fibo((x + 1) / 2) * fibo((x + 1) / 2)) % MOD) + ((fibo((x - 1) / 2) * fibo((x - 1) / 2)) % MOD);

	return m[x] = result % MOD;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	m[0] = 0;
	m[1] = 1;
	m[2] = 1;
	cout << fibo(n);

	return 0;
}