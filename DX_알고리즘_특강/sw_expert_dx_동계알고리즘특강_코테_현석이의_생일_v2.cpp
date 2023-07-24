#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int T;
string N, x, y;
string xy[2];
string path;
int len;

string ans;
int flag = 1;

void init() {
	N = "", x = "", y = "";
	path = "";
	len = 0;
	ans = "";
	flag = 1;
}

void dfs(int lv, string s) {
	if (lv >= len) {
		if (path.find(xy[0], 0) != -1 && path.find(xy[1], 0) != -1) {
			//cout << path << "\n";
			if (path <= N) {
				if (path > ans) ans = path;
			}
			flag = 0;
		}

		return;
	}

	for (int i = 0; i < 2; i++) {
		path += xy[i];
		dfs(lv + 1, xy[i]);
		path.pop_back();
	}
}

void sol() {
	cin >> N >> x >> y;
	xy[0] = x;
	xy[1] = y;
	len = N.length();

	for (int i = 0; i < 2; i++) {
		path += xy[i];
		dfs(1, xy[i]);
		path = "";
	}
	if (flag) printf("%d\n", -1);
	else cout<<ans<<"\n";
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("#%d ", i);
		init();
		sol();
	}

	return 0;
}