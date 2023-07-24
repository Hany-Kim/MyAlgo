#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, C;
struct Person
{
	int num;
	string name;
};

vector <vector <string>> vote;
int vote_max;

void input() {
	cin >> N >> C;
	vote = vector <vector <string>> (N, vector<string>());
	for (int i = 0; i < C; i++) {
		Person p = { 0, "" };
		cin >> p.num >> p.name;
		vote[p.num].push_back(p.name);
	}
}

void sol() {
	input();
	int idx = 0;
	for (int i = 0; i < N; i++) {
		if (vote[i].size() > vote_max) {
			vote_max = vote[i].size();
			idx = i;
		}
	}
	for (int i = 0; i < vote[idx].size(); i++) {
		cout << vote[idx][i] << ' ';
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