#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<long long> num;
vector<long long> num_cpy;
vector<char> oper;
vector<int> oper_used;
long long max_num = -2134567890, min_num = 2134567890;
vector<char> path;

long long calcu() {
	num_cpy = num;
	long long res = 0;
	for (int i = 1; i <= (N - 1); i++) {
		if (path[i - 1] == '+') num_cpy[i] = num_cpy[i - 1] + num_cpy[i];
		if (path[i - 1] == '-') num_cpy[i] = num_cpy[i - 1] - num_cpy[i];
		if (path[i - 1] == '*') num_cpy[i] = num_cpy[i - 1] * num_cpy[i];
		if (path[i - 1] == '/') num_cpy[i] = num_cpy[i - 1] / num_cpy[i];
		res = num_cpy[i];
	}
	return res;
}

void backtracking(int lv) {
	if (lv >= (N - 1)) {
		long long res = calcu();
		if (res > max_num) max_num = res;
		if (res < min_num) min_num = res;
		return;
	}
	for (int i = 0; i < (N - 1); i++) {
		if (oper_used[i])continue;
		path.push_back(oper[i]);
		oper_used[i] = 1;
		backtracking(lv + 1);
		path.pop_back();
		oper_used[i] = 0;
	}
}

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int nn = 0;
		cin >> nn;
		num.push_back(nn);
	}
	for (int i = 0; i < 4; i++) {
		int nn = 0;
		cin >> nn;
		for (int j = 0; j < nn; j++) {
			if (i == 0) oper.push_back('+');
			if (i == 1) oper.push_back('-');
			if (i == 2) oper.push_back('*');
			if (i == 3) oper.push_back('/');
			oper_used.push_back(0);
		}
	}

	backtracking(0);

	cout << max_num << "\n" << min_num;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}