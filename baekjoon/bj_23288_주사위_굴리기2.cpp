#include <iostream>

using namespace std;

// N x M ����

//ó�� �ֻ��� �̵� ������ "����"
//�ֻ����� �̵� �������� �� ĭ ��������.
// ����, �̵� ���⿡ ĭ�� ���ٸ�, �̵� ������ "�ݴ�"�� �� ���� �� ĭ ��������.
//�ֻ����� "������ ĭ(x, y)�� ���� ������ ȹ��"�Ѵ�.
//�ֻ��� �ٴڸ�(A) & ���� ��ǥ�� ���� �� ��(B)
//	A > B�� ��� �̵� ������ 90�� �ð� �������� ȸ����Ų��.
//	A < B�� ��� �̵� ������ 90�� �ݽð� �������� ȸ����Ų��.
//	A = B�� ��� �̵� ���⿡ ��ȭ�� ����.

int N, M, K;
int map[21][21];
int dice[4][3] = {
	0,2,0,
	4,1,3,
	0,5,0,
	0,6,0
};

void input() {
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> map[y][x];
		}
	}
}


void solution() {
	input();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}