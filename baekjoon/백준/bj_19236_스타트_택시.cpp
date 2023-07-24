/*

N��N ũ���� ����
�� ĭ�� ��ĭ(0) or ��(1)

if (�ýð� ��ĭ�� ���� ��,) than �����¿�� ������ ��ĭ �� �ϳ��� �̵�
�ִ� ��η� ������ ��ĭ �̵�

M���� �°��� ��ĭ �� �ϳ�(�����)�� �� ������, �ٸ� ��ĭ �� �ϳ�(������)�� �̵��Ϸ��� �Ѵ�
���� �°��� ���� ž���ϴ� ���� ����.
�°����� ����� - ������ ������ �ִ�.
�� �°��� �¿� �������� �̵���Ű�� ���� M�� �ݺ��ؾ� �Ѵ�
�� �°��� ������ �������� ������, ����������� �ýÿ� Ż �� �ְ�, ������������ �ýÿ��� ���� �� �ִ�.

�¿� �°��� �� ���� ���� ��ġ���� �ִܰŸ��� ���� ª�� �°��� ����.
 if(�׷� �°��� ���� ���̸�) than ���� �� ��ȣ�� ���� ���� �°���
	if(�׷� �°��� ���� ���̸�) than ���� �� ��ȣ�� ���� ���� �°��� ����
�ýÿ� �°��� ���� ��ġ�� �� ������ �� �°������� �ִܰŸ��� 0�̴�.

����� �� ĭ �̵��� ������ 1��ŭ �Ҹ�
�� �°��� �������� ���������� �̵���Ű��, �� �°��� �¿� �̵��ϸ鼭 �Ҹ��� ���� ���� �� �谡 �����ȴ�.

�̵��ϴ� ���߿� ���ᰡ �ٴڳ��� �̵��� �����ϰ�, �� ���� ������ ������
�°��� �������� �̵���Ų ���ÿ� ���ᰡ �ٴڳ��� ���� ������ ������ �������� �ʴ´�.
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FOR(box,start,end)  for(register int box = start; box < end; ++box)
#define dummy 2134567890

int N, M;
int map[21][21];
struct Taxi {
	int y;
	int x;
	int fuel;
	int goal_num;
};
Taxi taxi_driver;
struct Client {
	int start_y;
	int start_x;
	int goal_y;
	int goal_x;
	bool isGoal = false;
};
Client cli_list[410];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
struct Node {
	int y;
	int x;
};
struct Info {
	int dist;
	int y;
	int x;
	int cli_num;
};

void input() {
	cin >> N >> M >> taxi_driver.fuel;
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			cin >> map[y][x];
		}
	}
	cin >> taxi_driver.y >> taxi_driver.x;
	FOR(num, 2, (2 + M)) {
		cin >> cli_list[num].start_y >> cli_list[num].start_x >> cli_list[num].goal_y >> cli_list[num].goal_x;
		map[cli_list[num].start_y][cli_list[num].start_x] = num;
	}
}
void cpy_map(int (*cp_map)[21]) {
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			cp_map[y][x] = map[y][x];
		}
	}
}
void init_used(int(*cp_map)[21]) {
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			cp_map[y][x] = -1;
		}
	}
}
void pick_up_cli(int ty, int tx, int cost_fuel) {
	taxi_driver.y = ty;
	taxi_driver.x = tx;
	taxi_driver.fuel -= cost_fuel;
	taxi_driver.goal_num = map[ty][tx];
	map[ty][tx] = 0;
}
bool info_cmp(Info left, Info right) {
	if (left.dist <= right.dist) {
		if (left.dist == right.dist) {
			if (left.y <= right.y) {
				if (left.y == right.y) {
					if (left.x < right.x) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
bool find_cli() {
	int used[21][21] = { 0, };
	init_used(used);

	//int cost_fuel_taxiToCli = 0; // �ý� - �°� �̵��� �ʿ��� ����

	if (map[taxi_driver.y][taxi_driver.x] > 1) { // �ý� ��ġ�� ��ĭ�� �ƴϰ�, ���� �ƴ� = �°���ġ��
		pick_up_cli(taxi_driver.y, taxi_driver.x, 0); // �°��� ������ �¿��.
		return true;
	}
	else if(map[taxi_driver.y][taxi_driver.x] == 0) { // �ý� ��� ��ġ�� ��ĭ�̸�
		queue<Node> q;
		q.push({ taxi_driver.y, taxi_driver.x });
		used[taxi_driver.y][taxi_driver.x] = 0;
		vector<Info> v;

		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			FOR(dir, 0, 4) {
				int ny = now.y + dy[dir];
				int nx = now.x + dx[dir];

				if (ny<1 || ny>N || nx<1 || nx>N)continue; // �� ���� �����
				if (map[ny][nx] == 1 || used[ny][nx] != -1)continue;//���̸� �̹� ������ ���̸�

				used[ny][nx] = used[now.y][now.x] + 1;

				if (map[ny][nx] >= 2) { // �°��� �����ٸ�
					v.push_back({ used[ny][nx],ny,nx,map[ny][nx] });
				}
				else q.push({ ny,nx });
			}
		}

		if (v.size() == 0) return false;
		sort(v.begin(), v.end(), info_cmp);
		if (v[0].dist <= taxi_driver.fuel) { // �մ���ġ�� �̵��� ���ᰡ ����������
			pick_up_cli(v[0].y, v[0].x, used[v[0].y][v[0].x]); // �°��� ������ �¿��.
			return true;
		}
		else { // ������
			return false;
		}
	}
}
int find_goal() {
	int used[21][21] = { 0, };
	init_used(used);

	queue<Node> q;
	q.push({ taxi_driver.y, taxi_driver.x });
	used[taxi_driver.y][taxi_driver.x] = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		FOR(dir, 0, 4) {
			int ny = now.y + dy[dir];
			int nx = now.x + dx[dir];

			if (ny<1 || ny>N || nx<1 || nx>N)continue; // �� ���� �����
			if (map[ny][nx] == 1 || used[ny][nx] != -1)continue;//���̸� �̹� ������ ���̸�

			used[ny][nx] = used[now.y][now.x] + 1;

			if ((ny == cli_list[taxi_driver.goal_num].goal_y) && (nx == cli_list[taxi_driver.goal_num].goal_x)) { // ������ ã�Ҵٸ�
				//��ŸƮ �ýô� 
				if (used[ny][nx] <= taxi_driver.fuel) { // �մ��� �������� �������ָ�
					// ���� ���� 2��
					taxi_driver.fuel += used[ny][nx];
					taxi_driver.goal_num = 0;
					taxi_driver.y = ny;
					taxi_driver.x = nx;

					return true;
				}
				else { // ������
					return false;
				}
				/*
				if (�մ��� �������� �������ָ�) than ���ᰡ ����
				if (���ᰡ �ٴڳ���) than �� �� ������ ������.
				*/

				//return;
			}
			q.push({ ny,nx });
		}
	}

	return false;
}
void output() {

}
void sol() {

	FOR(cliNum, 0, M) { // �ý� ���� ���� M���� �°��� �¿�� ���� ��ǥ
		if (find_cli() == true) { // ���� ����� �°� ã�Ƽ� �¿��
			if (find_goal() == true) { // �������� �̵� ����
				if ((M - 1) == cliNum)cout << taxi_driver.fuel;
			}
			else {
				cout << -1;
				break;
			}
		}
		else {
			cout << -1;
			break;
		}
	}
	
	int de = 1;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	sol();
	return 0;
}