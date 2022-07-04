#include <iostream>
using namespace std;
// 출발지점 입력
// 노드번호와 가중치 출력
// 여러 노드중 낮은 숫자 노드부터
int arr[6][6] = {
	0,0,1,0,2,0,
	5,0,3,0,0,0,
	0,0,0,0,0,7,
	2,0,0,0,8,0,
	0,0,9,0,0,0,
	4,0,0,7,0,0
};
int K;
bool used[6];
int weight;

void dfs(int now) {
	cout << now << " " << weight << endl;
	used[now] = 1;
	for (int to = 0; to < 6; to++) {
		if (used[to] != 0)continue;
		if (arr[now][to] == 0)continue;
		weight += arr[now][to];
		dfs(to);
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> K;

	dfs(K);
	return 0;
}