#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <string> name;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		name.push_back(temp);
	}
}

void length_sort() {
	for (int i = 0; i < name.size() - 1; i++) {
		for (int j = i + 1; j < name.size(); j++) {
			if (name[i].length() > name[j].length()) {
				string temp = name[i];
				name[i] = name[j];
				name[j] = temp;
			}
		}
	}
}

void dic_sort() {
	int len = 0;
	int idx = 0;
	for (int i = 0; i < name.size(); i++) {
		if (len != name[i].length()) {
			sort(name.begin() + idx, name.begin() + i);
			idx = i;
		}
		if (i == name.size() - 1) {
			//sort(name.begin() + idx, name.begin() + i);
			sort(name.begin() + idx, name.end());
		}
		len = name[i].length();
	}
}

void sol() {
	input();
	//sort(name.begin(), name.end());
	length_sort();
	dic_sort();
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << "\n";
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