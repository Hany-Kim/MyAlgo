#include <iostream>
#include <queue>

using namespace std;
// ���̰� L(2 �� L �� 1,000,000,000(�ʾ�))�� ����� ���� 
// ���� N(1 �� N �� 100,000)����
// 0 �� ��ǥ ��L
// 1�ʿ� 1ĭ�� �̵� (�¿�) - �ε����� ��� O
// ���̰� �ε����� ��� ������ �ٲ� �̵�
// ��ǥ�� ����� ������
// 
// ouput
// 1. ���� �������� �������� ����
// 2. �� ���̰� ������ �ð�
//
// �ʱ� ��ġ: +X (X�� ������ġ) / ->
// �ʱ� ��ġ: -X (X�� ������ġ) / <-

int N, L;
int init_pos;
int stick[7][2]; // 0�� L+1�̵Ǹ� �����Ű������ L+2�迭 ����, ���̹�ȣ(num)����
queue <int> pos;
int turn;
int num = 1;
int rightMax;
int leftMax;
int leftNum, rightNum;

int ans;

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> init_pos;
		pos.push(init_pos);
	}
}

void arrangement() {
	// ��ġ
	while (!pos.empty()) {
		int ant_pos = pos.front();

		// ���� ����
		if (ant_pos < 0) {
			stick[abs(ant_pos)][0] = -1; // �ʱ� ��ġ: -X (X�� ������ġ) / <-
			stick[abs(ant_pos)][1] = num;
		}
		else {
			stick[abs(ant_pos)][0] = 1; // �ʱ� ��ġ: +X (X�� ������ġ) / ->
			stick[abs(ant_pos)][1] = num;
		}
		num++;
	}
}

int compare() {
	for (int i = 1; i <= L; i++) {
		if (stick[i][0] == -1) {
			leftMax = i;
		}
	}
	for (int i = L; i >= 1; i--) {
		if (stick[i][0] == 1) {
			rightMax = i;
		}
	}

	if (leftMax >= (L - rightMax)) {
		return rightMax;
	}
	else if (leftMax < (L - rightMax)) {
		return (L - leftMax);
	}
}

void solution() {
	input();
	arrangement();
	ans = compare();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}