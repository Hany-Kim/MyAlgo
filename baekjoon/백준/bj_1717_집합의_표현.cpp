#include <iostream>
using namespace std;

int n, m;
int vect[1000001];

int uFind(int tar) {
	//if (vect[tar] == 0)return tar;
	//int ret = uFind(vect[tar]);
	//vect[tar] = ret;
	//return ret;
	if (tar == vect[tar])return tar;
	return vect[tar] = uFind(vect[tar]);
}

void uUnion(int a, int b) {
	int da = uFind(a);
	int db = uFind(b);
	//if (da == db) return;
	//vect[db] = da;
	if (da > db)vect[da] = db;
	else if (da < db)vect[db] = da;
}

void sol() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		vect[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int check = 0;
		int a = 0, b = 0;
		cin >> check >> a >> b;

		if (check == 0) {
			uUnion(a, b);
		}
		else if (check == 1) {
			if (uFind(a) == uFind(b))cout << "YES\n";
			else if (uFind(a) != uFind(b))cout << "NO\n";
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();
	int de = 1;
	return 0;
}