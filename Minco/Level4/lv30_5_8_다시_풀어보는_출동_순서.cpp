#include <iostream>
#include <vector>
using namespace std;

vector<char> hero = {
	'B','I','A','H'
};

int n;
int index = -1;
bool used[4];

void input() {
	cin >> n;
}

int search_hero(int index) {
	for (int i = 1; i <= 4; i++) {
		int select = (index + i) % 4;
		if (used[select] == 0)return select;
	}
	return 0;
}

void sol() {
	input();
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < n; i++) {
			index = search_hero(index);
		}
		cout << hero[index] << " ";
		used[index] = 1;
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}