#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[16][16];
struct Node {
	int x;
	int y;
};
vector<Node> market;
vector<Node> person;
vector<int> arrive;
int t;


void sol() {
	cin >> n >> m;
	for (register int x = 1; x <= n; ++x) {
		for (register int y = 1; y <= n; ++y) {
			cin >> map[x][y];
		}
	}
	// 1번인덱스부터 사용하게 만들기
	market.push_back({0,0});
	person.push_back({0,0});
	arrive.push_back(0);
	for (register int i = 1; i <= m; ++i) {
		int x = 0, y = 0;
		cin >> x >> y;
		market.push_back({ x,y });
	}

	while (t <= m) {
		++t;
		if (person.size() > 1) {
			for (register int i = 1; i <= person.size(); ++i) {
				if (arrive[i] == true) continue;

			}
		}

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

