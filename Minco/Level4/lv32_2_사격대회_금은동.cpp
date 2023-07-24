#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Player
{
	string name;
	int score;
};
int N;
vector <Player> v;


void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		Player t = { "", 0 };
		cin >> t.name >> t.score;
		v.push_back(t);
	}
}

void output() {
	
}

void sort() {
	for (int i = 1; i < v.size(); i++) {
		Player temp = v[i];
		int j = 0;
		int flag = 0;
		for (j = i - 1; j >= 0; j--) {

			if (temp.score >= v[j].score) {
				v[j + 1] = v[j];
			}
			else {
				break;
			}
		}
		v[j+1] = temp;
		
		if (i < 3) {
			for (int k = 0; k <= i; k++) {
				cout << v[k].name << " ";
			}
		}
		else if (i >= 3) {
			for (int k = 0; k < 3; k++) {
				cout << v[k].name << " ";
			}
		}
		cout << "\n";
	}
}

void sol() {
	input();
	cout << v[0].name << '\n';
	sort();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}