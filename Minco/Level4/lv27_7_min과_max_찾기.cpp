#include <iostream>
#include <string>

using namespace std;

int Number[6];
string Command;

int max;
int min;
int max_val, min_val = 9999;

void input() {
	for (int i = 0; i < 6; i++) {
		cin >> Number[i];
	}
	cin >> Command;
}

void min_func() {
	int idx = 0;
	for (int i = 0; i < 6; i++) {
		if (min_val > Number[i] && Number[i] != -1) {
			min_val = Number[i];
			idx = i;
		}
	}
	Number[idx] = -1;
	cout << min_val;
	min_val = 9999;
}
void max_func() {
	int idx = 0;
	for (int i = 0; i < 6; i++) {
		if (max_val < Number[i] && Number[i] != -1) {
			max_val = Number[i];
			idx = i;
		}
	}
	Number[idx] = -1;
	cout << max_val;
	max_val = 0;
}

void search() {
	for (int i = 0; i < 6; i++) {
		if (Command[i] == 'm') {
			min_func();
		}
		if (Command[i] == 'x') {
			max_func();
		}
	}
}

int main() {
	input();
	search();

	return 0;
}