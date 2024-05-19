#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define FOR(i,s,e) for(register int i=(s); i<(e); ++i)

bool endFlag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string str = "";
		getline(cin, str);
		if (str.length() == 1 && str == ".") endFlag = true;
		if (endFlag) break;
		stack<char> myStack;
		stack<char> openBracket;
		for (register int i = str.length() - 1; i >= 0; i--) {
			// 역탐색
			if (str[i] == ']' || str[i] == ')') {
				myStack.push(str[i]);
			}
			else if (!myStack.empty() && str[i] == '[' && myStack.top() == ']') {
				myStack.pop();
			}
			else if (!myStack.empty() && str[i] == '(' && myStack.top() == ')') {
				myStack.pop();
			}
			else if (str[i] == '[' || str[i] == '(') {
				openBracket.push(str[i]);
			}
		}
		if (myStack.empty() && openBracket.empty()) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}