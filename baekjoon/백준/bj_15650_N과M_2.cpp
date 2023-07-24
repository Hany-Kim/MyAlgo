#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> path;
bool visited[9];
int branch = 1;

void func(int lv, int br) {
	if (lv == M) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = branch; i <= N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			path.push_back(i);
			func(lv + 1, branch + 1);
			visited[i] = false;
			path.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	func(0, branch);

	return 0;
}