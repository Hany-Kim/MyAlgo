#include <iostream>
#include <algorithm>
using namespace std;

string str;
int N;
int arr[26][200000];

void solution() {
	cin >> str >> N;

	for (int j = 0; j < str.size(); ++j) {
		char now = str[j];
		int idx = int(now - 'a');

		for (int i = 0; i < 26; ++i) {
			if (idx == i) {
				arr[i][j] += 1;
			}
			if(j != 0) arr[i][j] += arr[i][j - 1];
		}
	}
	for (int i = 0; i < N; ++i) {
		char alpha = ' ';
		int s = 0, e = 0;
		cin >> alpha >> s >> e;

		int idx = int(alpha - 'a');
		if (s == 0) cout << arr[idx][e] << '\n';
		else cout << arr[idx][e] - arr[idx][s - 1] << '\n';
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}