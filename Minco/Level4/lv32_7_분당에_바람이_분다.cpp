#include <iostream>
#include <vector>
using namespace std;

int map[3][3];
int N, K, cnt;
vector<int> wind_power;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int y = 0, x = 0;
		cin >> y >> x;
		cin >> map[y][x];
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int t = 0;
		cin >> t;
		wind_power.push_back(t);
	}
}

void wind(int wp) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] == 0)continue;
			if (map[y][x] % 10 <= wp) {
				map[y][x] = map[y][x] / 10;
			}
			else if (map[y][x]>wp) {
				map[y][x] = map[y][x] - wp;
			}
		}
	}
}

void count() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] == 0)continue;
			while (map[y][x] > 10) {
				map[y][x] = map[y][x] / 10;
				cnt++;
			}
			cnt++;
		}
	}
}

void sol() {
	input();
	for (int i = 0; i < K; i++) {
		wind(wind_power[i]);
	}
	count();
	cout << cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}