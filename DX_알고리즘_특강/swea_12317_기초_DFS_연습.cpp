#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

static unsigned int seed = 12345;
static unsigned int pseudo_rand(int max) {
	seed = ((unsigned long long)seed * 1103515245 + 12345) & 0x7FFFFFFF;
	return seed % max;
}

#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FOR(s, n) for(register int i = (s); i<(n); ++i)

struct Node {
	int ability;
	Node* child[5];
};
Node node_pool[100];

Node* get_node(int abili) {
	node_pool[abili].ability = abili;
	FOR(0, 5) node_pool[abili].child[i] = nullptr;
	return &node_pool[abili];
}
void init() {
	FOR(0, 100) {
		node_pool[i].ability = 0;
		for (register int j = 0; j < 5; ++j)
			node_pool[i].child[j] = nullptr;
	}
}
void dfs_init(int N, int path[100][2])
{
	init();
	int idx = 0;
	while (1) {
		if (path[idx][0] == 0 && path[idx][1] == 0) break;

		Node* new_pNode = nullptr;
		if (node_pool[path[idx][0]].ability == 0) { // node_pool에 노드가 아직 없다.
			new_pNode = get_node(path[idx][0]);
		}
		else {
			new_pNode = &node_pool[path[idx][0]];
		}

		Node* new_cNode = nullptr;
		if (node_pool[path[idx][1]].ability == 0) {
			new_cNode = get_node(path[idx][1]);
		}
		else {
			new_cNode = &node_pool[path[idx][1]];
		}

		FOR(0, 5) if (new_pNode->child[i] == nullptr) { // 부모 자식 연결
			new_pNode->child[i] = new_cNode;
			break;
		}
		
		++idx;
	}
}
int ans = -1;
void func(Node* parent, Node* child) {
	if (ans == -1) {
		if (parent->ability < child->ability) {
			ans = child->ability;
			return;
		}
	}
	Node* ptr = &node_pool[child->ability];

	FOR(0, 5) if (ptr->child[i] != nullptr) {
		func(parent, ptr->child[i]);
	}
}

int dfs(int n)
{
	Node* ptr = &node_pool[n];
	ans = -1;
	FOR(0, 5) if (ptr->child[i] != nullptr) {
		if (ans != -1) break;
		func(ptr, ptr->child[i]);
	}
	int ret = ans;
	return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int p[MAX_K + 2];
static int c[MAX_K + 2];
static int path[MAX_N][2];
static void makeTree(int n) {
	for (int i = 1; i < MAX_K + 2; ++i) {
		p[i] = c[i] = -1;
	}
	c[pseudo_rand(MAX_K + 1) + 1] = 0;
	for (int i = 0; i < n; ++i) {
		int pi = pseudo_rand(MAX_K + 1) + 1;
		while (c[pi] < 0 || c[pi] >= MAX_CHILD) {
			++pi;
			if (pi == MAX_K + 2)
				pi = 1;
		}
		int ci = pseudo_rand(MAX_K + 1) + 1;
		while (c[ci] >= 0) {
			++ci;
			if (ci == MAX_K + 2)
				ci = 1;
		}
		p[ci] = pi;
		++c[pi];
		c[ci] = 0;
	}
	bool check[MAX_K + 2] = { false };
	for (int i = 0; i < n; ++i) {
		int e = pseudo_rand(MAX_K + 1) + 1;
		while (check[e] || c[e] < 0 || p[e] == -1) {
			++e;
			if (e == MAX_K + 2)
				e = 1;
		}
		check[e] = true;
		path[i][0] = p[e];
		path[i][1] = e;
	}
}

int main() {
	setbuf(stdout, NULL);
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	int totalScore = 0;
	for (int tc = 1; tc <= T; tc++) {
		int n, q;

		scanf("%d %d %d", &n, &q, &seed);

		makeTree(n - 1);
		dfs_init(n, path);

		bool check[MAX_K + 2] = { false };
		int score = 100;
		for (int i = 0; i < q; ++i) {
			int k, ret, correct;

			scanf("%d", &k);

			ret = dfs(k);

			scanf("%d", &correct);

			if (ret != correct)
				score = 0;
		}
		printf("#%d : %d\n", tc, score);
		totalScore += score;
	}
	printf("#total score : %d\n", totalScore / T);

	return 0;
}