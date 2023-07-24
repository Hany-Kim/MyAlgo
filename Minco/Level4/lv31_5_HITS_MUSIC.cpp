#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector <string> v;
string path[2];
string answer = "HITSMUSIC";
int cnt;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str = "";
		cin >> str;
		v.push_back(str);
	}
}

void func(int lv, int now) {
	if (lv == 2) {
		string temp = "";
		for (int i = 0; i < 2; i++) {
			temp += path[i];
		}
		if (temp == answer) {
			cnt++;
		}
		return;
	}
	for (int i = now; i < N; i++) {
		path[lv] = v[i];
		func(lv + 1, i + 1);
	}
}

void sol() {
	input();
	func(0, 0);
	cout << cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}