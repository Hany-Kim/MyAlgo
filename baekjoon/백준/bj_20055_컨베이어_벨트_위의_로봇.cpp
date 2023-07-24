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
			if (belt[0][i].isRobot == true) { // 로봇이 내리는 위치에 도착하면 내린다.
				belt[0][i].isRobot = false;
			}
		}
	}
	belt[0][1] = belt[1][0];
}

void move_robot() {
	for (register int i = N - 1; i >= 1; --i) {
		if (belt[0][i].isRobot) {
			if ((belt[0][i + 1].life > 0) && (belt[0][i+1].isRobot == false)) { // 이동할 위치에 내구도가 남아있고, 로봇이 없다면
				if ((i + 1) == N) { // 이동할 위치가 내리는 위치라면
					belt[0][i].isRobot = false; // 바로내린다.
				}
				else {
					belt[0][i + 1].isRobot = belt[0][i].isRobot;
					belt[0][i].isRobot = false;
				}
				belt[0][i + 1].life -= 1; // 옮겼다면 내구도 감소
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

		rotate_belt(); // 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.

		/*cout << "rotate belt\n";
		output_life();
		output_robot();*/

		move_robot(); // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다

		/*cout << "move robot\n";
		output_life();
		output_robot();*/

		put_robot(); // 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.

		/*cout << "put robot\n";
		output_life();
		output_robot();

		cout << "===============================\n";*/
		if (check_life()) break; // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
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