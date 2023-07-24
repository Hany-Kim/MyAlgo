#include <iostream>
#include <string>
using namespace std;

int dash;
int N;
string conversation[4] = {
	"\"����Լ��� ������?\"",
	"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.",
	"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.",
	"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""
};
string answer[2] = {
	"\"����Լ��� ������?\"",
	"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\""
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
		cout << "��� �亯�Ͽ���.\n";
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
	cout << "��� �亯�Ͽ���.\n";
}

void sol() {
	input();
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
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