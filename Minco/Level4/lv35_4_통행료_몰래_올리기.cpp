#include <iostream>
#include <queue>
using namespace std;

int n;
vector<vector<int>> map;
struct Price
{
	int from;
	int to;
	int weight;
};
priority_queue<Price> gate;

bool operator<(Price left, Price right) {
	if (left.weight > right.weight)return true;
	if (left.weight < right.weight)return false;

	if (left.to > right.to)return true;
	if (left.to < right.to)return false;

	if (left.from > right.from)return true;
	if (left.from < right.to)return false;

	return false;
}

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
		for (int x = y; x < n; x++) {
			if (map[y][x] == 0 || map[y][x] == -1)continue;
			gate.push({ y,x,map[y][x] });
		}
	}

	// 10�� �λ�
	for (int i = 0; i < 10; i++) {
		// ����ᰡ ���� �� ������ ã�´�.
		Price now = gate.top();
		gate.pop();
		// 2��� �λ�
		now.weight = now.weight * 2;
		gate.push(now);
		if (i == 9) {
			cout << now.weight << "����";
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}