#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector <string> server;
int start1, end1;
int y, x;

void run(int s, int e, int m) {
	int mid = (s + e) / 2;
	if (s == e) {
		x = mid;
		return;
	}
	if (server[m][mid] == '#') {
		run(mid + 1, e, m);
	}
	if (server[m][mid] == '0') {
		run(s, mid - 1, m);
	}
}

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string t = "";
		cin >> t;
		server.push_back(t);
	}
	int s = 0;
	int e = N - 1;
	end1 = N - 1;
	while (1) {
		int mid = (s + e) / 2;
		if (s > mid) {
			break;
		}
		
		if (server[mid][0] == '#' && server[mid][N-1] == '0') {
			int start = 0;
			int last = N - 1;
			y = mid;
			run(start, last, mid);
			break;
		}

		if (server[mid][N-1] == '#') {
			s = mid + 1;
		}
		if (server[mid][0] == '0') {
			e = mid - 1;
		}
	}
	cout << y << " " << x;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();
	return 0;
}