#include <iostream>
#include <string>
using namespace std;

int T;
string N;
int x, y;
int xy[2];
string min_num, ans;
int between_flag, min_flag;
string combi;
int flag = 1;

void init() {
	N = "";
	x = 0, y = 0;
	min_num = "";
	ans = "";
	between_flag = 0;
	min_flag = 0;
	flag = 1;
	combi = "";
}

void dfs(int lv, int s) {
	if (lv >= N.length()) {
		if (combi <= N) {
			if (ans < combi) {
				ans = combi;
				flag = 0;
			}
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		combi += char(xy[i]+'0');
		dfs(lv + 1, xy[i]);
		combi.pop_back();
	}
}

void sol() {
	cin >> N >> x >> y;
	xy[0] = x;
	xy[1] = y;
	
	for (int i = 0; i < N.length(); i++) {
		min_num += char(x + '0');
	}

	if (min_num <= N) { // 같은 자리수의 최솟값보다 N이 큼
		dfs(0, x);
		dfs(0, y);
		if (flag)cout << -1 << '\n';
		else cout << ans << '\n';
	}
	else { // 한자리 빼야함
		if (N.length() - 1 < 1) {
			cout << -1 << '\n';
		}
		else {
			for (int i = 0; i < N.length() - 1; i++) {
				ans += char(y + '0');
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " ";
		init();
		sol();
	}

	return 0;
}