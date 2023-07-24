#include <iostream>
using namespace std;

long long A, B, C;
long long ans;

void sol() {
	cin >> A >> B >> C;
	ans = A + B + C;
	cout << ans;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}