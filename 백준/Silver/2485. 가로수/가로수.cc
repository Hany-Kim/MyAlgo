#include <iostream>
#include <set>
using namespace std;

int n;
set<int> s;
int arr[100000];

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (i > 0) {
			s.insert(arr[i] - arr[i - 1]);
		}
	}

	int num = 0;
	for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
		num = *itr;
		break;
	}
	for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
		if (num == *itr) continue;
		num = gcd(num, *itr);
	}
	
	int cnt = 0;
	for (int i = arr[0]; i <= arr[n - 1]; i+=num) {
		cnt += 1;
	}

	int ans = cnt - n;
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}