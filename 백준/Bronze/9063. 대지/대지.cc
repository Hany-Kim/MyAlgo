#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int minY = INT_MAX, minX = INT_MAX;
int maxY = INT_MIN, maxX = INT_MIN;

void sol() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int y = 0, x = 0;
		cin >> y >> x;
		minY = min(y, minY);
		minX = min(x, minX);
		maxY = max(y, maxY);
		maxX = max(x, maxX);
	}

	int ans = (maxY - minY) * (maxX - minX);
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}