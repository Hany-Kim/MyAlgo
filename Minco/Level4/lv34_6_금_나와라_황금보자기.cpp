#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int n;
	string type;
};

priority_queue<Node> q;

bool operator<(Node v, Node tar) {
	if (tar.n < v.n) return 1;
	if (tar.n > v.n) return 0;

	if (tar.type == "gold" && v.type == "stone") return 1;
	return 0;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;

		q.push({ t, "gold" });
	}

	int cnt = 0;
	while (1) {
		Node d1 = q.top();
		q.pop();
		if (d1.type == "stone") break;
		cnt++;

		Node d2 = q.top();
		q.pop();
		if (d2.type == "stone") break;
		cnt++;
		q.push({ d2.n * 2, "stone" });
	}

	cout << cnt;

	return 0;
}