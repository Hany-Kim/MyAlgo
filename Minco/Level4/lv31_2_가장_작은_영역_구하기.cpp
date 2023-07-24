#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int n;
vector <int> v_sum;
int min_num = 9999;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t = 0;
		cin >> t;
		v.push_back(t);
	}
}

void sw(int idx) {
	int sum = 0;
	for (int i = idx; i < idx + 4; i++) {
		sum += v[i];
	}
	v_sum.push_back(sum);
}

void sol() {
	input();
	for (int i = 0; i <= n - 4; i++) {
		sw(i);
	}
	for (int i = 0; i < 5; i++) {
		if (min_num > v_sum[i]) {
			min_num = v_sum[i];
		}
	}
	cout << min_num;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}