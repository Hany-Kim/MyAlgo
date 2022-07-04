#include <iostream>
using namespace std;
// 출발 노드 입력
// 방문할때마다 출력
// 여러 노드 이동 가능시, 숫자가 작은 노드부터
int arr[6][6] = {
	0,0,1,1,0,1,
	0,0,0,1,1,1,
	0,0,0,0,1,1,
	0,0,0,0,0,0,
	1,0,0,0,0,1,
	0,0,0,0,0,0
};
int startNode;
bool used[6];

void dfs(int now) {
	cout << now << " ";
	used[now] = 1;

	for (int to = 0; to < 6; to++) {
		if (used[to] != 0)continue;
		if (arr[now][to] == 0)continue;

		dfs(to);
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> startNode;
	dfs(startNode);
	return 0;
}