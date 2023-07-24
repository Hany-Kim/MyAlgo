#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M, H;
vector<long long> tree;

void BST() {
	int s = 0;
	int e = tree[N - 1];
	int sum = 0;

	while (s < e) {
		int mid = (s + e) / 2;

		if (tree[mid] == M) {

		}
		else if (tree[mid] < M) {
			s = mid + 1;
		}
		else if (tree[mid] > M) {
			e = mid - 1;
		}
	}
}

void sol() {
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++) {
		long long t;
		scanf("%lld", &t);
		tree.push_back(t);
	}
	sort(tree.begin(), tree.end());
	BST();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}