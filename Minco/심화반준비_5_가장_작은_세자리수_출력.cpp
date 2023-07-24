#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <int> v;
vector <int> used;
int path[3];
int flag;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
		used.push_back(0);
	}
}

void func(int lv) {
	if (lv == 3 && flag == 0) {
		if (path[0] != 0) {
			for (int i = 0; i < 3; i++) {
				cout << path[i];
			}
			flag = 1;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] != 0)continue;
		path[lv] = v[i];
		used[i] = 1;
		func(lv + 1);
		used[i] = 0;
	}
}

void sol() {
	input();
	sort(v.begin(), v.end());
	func(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}