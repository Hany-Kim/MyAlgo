#include <iostream>
#include <string>
using namespace std;

string call;
string number;
int time_taken;

void input() {
	cin >> call;
}

void transform() {
	for (int i = 0; i < call.length(); i++) {
		if (call[i] >= 'A' && call[i] <= 'C') {
			time_taken += 3;
		}
		else if (call[i] >= 'D' && call[i] <= 'F') {
			time_taken += 4;
		}
		else if (call[i] >= 'G' && call[i] <= 'I') {
			time_taken += 5;
		}
		else if (call[i] >= 'J' && call[i] <= 'L') {
			time_taken += 6;
		}
		else if (call[i] >= 'M' && call[i] <= 'O') {
			time_taken += 7;
		}
		else if (call[i] >= 'P' && call[i] <= 'S') {
			time_taken += 8;
		}
		else if (call[i] >= 'T' && call[i] <= 'V') {
			time_taken += 9;
		}
		else if (call[i] >= 'W' && call[i] <= 'Z') {
			time_taken += 10;
		}
	}
}

void sol() {
	input();
	transform();
	cout << time_taken;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}