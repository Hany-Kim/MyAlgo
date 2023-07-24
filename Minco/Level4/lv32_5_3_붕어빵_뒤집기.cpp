#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char map[3][7] = {
	"ABCEFG",
	"HIJKLM",
	"NOPQRS"
};
char cmap[3][7];
int dir[2][5] = {
	0,-1,1,0,0,
	0,0,0,-1,1
};
vector <char> rev;
string str;

void input() {
	cin >> str;
}

void sol() {
	input();
	for (int i = 0; i < str.length(); i++) {
		rev.push_back(str[i]);
	}
	memcpy(cmap, map, 21);
	for (int i = 0; i < rev.size(); i++) {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 6; x++) {
				if (rev[i] == cmap[y][x]) {
					for (int d = 0; d < 5; d++) {
						int dy = y + dir[0][d];
						int dx = x + dir[1][d];
						if (cmap[dy][dx] != '#') {
							cmap[dy][dx] = '#';
						}
						else if (cmap[dy][dx] == '#') {
							cmap[dy][dx] = map[dy][dx];
						}
					}
				}
			}
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			cout << cmap[y][x];
		}
		cout << "\n";
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}