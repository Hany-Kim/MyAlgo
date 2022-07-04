#include <iostream>
#include <string>
using namespace std;

string sen1;
string sen2;
string sen_temp;
int pos;
string res = "";
int length;

void input() {
	cin >> sen1 >> sen2;
}

void search() {
	for (int i = 0; i < sen1.size(); i++) {
		for (int j = sen1.size(); j >= i; j--) {
			sen_temp = sen1.substr(i, j);
			pos = sen2.find(sen_temp);
			if (pos >= 0) {
				//Ã£¾Ò´Ù.
				
				if (length < sen_temp.size()) {
					length = sen_temp.size();
					res = sen_temp;
				}
				
			}

		}
	}
}

void solution() {
	input();
	search();
	cout << res;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}