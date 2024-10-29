#include <iostream>
#include <deque>
using namespace std;

int n;
deque<int> dq;

void cmd1(int x) {
	dq.push_front(x);
}
void cmd2(int x) {
	dq.push_back(x);
}
int cmd3() {
	int ret = 0;

	if (dq.size() == 0) return -1;
	ret = dq.front();
	dq.pop_front();

	return ret;
}
int cmd4() {
	int ret = 0;
	
	if (dq.size() == 0) return -1;
	ret = dq.back();
	dq.pop_back();

	return ret;
}
int cmd5() {
	return dq.size();
}
int cmd6() {
	if (dq.empty()) return 1;
	return 0;
}
int cmd7() {
	int ret = 0;

	if (dq.size() == 0) return -1;
	ret = dq.front();

	return ret;
}
int cmd8() {
	int ret = 0;

	if (dq.size() == 0) return -1;
	ret = dq.back();

	return ret;
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int cmd = 0;
		int x = 0;
		int p = 0;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cin >> x;
			cmd1(x);
			break;
		case 2:
			cin >> x;
			cmd2(x);
			break;
		case 3:
			p = cmd3();
			cout << p << '\n';
			break;
		case 4:
			p = cmd4();
			cout << p << '\n';
			break;
		case 5:
			p = cmd5();
			cout << p << '\n';
			break;
		case 6:
			p = cmd6();
			cout << p << '\n';
			break;
		case 7:
			p = cmd7();
			cout << p << '\n';
			break;
		case 8:
			p = cmd8();
			cout << p << '\n';
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}