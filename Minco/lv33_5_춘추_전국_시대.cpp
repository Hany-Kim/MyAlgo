#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int vect[100];
int N, S;
vector<int> people;

char uFind(char ch) {
	if (vect[ch] == 0)return ch;
	char ret = uFind(vect[ch]);
	vect[ch] = ret;
	return ret;
}

void uUnion(char c1, char c2) {
	char a = uFind(c1);
	char b = uFind(c2);
	if (a == b)return;
	vect[b] = a;
}

void alliance(char c1, char c2) {
	uUnion(c1, c2);
}

void war(char c1, char c2) {

}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t = 0;
		cin >> t;
		people.push_back(t);
	}
	cin >> S;
	for (int i = 0; i < S; i++) {
		string command = " ";
		char c1 = ' ';
		char c2 = ' ';
		cin >> command >> c1 >> c2;
		if (command == "alliance") {
			alliance(c1, c2);
		}
		else if (command == "war") {
			war(c1, c2);
		}
	}
}

void sol() {
	input();

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}