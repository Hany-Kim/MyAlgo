#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define SUBJECT_NUM (20.0)

unordered_map<string, double>um;

void init() {
	um["A+"] = 4.5;
	um["A0"] = 4.0;
	um["B+"] = 3.5;
	um["B0"] = 3.0;
	um["C+"] = 2.5;
	um["C0"] = 2.0;
	um["D+"] = 1.5;
	um["D0"] = 1.0;
	um["F"] = 0.0;
}

bool mstrcmp(string str, char rate) {
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != rate) return false;
		if (i > 0) return false;
	}
	return true;
}

void sol() {
	init();
	double sum = 0.0;
	double cnt = 0;
	for (int i = 0; i < SUBJECT_NUM; ++i) {
		string subName = "";
		double score = 0.0;
		string rate = "";


		cin >> subName >> score >> rate;
		if (mstrcmp(rate, 'P')) continue;
		sum += (um[rate] * score);
		cnt += score;
	}
	double avg = sum / cnt;

	cout << avg;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}