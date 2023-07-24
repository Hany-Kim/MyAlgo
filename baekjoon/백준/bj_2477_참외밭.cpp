#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
pair<pair<int,int>, int> a[10];
int idx_cnt[5];
int long_len1, long_len2;
int flag_long_len1, flag_long_len2;
int short_len1, short_len2;
int flag_short_len1, flag_short_len2;
int flag1, flag2;

void sol() {
	cin >> K;
	for (int i = 0; i < 6; i++) {
		cin >> a[i].first.first >> a[i].first.second;
	}
	for (int i = 0; i < 6; i++) {
		idx_cnt[a[i].first.first]++;
	}
	for (int i = 1; i <= 4; i++) {
		if (idx_cnt[i] == 1) {// 긴변 구하기
			for (int j = 0; j < 6; j++) {
				if ((a[j].first.first == i) && !flag_long_len1) {
					long_len1 = a[j].first.second;
					a[j].second = 1;
					flag_long_len1 = 1;
				}
				else if ((a[j].first.first == i) && !flag_long_len2) {
					long_len2 = a[j].first.second;
					a[j].second = 1;
					flag_long_len2 = 1;
				}
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		if (a[i].second == 1) {//가지치기
			if (!flag1) {
				if (i > 0)
					if (a[i - 1].second != 1) a[i - 1].second = 2;
				if (i == 0) {
					if (a[5].second != 1) a[5].second = 2;
					else if (a[5].second == 1) a[4].second = 2;
				}
				flag1 = 1;
			}
			else if (!flag2) {
				if (i != 5)
					if(a[i + 1].second!=1) a[i + 1].second = 2;
				if (i == 5) {
					if (a[0].second != 1) a[0].second = 2;
					else if (a[0].second == 1)a[1].second = 2;
				}
				flag2 = 1;
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		if (a[i].second == 0) {
			if (!flag_short_len1) {
				short_len1 = a[i].first.second;
				flag_short_len1 = 1;
			}
			else if (!flag_short_len2) {
				short_len2 = a[i].first.second;
				flag_short_len2 = 1;
			}
		}
	}

	int big_sq = long_len1 * long_len2;
	int small_sq = short_len1 * short_len2;
	int ans = K * (big_sq - small_sq);
	cout << ans;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}