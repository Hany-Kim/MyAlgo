#include <iostream>
using namespace std;

char vect[100];

char uFind(char ch) {
	if (vect[ch] == 0) return ch;
	char ret = uFind(vect[ch]);
	vect[ch] = ret;
	return ret;
}

void uUnion(char t1, char t2) {
	char a = uFind(t1);
	char b = uFind(t2);
	if (a == b) return;

	if (a >= 'A' && a <= 'Z') {
		vect[b] = a;
	}
	else {
		vect[a] = b;
	}
}

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;

	char a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		uUnion(a, b);
	}

	for (int i = 1; i <= k; i++) {
		cout << uFind('0' + i);
	}

	return 0;
}