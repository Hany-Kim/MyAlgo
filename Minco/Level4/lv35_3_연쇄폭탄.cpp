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

	//�ݺ� ���map�� ����������
	while (!order.empty()) {
		//order���� ������, ��ǥ Ȯ���ϱ�
		Point now = order.top();
		order.pop();
		//map���� �ش���ǥ Ȯ���ϱ� 1�� ����, ���� ������ ����, ������ ����
		if (map[now.row][now.col] != 0) {
			second = now.secquence;
			// �ڱ��ڽ� ����
			map[now.row][now.col] = 0;
			// ��, �Ʒ�, ��, �� ����
			for (int i = 0; i < 4; i++) {
				int dy = now.row + direct[0][i];
				int dx = now.col + direct[1][i];
				if (dy < 0 || dy >= n || dx < 0 || dx >= n || map[dy][dx] == 0)continue;
				map[dy][dx] = 0;
			}
		}
	}
	cout << second << "��";
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}