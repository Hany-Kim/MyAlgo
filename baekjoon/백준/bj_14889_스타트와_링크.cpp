#include <iostream>
using namespace std;

int N;
int team[21][21];
int used[22];
int min_num = 9999;
int start, link;


void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> team[y][x];
		}
	}
}

void check() {
	start = 0;
	link = 0;
	for (int y = 0; y <= N; y++) {
		for (int x = 0; x <= N; x++) {
			if (used[y] == 1 && used[x] == 1)start += team[y][x];
			if (used[y] == 0 && used[x] == 0)link += team[y][x];
		}
	}
	int temp = abs(start - link);
	if (min_num > temp)min_num = temp;
}

void set_team(int lv,int num) {
	if (lv == (N / 2)) {
		check();
		return;
	}
	for (int i = num; i < N; i++) {
		used[i] = 1;
		set_team(lv + 1, i + 1);
		used[i] = 0;
	}

}

void sol() {
	input();
	set_team(0,1);
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