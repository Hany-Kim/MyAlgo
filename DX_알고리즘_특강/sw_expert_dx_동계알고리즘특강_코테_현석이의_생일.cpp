#include <stdio.h>
#include<vector>
#include<string>
using namespace std;

int T, N, x, y;
int len;
int xy[2];
vector<int> v;
int ans;
int flag = 1;

void init() {
	N = 0, x = 0, y = 0;
	len = 0;
	ans = 0;
	flag = 1;
}

void dfs(int lv, int s) {
	if (lv >= len) {
		string strnum = "";
		for (int i = 0; i < len; i++) {
			//printf("%d ", v[i]);
			strnum += char('0' + v[i]);
		}
		//printf("\n");
		int num = stoi(strnum);
		if (num <= N) {
			if (ans < num) {
				ans = num;
				flag = 0;
			}
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		v.push_back(xy[i]);
		dfs(lv + 1, xy[i]);
		v.pop_back();
	}
}

void sol() {
	scanf("%d %d %d", &N, &x, &y);
	xy[0] = x;
	xy[1] = y;
	len = to_string(N).length();

	for (int i = 0; i < 2; i++) {
		v.push_back(xy[i]);
		dfs(1, xy[i]);
		v.clear();
	}
	if(flag) printf("%d\n", -1);
	else printf("%d\n", ans);
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