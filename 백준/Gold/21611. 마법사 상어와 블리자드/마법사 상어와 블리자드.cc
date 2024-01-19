#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define N_MAX 60
#define FOR(i,s,e) for(register int i=s; i<e; ++i)

int N, M;
int map[N_MAX][N_MAX];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };
int ball_list[N_MAX * N_MAX];

void ice_fragments(int d, int s) {
	int sy = ((N + 1) / 2);
	int sx = ((N + 1) / 2);

	int ny = sy;
	int nx = sx;
	FOR(i, 0, s) {
		ny = ny + dy[d];
		nx = nx + dx[d];

		if (map[ny][nx] == 0) break;
		if (ny < 1 || ny > N || nx < 1 || nx > N) break;

		map[ny][nx] = 0;
	}
}

int ry[4] = { 0,1,0,-1 };
int rx[4] = { -1,0,1,0 };

vector<int> dimension_down() {
	int sy = ((N + 1) / 2);
	int sx = ((N + 1) / 2);

	int ny = sy;
	int nx = sx;
	int d = 0;
	int s = 1;

	vector<int> v;

	FOR(r, 1, (N + 1)) {
		if (r == N) {
			FOR(j, 0, s) {
				ny = ny + ry[d];
				nx = nx + rx[d];

				if (map[ny][nx] != 0) {
					v.push_back(map[ny][nx]);
				}
			}
			++d;
			if (d == 4) d = 0;
		}
		else {
			FOR(i, 0, 2) {
				FOR(j, 0, s) {
					ny = ny + ry[d];
					nx = nx + rx[d];

					if (map[ny][nx] != 0) {
						v.push_back(map[ny][nx]);
					}
				}
				++d;
				if (d == 4) d = 0;
			}
			++s;
		}
	}

	return v;
}

void dimension_up(vector<int> v) {
	int tmp[N_MAX][N_MAX] = { 0, };
	int sy = ((N + 1) / 2);
	int sx = ((N + 1) / 2);

	int ny = sy;
	int nx = sx;
	int d = 0;
	int s = 1;
	int idx = 0;

	FOR(r, 1, (N + 1)) {
		if (r == N) {
			FOR(j, 0, s) {
				ny = ny + ry[d];
				nx = nx + rx[d];

				//test[ny][nx] = d; // 여기 포인터
				if (idx >= v.size()) break;
				tmp[ny][nx] = v[idx++];
				/*if (idx >= v.size()) tmp[ny][nx] = 0;
				else tmp[ny][nx] = v[idx++];*/
				//
			}
			++d;
			if (d == 4) d = 0;
		}
		else {
			FOR(i, 0, 2) {
				FOR(j, 0, s) {
					ny = ny + ry[d];
					nx = nx + rx[d];

					//test[ny][nx] = d; // 여기 포인터
					if (idx >= v.size()) break;
					tmp[ny][nx] = v[idx++];
					/*if (idx >= v.size()) tmp[ny][nx] = 0;
					else tmp[ny][nx] = v[idx++];*/
					//
				}
				if (idx >= v.size()) break;
				++d;
				if (d == 4) d = 0;
			}
			++s;
		}
		if (idx >= v.size()) break;
	}

	memcpy(map, tmp, sizeof(map));
}

bool is_bomb(vector<int> v) {
	if (v.size() == 0) return false;
	int cnt = 1;
	int prev = v[0];
	FOR(i, 1, v.size()) {
		if (cnt >= 4) return true;
		if (prev == v[i]) {
			++cnt;
		}
		else if (prev != v[i]) {
			prev = v[i];
			cnt = 1;
		}
	}
	if (cnt >= 4) return true;
	else return false;
}

vector<int> change_ball(vector<int> v) {
	vector<int> tmp;
	tmp = vector<int>(((N * N) - 1), 0);

	if (v.size() > 0) {
		vector<int> a;
		int idx = 0;
		int prev = v[0];

		a.push_back(v[0]);
		FOR(i, 1, v.size()) {
			if (idx >= ((N * N) - 1)) break;
			if (prev == v[i]) {
				a.push_back(v[i]);
			}
			else if (prev != v[i]) {
				/*tmp.push_back(a.size());
				tmp.push_back(prev);*/
				tmp[idx++] = a.size();
				tmp[idx++] = prev;
				prev = v[i];
				a.clear();
				a.push_back(v[i]);

			}
		}
		if (idx < ((N * N) - 1)) {
			/*tmp.push_back(a.size());
			tmp.push_back(prev);*/
			tmp[idx++] = a.size();
			tmp[idx++] = prev;
		}
	}

	return tmp;
}

void sort_ball() {
	vector<int> v;

	vector<int> tmp = dimension_down();
	//if (tmp.size() == 0) return; // 구슬없으면 정렬 필요 x
	FOR(i, 0, tmp.size()) {
		if (tmp[i] != 0) v.push_back(tmp[i]);
	}

	//bool flag = is_bomb(tmp);
	vector<int> a;
	vector<int> b;
	while (is_bomb(tmp)) { // 4개 이상 연속있으면 반복
		if (tmp.size() == 0) break;
		int prev = tmp[0];
		a.push_back(prev);
		FOR(i, 1, tmp.size()) {
			if (prev == tmp[i]) {
				a.push_back(tmp[i]);
			}
			else if (prev != tmp[i]) {
				if (a.size() >= 4) {
					ball_list[a[0]] += a.size();
				}
				else {
					b.insert(b.end(), a.begin(), a.end());
				}
				a.clear();
				prev = tmp[i];
				a.push_back(tmp[i]);
			}
		}
		if (a.size() >= 4) {
			ball_list[a[0]] += a.size();
		}
		else {
			b.insert(b.end(), a.begin(), a.end());
		}
		tmp = b;
		a.clear();
		b.clear();
	}

	tmp = change_ball(tmp);

	dimension_up(tmp);
}


void sol() {
	cin >> N >> M;
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			cin >> map[y][x];
		}
	}

	FOR(i, 0, M) {
		int d = 0, s = 0;
		cin >> d >> s;

		ice_fragments(d, s);
		sort_ball();

		/*FOR(y, 1, (N + 1)) {
			FOR(x, 1, (N + 1)) {
				cout << map[y][x] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/
	}

	int sum = 0;
	sum = (1 * ball_list[1]) + (2 * ball_list[2]) + (3 * ball_list[3]);
	cout << sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}