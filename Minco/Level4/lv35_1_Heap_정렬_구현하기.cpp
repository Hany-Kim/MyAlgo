#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	string str = "";
	cin >> str;
	priority_queue<char> q;
	for (int i = 0; i < str.length(); i++) {
		q.push(str[i]);
	}
	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}
	return 0;
}