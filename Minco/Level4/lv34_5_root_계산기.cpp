#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int n, new_num;
int s = 1, e;

void sol() {
	cin >> n;
	e = n;
	while (1) {
		int mid = (s + e) / 2;
		if (pow(mid, 2) <= n && pow(mid + 1, 2) > n) {
			cout << mid;
			break;
		}
		if (pow(mid, 2) > n) {
			e = mid;
		}
		if (pow(mid, 2) < n) {
			s++;
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