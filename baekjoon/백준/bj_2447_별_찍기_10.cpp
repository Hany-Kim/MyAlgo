#include <iostream>
using namespace std;

int N;

void input() {
	cin >> N;
}

void func(int i, int j, int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
		cout << ' ';
	}
	else {
		if (num / 3 == 0) {
			cout << '*';
		}
		else func(i, j, num / 3);
	}
	
}

void sol() {
	input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			func(i, j, N);
		}
		cout << '\n';
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}