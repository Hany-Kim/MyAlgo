/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

#define MAX_SIZE 12

#define FOR(v,s,e) for(register int v = (s); v<(e); ++v)

int N;
int map[MAX_SIZE][MAX_SIZE];
struct Node {
	int y, x;
};
Node cell[12];
int cellCnt;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int ans;
int max_core_cnt;

void init() {
	cellCnt = 0;
	FOR(i, 0, 12) cell[i] = { 0,0 };
	FOR(y, 0, N) {
		FOR(x, 0, N) {
			map[y][x] = 0;
		}
	}
	ans = 2134567890;
	max_core_cnt = 0;
}

void dfs(int cellNum, int edgeLen, int coreCnt) {
	if (cellNum == cellCnt) {
		if (coreCnt > max_core_cnt) {
			max_core_cnt = coreCnt;
			ans = edgeLen;
		}
		else if (coreCnt == max_core_cnt && edgeLen < ans) {
			ans = edgeLen;
		}
		return;
	}

	FOR(dir, 0, 4) {
		Node now = cell[cellNum];
		int ny = now.y;
		int nx = now.x;
		int len = 0;

		bool flag = false;
		while (1) {
			if (ny == 0 || ny == N - 1 || nx == 0 || nx == N - 1) {
				flag = true;
				break;
			}
			ny += dy[dir];
			nx += dx[dir];
			++len;
			if (map[ny][nx] == 1 || map[ny][nx] == 2) break;
		}

		if (flag) { // ������ �������� �Ǵ�
			ny = now.y;
			nx = now.x;
			FOR(i, 0, len) {
				ny += dy[dir];
				nx += dx[dir];
				map[ny][nx] = 2;
			}
			dfs(cellNum + 1, edgeLen + len, coreCnt + 1);
			FOR(i, 0, len) {
				map[ny][nx] = 0;
				ny -= dy[dir];
				nx -= dx[dir];
			}
		}
	}
	dfs(cellNum + 1, edgeLen, coreCnt);
}

void sol() {
	cin >> N;
	init();
	FOR(y, 0, N) FOR(x, 0, N) {
		cin >> map[y][x];

		// �����ڸ�
		if (y == 0) continue;
		if (x == 0) continue;
		if (y == N - 1) continue;
		if (x == N - 1) continue;

		if (map[y][x] == 1) cell[cellCnt++] = { y,x };
	}

	int cellNum = 0; // ���° �ھ�
	int edgeLen = 0; // ���� ����
	int coreCnt = 0; // �ھ� ��
	dfs(cellNum, edgeLen, coreCnt);

	cout << ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		cout << "#" << test_case << " ";
		sol();
		cout << '\n';
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}