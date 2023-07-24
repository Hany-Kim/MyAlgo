#include <iostream>
using namespace std;

int R;

void sol() {
	double pi = 3.1415926535897932;

	cin >> R;

	double round = R * R * pi;
	double taxi = R * R * 2;
	cout << fixed;
	cout.precision(6);
	cout << round << "\n" << taxi;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}