#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string N;
int a[11];

void sol() {
	cin >> N;
	for (int i = 0; i < N.length(); i++) {
		a[i] = int(N[i]-'0');
	}
	sort(a, a + N.length(), greater<int>());
	for (int i = 0; i < N.length(); i++) {
		cout << a[i];
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}