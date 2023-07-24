#include <iostream>
#include <string>
using namespace std;

int num;
string input_num;
int sum;

void input() {
	cin >> num >> input_num;
}

void sol() {
	input();
	for (int i = 0; i < num; i++) {
		//sum += input_num % 10;
		//input_num = input_num / 10;
		char ch = input_num[i];
		sum += int(ch - '0');
	}
	cout << sum;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}