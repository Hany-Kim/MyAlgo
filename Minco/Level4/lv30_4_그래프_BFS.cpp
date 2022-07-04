#include <iostream>
#include <queue>
using namespace std;

int arr[6][6] = {
	0,0,0,0,1,0,
	1,0,1,0,0,1,
	1,0,0,1,0,0,
	1,1,0,0,0,0,
	0,1,0,1,0,1,
	0,0,1,1,0,0
};
bool used[6];
int startNode;
queue<int> q;

void bfs() {
	
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> startNode;
	bfs();

	return 0;
}