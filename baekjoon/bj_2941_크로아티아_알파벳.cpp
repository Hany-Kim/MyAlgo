#include <iostream>
#include <string>
using namespace std;

string croatia[8] = {
	"c=",
	"c-",
	"dz=",
	"d-",
	"lj",
	"nj",
	"s=",
	"z="
};

string str;
int idx;
int cnt;
int flag;

void input() {
	cin >> str;
}

void sol() {
	input();

	while (!str.empty()) {
		flag = 0;
		for (int i = 0; i < 8; i++) {
			if (str.find(croatia[i], 0) == 0) {
				idx = i;
				flag = 1;
				break;
			}
		}
		if (flag) {
			str.erase(str.find(croatia[idx], 0), croatia[idx].length());
			cnt++;
		}
		else {
			str.erase(0, 1);
			cnt++;
		}
	}
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