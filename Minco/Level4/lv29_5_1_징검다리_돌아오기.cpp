#include <iostream>

using namespace std;

int n;
int m[9] = { 3,1,2,1,3,2,1,2,1 };
int offset;

void input() {
	cin >> n;
}

void func(int n) {
	offset += n;
	if (offset >= 10) {
		cout << "도착 ";
		offset -= n;
		return;
	}
	cout << m[offset - 1] << " ";
	func(m[offset - 1]);
	cout << m[offset-1] << " ";
	offset -= n;
}

void solution() {
	input();
	cout << "시작 ";
	func(n);
	cout << "시작 ";
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;

}