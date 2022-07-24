#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string str[3];
string str_temp[3];
int index_num;
int max_length;

void input() {
	for (int i = 0; i < 3; i++) {
		cin >> str[i];
	}
	memcpy(str_temp, str, 3);
}

void except_top_0() {
	for (int i = 0; i < 3; i++) {
		while (str[i].front() == '0') {
			str[i].erase(0, 1);
		}
	}
}

void cmp(int n) {
	for (int i = 0; i < str[n].size(); i++) {
		if (str[index_num][i] == str[n][i])continue;
		if (str[index_num][i] == '0' && str[n][i] == '1') {
			index_num = n;
			max_length = str[n].size();
		}
	}
}

void length_compare() {
	for (int i = 0; i < 3; i++) {
		if (str[i].size() > max_length) {
			max_length = str[i].size();
			index_num = i;
		}
		if (str[i].size() == max_length) {
			cmp(i);
		}
	}
}

void sol() {
	input();
	except_top_0();
	length_compare();
	cout << str_temp[index_num];
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}