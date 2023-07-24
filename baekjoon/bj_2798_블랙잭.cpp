#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> card_num;
vector <bool> used;
int path[3];
int cur_max_card_num;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		card_num.push_back(a);
		used.push_back(0);
	}
}

void draw(int lv) {
	if (lv == 3) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += path[i];
		}
		if (sum <= M) {
			if (sum > cur_max_card_num) {
				cur_max_card_num = sum;
			}
		}
		return;
	}
	for (int i = 0; i < card_num.size(); i++) {
		if (used[i] == 1)continue;
		path[lv] = card_num[i];
		used[i] = 1;
		draw(lv + 1);
		used[i] = 0;
	}
}

void sol() {
	input();
	draw(0);
	cout << cur_max_card_num;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}