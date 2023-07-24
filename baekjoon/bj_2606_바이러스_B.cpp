#include <iostream>
using namespace std;

int N, M, ans;
struct Node {
	int node;
	Node* next;
};
Node HEAD[110];
Node POOL[110 * 110];
int pcnt;
int visit[110];

void init(int n) {
	pcnt = 0;
	for (int i = 1; i <= N; i++) HEAD[i].next = 0;
	for (int i = 1; i <= N; i++)visit[i] = 0;

	ans = 0;
}
void Make(int p, int c) {
	Node* nd = &POOL[pcnt++];
	nd->node = c;

	nd->next = HEAD[p].next;
	HEAD[p].next = nd;
}

int queue[110 * 110];
int wp, rp;

void bfs() {
	int out = 0;
	wp = rp = 0;

	queue[wp++] = 1;
	visit[1] = 1;

	while (wp > rp) {
		out = queue[rp++];
		for (Node* p = HEAD[out].next; p; p = p->next) {
			if (visit[p->node] == 0) {
				visit[p->node] = 1;
				ans++;
				queue[wp++] = p->node;
			}
		}
	}
}

void outputHead(int head) {
	cout << "head " << head << " : ";
	for (Node* p = HEAD[head].next; p; p = p->next) cout << p->node << ' ';
	cout << '\n';
}

void sol() {
	cin >> N >> M;
	init(N);
	
	for (int i = 0; i < M; i++) {
		int p = 0, c = 0;
		cin >> p >> c;

		Make(p, c);
		Make(c, p);
	}

	//for (int i = 1; i <= N; i++)outputHead(i);

	bfs();

	cout << ans << '\n';
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}