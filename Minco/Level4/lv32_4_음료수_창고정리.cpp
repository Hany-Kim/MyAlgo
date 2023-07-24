#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> line;
int used[5];
vector <int> slice[5];

void input() {
	for (int i = 0; i < 5; i++) {
		string t = "";
		cin >> t;
		line.push_back(t);
	}
	for (int i = 0; i < 2; i++) {
		int n = 0;
		cin >> n;
		used[n] = 1;
	}
}

void sol() {
	input();
	for (int i = 0; i < 5; i++) {
		int len = line[i].length();
		int num = stoi(line[i]);
		for (int j = 0; j < len; j++) {
			int temp = num % 10;
			slice[i].push_back(temp);
			num = num / 10;
		}

		if (used[i] == 1) {
			cout << slice[i][0] << " ";
		}
		else if (used[i] == 0) {
			cout << slice[i][slice[i].size() - 1] << " ";
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}