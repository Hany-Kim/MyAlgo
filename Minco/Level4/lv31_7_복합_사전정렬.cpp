#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector <string> v;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t = "";
		cin >> t;
		v.push_back(t);
	}
}

void v_sort() {
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++) {
			if (v[i].size() > v[j].size()) {
				string temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
			else if (v[i].size() == v[j].size()) {
				int flag = 0;
				for (int k = 0; k < v[i].size(); k++) {
					if (v[i][k] != v[j][k]) {
						flag = 1;
						if (v[i][k] > v[j][k]) {
							string temp = v[i];
							v[i] = v[j];
							v[j] = temp;
						}
					}
					if (flag) break;
				}
			}
		}
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n';
	}
}

void sol() {
	input();
	v_sort();
	output();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}