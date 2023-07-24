#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
struct Person
{
	int age;
	string name;
};
vector<vector<string>> v(201, vector<string>());

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		Person temp = { 0, "" };
		cin >> temp.age >> temp.name;
		v[temp.age].push_back(temp.name);
	}
	for (int i = 0; i < 201; i++) {
		if (v[i].size() > 0) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << i << ' ' << v[i][j] << '\n';
			}
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