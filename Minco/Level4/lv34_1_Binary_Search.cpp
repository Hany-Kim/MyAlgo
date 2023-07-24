#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10] = {
	4,4,5,7,8,10,20,22,23,24
};
int n;
int s, e = 9;

void run(int s, int e) {
	int mid = (s + e) / 2;
	
	if (s > e) {
		cout << "X";
		return;
	}

	if (arr[mid] == n) {
		cout << 'O';
		return;
	}
	
	if (arr[mid] < n) {
		run(mid + 1, e);
	}

	if (arr[mid] > n) {
		run(s, mid - 1);
	}

}

void sol() {
	cin >> n;
	run(s, e);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();
	return 0;
}