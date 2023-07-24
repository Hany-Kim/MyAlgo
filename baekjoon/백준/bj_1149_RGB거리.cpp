#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int rgb[1001][3];
int cpy[1001][3];
int used_rgb[3];
int sum;

void sol() {
	cin >> N;
	memset(cpy, 2134567, sizeof(cpy));
	for (int i = 0; i < N; i++) {
		int r = 0, g = 0, b = 0;
		cin >> r >> g >> b;
		if (i == 0) {
			cpy[i][0] = r;
			cpy[i][1] = g;
			cpy[i][2] = b;
		}
		rgb[i][0] = r;
		rgb[i][1] = g;
		rgb[i][2] = b;
		/*int min_num = 0;
		if (used_rgb[0]) {
			min_num = min(g, b);
		}
		else if (used_rgb[1]) {
			min_num = min(r, b);
		}
		else if (used_rgb[2]) {
			min_num = min(r, g);
		}
		else min_num = min(min(r, g), b);

		if (!used_rgb[0] && (min_num == r)) {
			used_rgb[0] = 1;
			used_rgb[1] = 0;
			used_rgb[2] = 0;
			sum += r;
		}
		else if (!used_rgb[1] && (min_num == g)) {
			used_rgb[0] = 0;
			used_rgb[1] = 1;
			used_rgb[2] = 0;
			sum += g;
		}
		else if (!used_rgb[2] && (min_num == b)) {
			used_rgb[0] = 0;
			used_rgb[1] = 0;
			used_rgb[2] = 1;
			sum += b;
		}*/
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				if (cpy[i + 1][1] > (cpy[i][j] + rgb[i + 1][1])) cpy[i + 1][1] = cpy[i][j] + rgb[i + 1][1];
				if (cpy[i + 1][2] > (cpy[i][j] + rgb[i + 1][2])) cpy[i + 1][2] = cpy[i][j] + rgb[i + 1][2];
			}
			else if (j == 1) {
				if (cpy[i + 1][0] > (cpy[i][j] + rgb[i + 1][0])) cpy[i + 1][0] = cpy[i][j] + rgb[i + 1][0];
				if (cpy[i + 1][2] > (cpy[i][j] + rgb[i + 1][2])) cpy[i + 1][2] = cpy[i][j] + rgb[i + 1][2];
			}
			else if (j == 2) {
				if (cpy[i + 1][1] > (cpy[i][j] + rgb[i + 1][1])) cpy[i + 1][1] = cpy[i][j] + rgb[i + 1][1];
				if (cpy[i + 1][0] > (cpy[i][j] + rgb[i + 1][0])) cpy[i + 1][0] = cpy[i][j] + rgb[i + 1][0];
			}
		}
	}
	cout << min(min(cpy[N-1][0], cpy[N-1][1]), cpy[N-1][2]);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}