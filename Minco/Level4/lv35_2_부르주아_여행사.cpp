#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> map;
priority_queue<int> value;
struct Point {
	int y;
	int x;
};
priority_queue<Point> node;


void sol() {
	cin >> n;
	map = vector<vector<int>>(n);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int t = 0;
			cin >> t;
			map[y].push_back(t);
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] != 0) {
				value.push(map[y][x]);
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < n; y++) {
			int flag = 0;
			for (int x = 0; x < n; x++) {
				if (value.top() == map[y][x]) {
					cout << char(y + 'A') << '-' << char(x + 'A') << " ";
					flag = 1;
					break;
				}
			}
			if (flag)break;
		}
		cout << value.top() << '\n';
		value.pop();
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