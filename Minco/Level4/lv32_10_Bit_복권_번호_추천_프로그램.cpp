#include <iostream>
#include <vector>
using namespace std;

int n;
vector <vector <int>> map;
vector <vector <bool>> bit_map;
int arr[10];

void input() {
	cin >> n;
	map = vector<vector<int>>(n, vector<int>());
	bit_map = vector<vector<bool>>(n, vector<bool>());
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int t = 0;
			cin >> t;
			map[y].push_back(t);
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int t = 0;
			cin >> t;
			bit_map[y].push_back(t);
		}
	}
}

void sol() {
	input();
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (bit_map[y][x] == 1) {
				arr[map[y][x]]++;
			}
		}
	}
	int max_num = 100;
	while (max_num != 0) {
		for (int i = 0; i < 10; i++) {
			if (arr[i] == max_num) {
				for (int j = 0; j < max_num; j++) {
					cout << i << " ";
				}
			}
		}
		max_num--;
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