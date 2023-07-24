#include <iostream>
using namespace std;

int N;

void input() {
	cin >> N;
}

void sol() {
	input();
	int i = 1;
	while (N > i) {
		N -= i;
		i++;
	}
	if (i % 2 == 1)cout << i + 1 - N << '/' << N << endl;
	else cout << N << '/' << i + 1 - N << endl;

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}