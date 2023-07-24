#include <iostream>
#include <vector>
using namespace std;

struct NC
{
	int n;
	char ch;
};
int num;
vector <NC> v;

void input() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		NC t = { 0, ' ' };
		cin >> t.n >> t.ch;
		v.push_back(t);
	}
}

void sort() {
	for (int i = 0; i < v.size()-1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].n > v[j].n) {
				NC temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
			else if (v[i].n == v[j].n) {
				if (v[i].ch > v[j].ch) {
					NC temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
		}
	}
}

void output() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].n << " " << v[i].ch << '\n';
	}
}

void sol() {
	input();
	sort();
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