#include <iostream>
using namespace std;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	double a, b;
	cin >> a >> b;

	double result;
	result = (a / b);
	cout.setf(ios::fixed);
	cout.precision(9);
	cout << result;
	return 0;
}