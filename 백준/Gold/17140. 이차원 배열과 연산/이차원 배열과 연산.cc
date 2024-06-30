#include <iostream>
#include <vector>
using namespace std;

int r, c, k;
vector<vector<int>> Arr(101, vector<int>(101));
int r_num = 4;
int c_num = 4;
int myTime;
vector<vector<int>> cpy;

void R_calc() {
	int c_max = 0; // R연산 수행시 최대 열 길이;
	for (int y = 1; y < r_num; y++) {
		vector<int> tmp;
		tmp.push_back(0); // 인덱스 1부터
		int myMax = 0; // cnt 최대 갯수
		int cnt[101] = { 0, };
		for (int x = 1; x < c_num; x++) {
			cnt[Arr[y][x]]++;
			if (cnt[Arr[y][x]] > myMax) myMax = cnt[Arr[y][x]];
		}
		for (int i = 1; i <= myMax; i++) {
			for (int j = 1; j <= 100; j++) {
				if (cnt[j] == i) {
					tmp.push_back(j);
					tmp.push_back(i);
				}
			}
		}
		if (tmp.size() > c_max) c_max = tmp.size();
		cpy.push_back(tmp);
	}

	for (int y = 1; y < cpy.size(); y++) {
		if (cpy[y].size() < c_max) {
			int diff = c_max - cpy[y].size();
			for (int i = 0; i < diff; i++) {
				cpy[y].push_back(0);
			}
		}
	}

	c_num = c_max;
	Arr = vector<vector<int>>(101, vector<int>(101));
	for (int y = 0; y < cpy.size(); y++) {
		for (int x = 0; x < cpy[y].size(); x++) {
			Arr[y][x] = cpy[y][x];
		}
	}
}
void C_calc() {
	int r_max = 0; // C연산 수행시 최대 행 길이;
	for (int x = 1; x < c_num; x++) {
		vector<int> tmp;
		tmp.push_back(0); // 인덱스 1부터
		int myMax = 0; // cnt 최대 갯수
		int cnt[101] = { 0, };
		for (int y = 1; y < r_num; y++) {
			cnt[Arr[y][x]]++;
			if (cnt[Arr[y][x]] > myMax) myMax = cnt[Arr[y][x]];
		}
		for (int i = 1; i <= myMax; i++) {
			for (int j = 1; j <= 100; j++) {
				if (cnt[j] == i) {
					tmp.push_back(j);
					tmp.push_back(i);
				}
			}
		}
		if (tmp.size() > r_max) r_max = tmp.size();
		cpy.push_back(tmp);
	}

	for (int y = 1; y < cpy.size(); y++) {
		if (cpy[y].size() < r_max) {
			int diff = r_max - cpy[y].size();
			for (int i = 0; i < diff; i++) {
				cpy[y].push_back(0);
			}
		}
	}

	r_num = r_max;
	Arr = vector<vector<int>>(101, vector<int>(101));
	for (int y = 0; y < cpy.size(); y++) {
		for (int x = 0; x < cpy[y].size(); x++) {
			Arr[x][y] = cpy[y][x];
		}
	}
}
void sol() {
	cin >> r >> c >> k;
	for (int y = 1; y <= 3; y++) {
		for (int x = 1; x <= 3; x++) {
			cin >> Arr[y][x];
		}
	}
	int flag = 0;
	while (1) {
		cpy = vector<vector<int>>(1, vector<int>(1));
		if (Arr[r][c] == k) break;
		if (myTime > 100) {
			flag = 1;
			break;
		}
		if (r_num >= c_num) R_calc();
		else if (r_num < c_num) C_calc();
		cpy.clear();

		/*cout << "r: " << r_num << " c: " << c_num << '\n';
		for (int y = 0; y < Arr.size(); y++) {
			for (int x = 0; x < Arr[y].size(); x++) {
				cout << Arr[y][x] << ' ';
			}
			cout << '\n';
		}*/
		myTime++;
	}
	if (flag) cout << -1;
	else cout << myTime;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}