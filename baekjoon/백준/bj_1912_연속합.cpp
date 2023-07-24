#include <iostream>
using namespace std;

int n;
long long max_num = -9999;

void sol() {
	cin >> n;
	int sum = 0;
	int save = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		sum += temp;
		if ((save + temp) > sum) {
			sum = save + temp;
		}

		if (sum > max_num) max_num = sum;
		else { // sum <= max_num
			save = sum;
			sum = 0;
		}
	}
	cout << max_num;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}