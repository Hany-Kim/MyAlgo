#include <iostream>
using namespace std;

int N, K;
struct Info {
	bool isRobot = false;
	int life;
};
Info belt[2][101];
int step;

void rotate_belt() {
	for (register int i = 1; i <= N; ++i) {
		belt[1][i - 1] = belt[1][i];
	}
	belt[1][N] = belt[0][N];
	for (register int i = N; i >= 1; --i) {
		belt[0][i] = belt[0][i-1];
		if (i == N) {
			if (belt[0][i].isRobot == true) { // �κ��� ������ ��ġ�� �����ϸ� ������.
				belt[0][i].isRobot = false;
			}
		}
	}
	belt[0][1] = belt[1][0];
}

void move_robot() {
	for (register int i = N - 1; i >= 1; --i) {
		if (belt[0][i].isRobot) {
			if ((belt[0][i + 1].life > 0) && (belt[0][i+1].isRobot == false)) { // �̵��� ��ġ�� �������� �����ְ�, �κ��� ���ٸ�
				if ((i + 1) == N) { // �̵��� ��ġ�� ������ ��ġ���
					belt[0][i].isRobot = false; // �ٷγ�����.
				}
				else {
					belt[0][i + 1].isRobot = belt[0][i].isRobot;
					belt[0][i].isRobot = false;
				}
				belt[0][i + 1].life -= 1; // �Ű�ٸ� ������ ����
			}
		}
	}
}

void output_life() {
	for (int y = 0; y <= 1; ++y) {
		for (int x = 1; x <= N; ++x) {
			cout << belt[y][x].life << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void output_robot() {
	for (int y = 0; y <= 1; ++y) {
		for (int x = 1; x <= N; ++x) {
			if (belt[y][x].isRobot)
				cout << 1 << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void put_robot() {
	if ((belt[0][1].life > 0) && (belt[0][1].isRobot == false)) {
		belt[0][1].isRobot = true;
		belt[0][1].life -= 1;
	}
}

bool check_life() {
	int score = 0;
	for (register int i = 1; i <= N; ++i) {
		if (belt[0][i].life <= 0) ++score;
	}
	for (register int i = N; i >= 1; --i) {
		if (belt[1][i].life <= 0) ++score;
	}
	if (score >= K) return true;
	else return false;
}

void sol() {
	cin >> N >> K;
	for (register int i = 1; i <= N; ++i) {
		cin >> belt[0][i].life;
	}
	for (register int i = N; i >= 1; --i) {
		cin >> belt[1][i].life;
	}

	while (1) {
		++step;
		/*cout << "step: " << step << '\n';

		output_life();
		output_robot();*/

		rotate_belt(); // ��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ���Ѵ�.

		/*cout << "rotate belt\n";
		output_life();
		output_robot();*/

		move_robot(); // ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. ���� �̵��� �� ���ٸ� ������ �ִ´�

		/*cout << "move robot\n";
		output_life();
		output_robot();*/

		put_robot(); // �ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.

		/*cout << "put robot\n";
		output_life();
		output_robot();

		cout << "===============================\n";*/
		if (check_life()) break; // �������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.
	}
	cout << step;
	int de = 1;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}