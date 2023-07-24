#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
struct Point {
	int row;
	int col;
	int secquence;
};
priority_queue<Point> order;
int second;

int direct[2][4] = {
	-1, 1, 0, 0,
	0, 0, -1, 1
};

bool operator<(Point left, Point right) {
	return left.secquence > right.secquence;
}

void sol() {
	cin >> n;
	map = vector<vector<int>>(n);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int t = 0;
			cin >> t;
			map[y].push_back(t);
			order.push({ y, x, t });
		}
	}

	//반복 모든map이 터질때까지
	while (!order.empty()) {
		//order에서 꺼내기, 좌표 확인하기
		Point now = order.top();
		order.pop();
		//map에서 해당좌표 확인하기 1초 증가, 값이 있으면 폭파, 없으면 다음
		if (map[now.row][now.col] != 0) {
			second = now.secquence;
			// 자기자신 폭파
			map[now.row][now.col] = 0;
			// 위, 아래, 좌, 우 폭파
			for (int i = 0; i < 4; i++) {
				int dy = now.row + direct[0][i];
				int dx = now.col + direct[1][i];
				if (dy < 0 || dy >= n || dx < 0 || dx >= n || map[dy][dx] == 0)continue;
				map[dy][dx] = 0;
			}
		}
	}
	cout << second << "초";
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}