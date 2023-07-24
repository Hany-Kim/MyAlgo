#include <iostream>
using namespace std;

//�Ǹ� ����� ������� �ų� �Ӵ��, ��꼼, �����, �޿� �� A������ ���� ���
//�� ���� ��Ʈ���� �����ϴ� ������ ����� �ΰǺ� �� �� B������ ���� ���
//��Ʈ�� ������ C����

// A + Bx < Cx
// x?
// A < (C-B)x
// C-B<0 => -1

long long A, B, C;
long long ans;

void input() {
	cin >> A >> B >> C;
}

void check() {
	if (C - B <= 0)cout << -1;
	else {
		ans = A / (C - B);
		cout << ans + 1;
	}
}

void sol() {
	input();
	check();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}