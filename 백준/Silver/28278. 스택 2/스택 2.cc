#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

#define FOR(i,s,e) for(register int i=(s); i<(e); ++i)

int N;
stack<int> s;
int stackArr[1000000];
int stackPointer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N;

	FOR(i, 0, N) {
		int x = 0;
		int cmd = 0;
		cin >> cmd;

		switch (cmd)
		{
		case 1:
			cin >> x;

			stackArr[stackPointer++] = x;
			break;
		case 2:
			if (stackPointer == 0) cout << -1 << '\n';
			else cout << stackArr[--stackPointer] << '\n';
			break;
		case 3:
			cout << stackPointer << '\n';
			break;
		case 4:
			if (stackPointer == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		case 5:
			if (stackPointer == 0) cout << -1 << '\n';
			else cout << stackArr[stackPointer - 1] << '\n';
			break;
		}

		if (stackPointer < 0) stackPointer = 0;
	}

	return 0;
}