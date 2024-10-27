#include <iostream>
#include <string>
using namespace std;

string N;
int B;
int ans;

void sol() {
	cin >> N >> B;

	int times = 1;
	for (int i = N.size() - 1; i >= 0; i--) {
		int num = 0;
		if (N[i] >= 'A' && N[i] <= 'Z') {
			num = int(N[i] - 'A') + 10;
		}
		else {
			num = int(N[i] - '0');
		}

		ans += (times * num);
		times *= B;
	}

	cout << ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}