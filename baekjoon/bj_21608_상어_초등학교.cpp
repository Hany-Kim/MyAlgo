#include <iostream>
#include <vector>
#define MAX_SIT 21 // 교실 자릿수
#define MAX_STU 401 // 최대 학생 수
using namespace std;

int N;
//int classroom[MAX_SIT][MAX_SIT];
//int student[MAX_STU][5];
int classroom[4][4];
int student[9][5];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


void input() { 
	cin >> N;
	for (register int y = 0; y < (N * N); ++y) {
		for (register int x = 0; x < 5; ++x) {
			cin >> student[y][x];
		}
	}
}

bool first(int stu_num) {
	int check[9][9] = { 0, };

	int max_num = 0;

	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= N; ++x) {
			int cnt = 0;
			for (register int i = 0; i < 4; ++i) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny<1 || ny>N || nx<1 || nx>N)continue;
				if (classroom[ny][nx] == 0)continue;

				if (classroom[ny][nx] != 0) {
					for (register int num = 1; num < 5; ++num) {
						if (classroom[ny][nx] == student[stu_num][num]) ++cnt;
					}
				}
			}

			check[y][x] = cnt;

			if (max_num < cnt) max_num = cnt; // 만족하는 칸이 여러개인지 확인
		}
	}

	vector<pair<int, int>> v;

	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= N; ++x) {
			if (max_num == check[y][x]) v.push_back({ y,x });
		}
	}

	if (v.size() > 1) return true; // 1조건 만족하는게 여러개
	else if (v.size() == 1) return false; // 1조건 만족하는게 한개
}

bool second(int stu_num) {
	int check[9][9] = { 0, };

	int max_num = 0;

	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= N; ++x) {
			int cnt = 0;
			for (register int i = 0; i < 4; ++i) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny<1 || ny>N || nx<1 || nx>N)continue;

				if (classroom[ny][nx] == 0) ++cnt;
			}
			check[y][x] = cnt;

			if (max_num < cnt) max_num = cnt;
		}
	}

	vector<pair<int, int>> v;

	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= N; ++x) {
			if (max_num == check[y][x]) v.push_back({ y,x });
		}
	}

	if (v.size() > 1) return true; // 2조건 만족하는게 여러개
	else if (v.size() == 1) {
		classroom[v[0].first][v[0].second] = student[stu_num][0];
		return false; // 2조건 만족하는게 한개
	}
}

void third(int stu_num) {

}

void sol() {
	input();

	for (register int i = 0; i < (N * N); ++i) {
		if (first(i) == true) { // 1조건 만족하는게 여러개
			if (second(i) == true) { // 2조건 만족하는게 여러개
				third(i);
			}
			else {

			}

		}
		else { // 1조건 만족하는게 한개

		}

	}

	int de = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	sol();

	return 0;
}