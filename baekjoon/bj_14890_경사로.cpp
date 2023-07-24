#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N,L;
int map[100][100];
int cnt;
int ans;

bool whole_same_chk(vector<int> arr) {
	int flag = 0;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i - 1] != arr[i]) {
			flag = 1;
			break;
		}
	}
	if (flag) return 0;
	else if (!flag) return 1;
}

void runway(vector<int> arr, vector<int> used) {
	int flag = 0;
	for (int i = 1; i < arr.size(); i++) {
		if (abs(arr[i - 1] - arr[i]) == 1) {
			if (arr[i - 1] < arr[i]) { // 왼쪽 경사로 설치
				int low_place = i - 1;
				while (1) {
					if ((low_place - 1) < 0) break;
					if (used[low_place - 1]) break;
					if (arr[low_place - 1] != arr[low_place]) break;
					low_place--;
				}
				if (L > (i - 1 - low_place + 1)) flag = 1;
				else if (L <= (i - 1 - low_place + 1)) {
					for (int j = (i - 1); j >= (i - 1 - L + 1); j--) {
						//if (!used[j]) used[j] += 1;
						used[j] += 1;
					}
				}
			}
			else if (arr[i - 1] > arr[i]) { // 오른쪽 경사로 설치
				int low_place = i;
				while (1) {
					if ((low_place + 1) >= N) break;
					if (used[low_place]) break;
					if (arr[low_place + 1] != arr[low_place]) break;
					low_place++;
				}
				if (L > (low_place - i + 1)) flag = 1;
				else if (L <= (low_place - i + 1)) {
					for (int j = i; j <= (i + L - 1); j++) {
						//if (!used[j]) used[j] += 1;
						used[j] += 1;
					}
				}
			}
		}
		else if (abs(arr[i - 1] - arr[i]) >= 2) flag = 1;
		if (flag) break;
	}
	for (int i = 0; i < used.size(); i++) {
		if (used[i] >= 2) flag = 1;
	}
	if (!flag) cnt++;
}

void possible(int idx) {
	vector<int> row;
	vector<int> col;
	vector<int> r_used;
	vector<int> c_used;
	for (int i = 0; i < N; i++) {
		row.push_back(map[idx][i]);
		col.push_back(map[i][idx]);
		r_used.push_back(0);
		c_used.push_back(0);
	}

	if (whole_same_chk(row)) cnt++;
	else runway(row, r_used);

	if (whole_same_chk(col)) cnt++;
	else runway(col, c_used);

}

void sol() {
	cin >> N >> L;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	for (int i = 0; i < N; i++) {
		possible(i);
	}
	cout << cnt;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}