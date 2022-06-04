#include <iostream>
#include <string>
using namespace std;

string sen1;
string sen2;
int max_length;

void input() {
	cin >> sen1 >> sen2;
}

void compare() {

}

void solution() {
	input();

	for (int i = 0; i < sen2.length(); i++) {
		sen2.substr(0, i);
	}
	compare();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}