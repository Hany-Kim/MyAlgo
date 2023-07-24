#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N = 3;
	int K = 2;

	stack<int> s;

	int arr[3];

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	int start = 1;
	for (int i = 0; i < 3; i++) {
		s.push(arr[i]);
		if (start != arr[i]) continue;
		if (start == arr[i]) {

		}
	}
	

	int de = 1;
	return 0;
}