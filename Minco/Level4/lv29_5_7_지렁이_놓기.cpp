#include <iostream>

using namespace std;

int index, life;
int map[5];
int repeat;

void input() {
	cin >> index >> life;
}

void init() {
	map[index] = life;
}

void output() {
	for (int i = 0; i < 5; i++) {
		if (map[i] == 0)cout << "_";
		else cout << map[i];
	}
}

void move() {
	map[index] = 0;
	life--;
	index++;
}

void solution() {
	input();
	repeat = life;
	for (int i = 0; i <= repeat; i++) {
		init();
		output();
		cout << endl;
		move();
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}