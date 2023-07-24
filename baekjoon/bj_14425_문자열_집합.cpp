#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
string N_zip[10000];
int cnt;

void sol() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> N_zip[i];
	}

	sort(N_zip, N_zip + N);

	for (int i = 0; i < M; i++) {
		string temp = "";
		cin >> temp;
		int s = 0;
		int e = N - 1;
		while (1) {
			int mid = (s + e) / 2;
			if (s > e) break;
			if (N_zip[mid] == temp) {
				cnt++;
				break;
			}
			else if (N_zip[mid] > temp) {
				e = mid - 1;
			}
			else if (N_zip[mid] < temp) {
				s = mid + 1;
			}
		}
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