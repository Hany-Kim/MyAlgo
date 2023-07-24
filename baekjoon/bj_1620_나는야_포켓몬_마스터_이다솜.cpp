#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
string dogam[100001];
map<string, int> pocketmon;

void sol() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> dogam[i];
		pocketmon.insert(make_pair(dogam[i],i));
	}
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if ((temp[0] >= '0') && (temp[0] <= '9')) {
			cout << dogam[stoi(temp)] << '\n';
		}
		else {
			cout << pocketmon[temp] << '\n';
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