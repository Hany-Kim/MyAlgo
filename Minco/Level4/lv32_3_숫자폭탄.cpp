#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int flag;
vector <int> bomb;
vector <int> ans;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t = 0;
		cin >> t;
		bomb.push_back(t);
	}
}

void search() {
	for (int i = 0; i < N - 2; i++) {
		if (bomb[i] == bomb[i + 1] && bomb[i + 1] == bomb[i + 2]) {
			i += 2;
		}
		else {
			ans.push_back(bomb[i]);
			if (i == N - 3) {
				ans.push_back(bomb[N - 2]);
				ans.push_back(bomb[N - 1]);
			}
		}
	}
}

void sol() {
	input();
	search();
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
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