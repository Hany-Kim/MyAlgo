#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, S, M;
vector <string> book;

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name = "";
		cin >> name;
		book.push_back(name);
	}
	sort(book.begin(), book.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		string target = "";
		cin >> target >> S;
		int start = 0;
		int last = book.size() - 1;
		while (1) {
			if (S < 1) {
				cout << "fail\n";
				break;
			}
			S--;
			int mid = (start + last) / 2;
			if (start > mid) {
				cout << "fail\n";
				break;
			}

			if (book[mid] == target) {
				cout << "pass\n";
				break;
			}

			if (book[mid] < target) {
				start = mid + 1;
			}

			if (book[mid] > target) {
				last = mid - 1;
			}
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