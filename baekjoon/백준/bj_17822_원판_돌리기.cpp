#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
vector<vector<int>> circle;
int ans;

void dir_clock(int x, int k) {
	for (int i = 0; i < k; i++) {
		int tmp = circle[x].back();
		circle[x].pop_back();

		circle[x].insert(circle[x].begin() + 1, tmp);
	}
}
void rev_dir_clock(int x, int k) {
	for (int i = 0; i < k; i++) {
		int tmp = circle[x][1];
		circle[x].erase(circle[x].begin() + 1);

		circle[x].push_back(tmp);
	}
}
void del_same_num() {
	int del_flag[51][51] = { 0, };
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			int idx = x - 1;
			if (idx < 1) idx = M;
			if ((circle[y][idx] == circle[y][x]) && (circle[y][x] != 0)) {
				del_flag[y][idx] = 1;
				del_flag[y][x] = 1;
			}
		}
	}
	for (int x = 1; x <= M; x++) {
		for (int y = 2; y <= N; y++) {
			if ((circle[y - 1][x] == circle[y][x]) && (circle[y][x] != 0)) {
				del_flag[y - 1][x] = 1;
				del_flag[y][x] = 1;
			}
		}
	}

	int change_flag = 1;
	int cnt = 0;
	int whole_sum = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (del_flag[y][x] == 1) {
				circle[y][x] = 0;
				change_flag = 0;
			}
			if (circle[y][x] != 0) {
				++cnt;
				whole_sum += circle[y][x];
			}
		}
	}

	float avg = (float)whole_sum / (float)cnt;
	if (change_flag) {
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				if (circle[y][x] != 0) {
					if (circle[y][x] < avg) {
						circle[y][x] += 1;
					}
					else if (circle[y][x] > avg) {
						circle[y][x] -= 1;
					}
				}
			}
		}
	}
}
void sum() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (circle[y][x] != 0) {
				ans += circle[y][x];
			}
		}
	}
}
void output() {
	for (int y = 1; y <= N; y++) {
		cout << "[" << y << "] ";
		for (int x = 1; x <= M; x++) {
			cout << circle[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void sol() {
	cin >> N >> M >> T;

	circle = vector<vector<int>>(N + 1, vector<int>(M + 1));
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> circle[y][x];
		}
	}

	for (int i = 0; i < T; i++) {
		int xi = 0, di = 0, ki = 0;
		cin >> xi >> di >> ki;
		int mul = 1;
		while (1) {
			int nn = mul * xi;
			if (nn > N) break;

			if(di == 0) dir_clock(nn,ki);
			else if(di == 1) rev_dir_clock(nn,ki);

			++mul;
		}

		del_same_num();
	}
	sum();

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