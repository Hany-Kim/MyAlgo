#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr = {1,5,4,2,-5,-7};
int num;

void input() {
	cin >> num;
}

void arr_sort() {
	sort(arr.begin(), arr.end(), greater<>());
}

void find() {
	cout << arr[num-1];
}

void sol() {
	input();
	arr_sort();
	find();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}