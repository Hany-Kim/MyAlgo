#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> s;

void sol() {
	long long int n1 = 0, n2 = 0;
	long long int n3 = 0, n4 = 0;
	cin >> n1 >> n2 >> n3 >> n4;

	long long int times = 1;
	long long int num = 0;
	while (true) {
		num = n2 * times;

		if (num % n4 == 0) {
			break;
		}
		times++;
	}

	n1 = n1 * (num / n2);
	n3 = n3 * (num / n4);

	n1 = n1 + n3;
	
	int a1 = n1, a2 = num;
	int minN = min(a1, a2);
	int maxN = max(a1, a2);

	bool isRev = 0;
	if (minN == a2 && maxN == a1) isRev = true;

	for (int i = 1; i <= minN; ++i) {
		if(minN % i == 0) s.insert(i);
	}

	for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
		if (*itr == 1) continue;

		while (true) {
			if (minN % (*itr) == 0 && maxN % (*itr) == 0) {
				minN /= (*itr);
				maxN /= (*itr);
			}
			else break;
		}
	}

	if (isRev) cout << maxN << " " << minN;
	else cout << minN << " " << maxN;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}