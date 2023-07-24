#include <iostream>
using namespace std;

int park[9] = { 1,2,3,3,5,1,0,1,3 };
int bus;
int min_sum = 9999;

void input() {
	cin >> bus;
}

void sliding_window() {
	for (int i = 0; i < 9 - bus + 1; i++) {
		int sum = 0;
		for (int j = i; j < i + bus; j++) {
			sum += park[j];
		}
		if (sum < min_sum) {
			min_sum = sum;
		}
	}
}

void sol() {
	input();
	sliding_window();
	cout << min_sum;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}