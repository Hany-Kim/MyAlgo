#include <iostream>
#include <vector>

using namespace std;

int N, M;
int uni[55];
vector<int> know_truth;
vector<int> party[55];
int ans;

void input() {
	cin >> N >> M;
	int K = 0;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a = 0;
		cin >> a;
		know_truth.push_back(a);
	}
	for (int i = 0; i < M; i++) {
		int num = 0;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int a = 0;
			cin >> a;
			party[i].push_back(a);
		}
	}
	ans = M;
}
int find(int a) {
	if (a == uni[a]) return a;
	return uni[a] = find(uni[a]);
}
void set_union(int a, int b) {
	a = find(a);
	b = find(b);
	uni[b] = a;
}
bool isSameUnion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return true;
	return false;
}
void sol() {
	input();

	for (int i = 1; i <= N; i++)
		uni[i] = i;
	for (int i = 0; i < M; i++) {
		int N1 = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			int N2 = party[i][j];
			set_union(N1, N2);
		}
	}

	for (int i = 0; i < M; i++) {
		bool Go_Party = true;
		for (int j = 0; j < party[i].size(); j++) {
			if (Go_Party == false) break;
			int N1 = party[i][j];
			for (int k = 0; i < know_truth.size(); k++) {
				int N2 = know_truth[k];
				if (isSameUnion(N1, N2) == true) {
					Go_Party = false;
					break;
				}
			}
		}
		if (Go_Party == false) ans--;
	}
	cout << ans << '\n';
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}