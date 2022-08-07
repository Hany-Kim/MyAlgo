#include <iostream>
#include <string>
using namespace std;

int N;
string num;


void input() {
	cin >> N >> num;
}

void sol() {
	input();
	for (int i = 0; i < N; i++) {
		cout << num.front();
		num.pop_back();
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