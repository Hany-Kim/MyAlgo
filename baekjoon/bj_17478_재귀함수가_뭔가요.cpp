#include <iostream>
#include <string>
using namespace std;

int dash;
int N;
string conversation[4] = {
	"\"재귀함수가 뭔가요?\"",
	"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
	"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
	"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};
string answer[2] = {
	"\"재귀함수가 뭔가요?\"",
	"\"재귀함수는 자기 자신을 호출하는 함수라네\""
};

void input() {
	cin >> N;
}

void func(int lv) {
	if (lv == N) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < dash; j++) {
				cout << "_";
			}
			cout << answer[i] << '\n';
		}
		for (int j = 0; j < dash; j++) {
			cout << "_";
		}
		cout << "라고 답변하였지.\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < dash; j++) {
			cout << "_";
		}
		cout << conversation[i] << '\n';
	}
	dash += 4;
	func(lv + 1);
	dash -= 4;
	for (int j = 0; j < dash; j++) {
		cout << "_";
	}
	cout << "라고 답변하였지.\n";
}

void sol() {
	input();
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	func(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}