#include <iostream>
using namespace std;

int total_price;
int num;
int list_p_n[4][2];
int sum;

void input() {
	cin >> total_price >> num;
	for (int i = 0; i < num; i++) {
		cin >> list_p_n[i][0] >> list_p_n[i][1];
	}
}

void cal() {
	for (int i = 0; i < num; i++) {
		int mid_cal = 0;
		mid_cal = list_p_n[i][0] * list_p_n[i][1];
		sum += mid_cal;
	}
}

void check() {
	if (total_price == sum) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

void sol() {
	input();
	cal();
	check();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}