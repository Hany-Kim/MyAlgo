#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> arr1;
priority_queue<int, vector<int>, greater<int>> arr2;
int arr1_idx, arr2_idx;
int newArr[8];
int temp;

void input() {
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		arr1.push(temp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		arr2.push(temp);
	}
}

int compare() {
	if ((arr1.top() > arr2.top()) || (arr2.empty() == 1)) {
		temp = arr2.top();
		arr2.pop();
	}
	else if ((arr1.top() <= arr2.top()) || (arr1.empty() == 1)) {
		temp = arr1.top();
		arr1.pop();
	}
	return temp;
}

void new_arr() {
	for (int i = 0; i < 8; i++) {
		newArr[i] = compare();
		cout << newArr[i] << " ";
	}
}

void solution() {
	input();
	new_arr();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}