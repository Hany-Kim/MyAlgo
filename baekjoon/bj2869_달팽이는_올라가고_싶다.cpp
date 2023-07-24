#include <iostream>
using namespace std;

int A, B, V;
int day;
int n;

void sol() {
	cin >> A >> B >> V;

	cout << (int)(V - B - 1) / (A - B) + 1;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}