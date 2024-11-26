#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

void solution() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num = 0;
		cin >> num; 
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long ans = v[0] * v[v.size() - 1];

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}