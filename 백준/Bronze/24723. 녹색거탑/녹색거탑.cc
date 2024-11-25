#include <iostream>
#include <math.h>
using namespace std;

int N;

void solution() {
	cin >> N;
	cout << pow(2, N);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}