#include <iostream>
#include <utility>
using namespace std;

// (x,y) (¸ö¹«°Ô, Å°)
int N;
pair<int,int> person[50];
int is_rank = 1;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> person[i].first >> person[i].second;
	}
}

void sol() {
	input();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (person[y].first < person[x].first && person[y].second < person[x].second) is_rank++;
		}
		cout << is_rank << ' ';
		is_rank = 1;
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