#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
string path;
int used[31];
int cnt;
long long dp[31][31];

void dfs(int max_lv, int lv, int now) {
	if (lv >= max_lv) {
		//cout << path << '\n';
		string r_path = path;
		reverse(r_path.begin(), r_path.end());
		if (path == r_path) cnt++;
		return;
	}
	for (int i = now; i < str.length(); i++) {
		if (used[i]) continue;
		path += str[i];
		used[i] = 1;
		dfs(max_lv, lv + 1, i);
		path.pop_back();
		used[i] = 0;
	}
}

void sol() {
	cin >> str;
	/*for (int i = 1; i <= str.length(); i++) {
		path = "";
		dfs(i,0,0);
	}*/
	for (int i = 0; i < str.length(); i++) {
		dp[i][i] = 1;
		if ((i + 1) < str.length() && str[i] == str[i + 1]) dp[i][i + 1] = 3;
		else if ((i + 1) < str.length())dp[i][i + 1] = 2;
	}
	for (int i = 2; i < str.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			int k = j + i;
			if (k >= str.length())break;
			if (str[j] == str[k])dp[j][k] = dp[j + 1][k] + dp[j][k - 1] + 1;
			else dp[j][k] = dp[j + 1][k] + dp[j][k - 1] - dp[j + 1][k - 1];
		}
	}
	//cout << cnt;
	cout << dp[0][str.length() - 1];
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}