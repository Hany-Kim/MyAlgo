#include <iostream>

using  namespace std;

int N, t;
char w;
int arrange[11][4];
int time;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> w;
		arrange[t][int(w - 'A')] = 1;
	}

	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 4; x++) {
			if (arrange[y][x] == 1) {
				if ((x == 0) && (arrange[y][3] == 1)) {
					cout << -1 << endl;
				}
				else if ((x != 0) && (arrange[y][x-1] == 1)) {
					cout << -1 << endl;
				}
				else if ((x != 3) && (arrange[y][x + 1] == 1)) {

				}
				
			}
		}
	}

	int de = 1;
	return 0;
}