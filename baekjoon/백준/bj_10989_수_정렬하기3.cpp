#include <iostream>
using namespace std;

int N;
int arr[10001];

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int index = 0;
		cin >> index;
		arr[index]++;
	}
	
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
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