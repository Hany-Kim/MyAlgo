#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int dat[5][8];
int W[5];
int V[5];

void input() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];
}

void solve() {
	for (int y = 1; y <= N; y++) // ��ǰ�� ��
	{
		for (int x = 1; x <= K; x++) // ��ƿ�� �ִ� ����
		{

			if (x - W[y] >= 0) dat[y][x] = max(dat[y - 1][x], dat[y - 1][x - W[y]] + V[y]);// ��ȭ�� max(dat[y - 1][x], dat[y - 1][x - W[y]] + V[y])
			else dat[y][x] = dat[y - 1][x];
		}
	}

}

void answer() {
	cout << dat[N][K];
}

void solution() {
	input();
	solve();
	answer();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}


/*
10kg ����
���� : ������� ��ġ�� �ִ�ȭ

1. ���԰� ������
1(1kg), 1(2kg), 2(3kg), 2(4kg)
10(5kg) -> good

2. ��ġ�� ū��(����)
10(10kg)
9(1kg) 5(2kg)

=> ��� ����� ���� ����غ����Ѵ�


4 7

a 6 13
b 4 8
c 3 6
d 5 12

abcd	W	V
0000	
0001	5  12
0010
0011x
0100
0101
0110	7   14
0111
1000
1001
1010
1011
1100
1101
1110
1111

��ȭ��
*/