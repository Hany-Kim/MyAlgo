#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
struct Record {
	int n;
	int th;
};
vector<Record> v;
vector<Record> vt;

bool operator<(Record left, Record right) {
	if (left.n > right.n) return false;
	if (left.n < right.n) return true;

	return false;
}

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		Record r = { 0,0 };
		cin >> r.n;
		v.push_back(r);
		vt.push_back(r);
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if ((i>0) &&(v[i].n == v[i - 1].n)) {
			v[i].th = v[i - 1].th;
			continue;
		}
		v[i].th = cnt;
		cnt++;
	}
	for (int i = 0; i < vt.size(); i++) {

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