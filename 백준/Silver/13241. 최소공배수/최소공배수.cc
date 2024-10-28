#include <iostream>
using namespace std;

void sol() {
	long long int n1 = 0, n2 = 0;
	cin >> n1 >> n2;

	long long int times = 1;
	while (true) {
		long long int num = n1 * times;

		if (num % n2 == 0) {
			cout << num;
			break;
		}
		times++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}