#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int A[11][11];
int map[11][11];
vector<int> tree[11][11];
int tree_cnt;
//  같은 1×1 크기의 칸에 여러 개의 나무가 심어져 있을 수도 있다.

void set_tree() {
	for (int i = 0; i < M; i++) {
		int x = 0, y = 0, z = 0;
		cin >> x >> y >> z;

		tree[x][y].push_back(z); // 나이 배치
	}
}

void spring() {
	/*
	봄
	나무가 자신의 나이만큼 양분을 먹고,
	나이가 1 증가한다.
	각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다.

	하나의 칸에 여러 개의 나무가 있다면,
	나이가 어린 나무부터 양분을 먹는다.

	만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는
	양분을 먹지 못하고 즉시 죽는다.
	*/
	for(int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (!tree[y][x].empty()) {
				int yang_bun = 0;
				vector<int> tmp;

				sort(tree[y][x].begin(), tree[y][x].end());
				for (int j = 0; j < tree[y][x].size(); j++) {
					if (map[y][x] >= tree[y][x][j]) {
						// 남은 양분이 나무 나이보다 많을 때
						map[y][x] = map[y][x] - tree[y][x][j]; // 나무가 자신의 나이만큼 양분을 먹고,
						tmp.push_back(tree[y][x][j] + 1); //나이가 1 증가한다.
					}
					else {
						// 남은 양분이 나무 나이보다 적을 때
						yang_bun = yang_bun + (tree[y][x][j] / 2);
					}
				}
				tree[y][x].clear();
				for (int k = 0; k < tmp.size(); k++) {
					tree[y][x].push_back(tmp[k]);
				}
				/*
				여름
				봄에 죽은 나무가 양분으로 변하게 된다.
				각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
				소수점 아래는 버린다.
				*/
				map[y][x] = map[y][x] + yang_bun; // 죽은 나무 양분 추가
			}
		}
	}
}

void summer() {

}

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
void autumn() {
	/*
	가을
	나무가 번식한다.
	번식하는 나무는 나이가 5의 배수이어야 하며,
	인접한 8개의 칸에 나이가 1인 나무가 생긴다.
	
	어떤 칸 (r, c)와 인접한 칸은 "상하좌우 대각"
	상도의 땅을 벗어나는 칸에는
	나무가 생기지 않는다
	*/

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (!tree[y][x].empty()) {
				for (int j = 0; j < tree[y][x].size(); j++) {
					if ((tree[y][x][j] % 5) == 0) { // 번식하는 나무는 나이가 5의 배수이어야 하며,
						for (int k = 0; k < 8; k++) { // 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
							int ny = y + dy[k];
							int nx = x + dx[k];

							if (ny < 1 || ny > N || nx < 1 || nx > N) continue; 
							//상도의 땅을 벗어나는 칸에는
							//나무가 생기지 않는다

							tree[ny][nx].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	/*
	겨울
	S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
	각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
	*/

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			map[y][x] = map[y][x] + A[y][x];
		}
	}
}

void counting_tree() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (!tree[y][x].empty()) {
				tree_cnt = tree_cnt + tree[y][x].size();
			}
		}
	}
}

void sol() {
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> A[y][x];
			// 가장 처음에 양분은 모든 칸에 5만큼 들어있다.
			map[y][x] = 5;
		}
	}
	set_tree();

	for (int year = 0; year < K; year++) {
		spring();
		summer();
		autumn();
		winter();
	}

	counting_tree();

	cout << tree_cnt;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}