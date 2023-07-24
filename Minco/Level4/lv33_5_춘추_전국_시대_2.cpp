#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, Situation;
struct Country {
	int people;
	char root;
	int nationCnt;
	int isDie;
};
Country vect[100];
string command;
char c1, c2;

char uFind(char tar) {
	if (vect[tar].root == 0)return tar;
	char ret = uFind(vect[tar].root);
	vect[tar].root = ret;
	return ret;
}

void uUnion(char c1, char c2) {
	char da = uFind(c1);
	char db = uFind(c2);
	if (vect[c1].isDie == 1 || vect[c2].isDie == 1)return;
	if (da == db) return;
	vect[db].root = da;

	vect[da].people += vect[db].people;
	vect[da].nationCnt += vect[db].nationCnt;
	vect[db].people = 0;
	vect[db].nationCnt = 0;
}

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> vect[int(i + 'A')].people;
		vect[int(i + 'A')].nationCnt = 1;
	}
	cin >> Situation;
	for (int i = 0; i < Situation; i++) {
		cin >> command >> c1 >> c2;
		if (command == "alliance") {
			uUnion(c1, c2);
		}
		else if (command == "war") {
			char e1 = uFind(c1);
			char e2 = uFind(c2);
			if (vect[c1].isDie == 1 || vect[c2].isDie == 1)continue;
			if (e1 == e2)continue;

			if (vect[e1].people > vect[e2].people) {
				vect[e2].isDie = 1;
				N -= vect[e2].nationCnt;
				vect[e2].people = 0;
				vect[e2].nationCnt = 0;
			}
			else {
				vect[e1].isDie = 1;
				N -= vect[e1].nationCnt;
				vect[e1].people = 0;
				vect[e1].nationCnt = 0;
			}

		}
	}
	cout << N;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}