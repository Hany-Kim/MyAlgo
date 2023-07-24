#include <iostream>
#include <cmath>
using namespace std;

/*
ĭ���� �� �ִ� �� ���� ������� �� �ִ�. ���� ũ��� �ӵ��� ������ �ִ�.
���ÿ��� ó���� 1�� ���� �� ĭ ���ʿ� �ִ�.
���ÿ��� ���� ������ ���� ������ ĭ�� �̵��ϸ� �̵��� �����.

���ÿ��� ó���� 1�� ���� �� ĭ ���ʿ� �ִ�.
������ 1�� ���� �Ͼ�� ���̸�, �Ʒ� ���� ������� �Ͼ��.
���ÿ��� ���� ������ ���� ������ ĭ�� �̵��ϸ� �̵��� �����.
1. ���ÿ��� ���������� �� ĭ �̵��Ѵ�.
2. ���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�.
�� ������ �����ǿ��� ���� �� �������.
3. �� �̵��Ѵ�.

*/
int R, C, M;
struct Shark {
	int s; // �ӷ�
	int d; // �̵�����
	int z; // ũ��
};
Shark map[102][102];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,1,-1 };
struct Hunt {
	int y;
	int x;
};
Hunt hunter = { 0,0 }; //���ÿ��� ó���� 1�� ���� �� ĭ ���ʿ� �ִ�.
int sum;

void input() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int y = 0, x = 0, s = 0, d = 0, z = 0;
		cin >> y >> x >> s >> d >> z;
		map[y][x] = { s,d,z };
	}
}
void move_shark() {
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (map[y][x].z) {
				int ny = y + (dy[map[y][x].d] * map[y][x].s);
				int nx = x + (dx[map[y][x].d] * map[y][x].s);
				if (ny < 1) {
					ny = abs(ny - 2);
					map[y][x].d = 2;
				}
				else if (nx < 1) {
					nx = abs(nx - 2);
					map[y][x].d = 3;
				}
				else if (ny > R) {
					ny = R + ((ny - R) * -1);
					map[y][x].d = 1;
				}
				else if (nx > C) {
					nx = C + ((nx - C) * -1);
					map[y][x].d = 4;
				}

				if (map[ny][nx].z) { // �̵��� ���� �� ������
					if (map[y][x].z > map[ny][nx].z) {// ��� �Դ´�.
						map[ny][nx].s = map[y][x].s;
						map[ny][nx].d = map[y][x].d;
						map[ny][nx].z = map[y][x].z;
						map[y][x] = { 0,0,0 };
					}
					else if (map[y][x].z < map[ny][nx].z) {// ��� ������.
						map[y][x] = { 0,0,0 };
					}
				}
				else {
					map[ny][nx].s = map[y][x].s;
					map[ny][nx].d = map[y][x].d;
					map[ny][nx].z = map[y][x].z;
					map[y][x] = { 0,0,0 };
				}
			}
		}
	}
}
void sol() {
	input();
	while (1) {
		++hunter.x;
		if (hunter.x == C + 1) break;

		for (int y = 1; y <= R; y++) {
			if (map[y][hunter.x].z) {
				sum += map[y][hunter.x].z;
				map[y][hunter.x] = { 0,0,0 };
				break;
			}
		}

		move_shark();

	}
	cout << sum;
	int de = 1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}