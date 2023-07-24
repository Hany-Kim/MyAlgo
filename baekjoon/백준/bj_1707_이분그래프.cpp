#include <iostream>
using namespace std;

int K;
int V, E;
struct Node {
	int node;
	Node* next;
};
Node HEAD[20200];
Node POOL[202000 * 2];
int pcnt;
int check[20200];

void init() {
	pcnt = 0;
	for (int i = 1; i <= V; i++) {
		HEAD[i].next = 0;
		check[i] = 0;
	}
}
void Make(int p, int c) {
	Node* nd = &POOL[pcnt++];
	nd->node = c;
	nd->next = HEAD[p].next;
	HEAD[p].next = nd;
}
int dfs(int node, int color) {
	check[node] = color;
	
	for (Node* p = HEAD[node].next; p; p = p->next) {
		if (check[p->node] == color)return 0;
		if (!check[p->node]) {
			if (!dfs(p->node, 3 - color))return 0;
		}
	}
	return 1;
}
void sol() {
	cin >> K;
	for (int tc = 0; tc < K; tc++) {
		int flag = 0;
		cin >> V >> E;
		
		init();

		for (int i = 0; i < E; i++) {
			int p = 0, c = 0;
			cin >> p >> c;
			Make(p, c);
			Make(c, p);
		}

		flag = 0;
		for (int i = 1; i <= V; i++) {
			if (!check[i]) {
				flag = dfs(i, 1);
				if (!flag) break;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
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