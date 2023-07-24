#include <iostream>
using namespace std;

//판매 대수에 상관없이 매년 임대료, 재산세, 보험료, 급여 등 A만원의 고정 비용
//한 대의 노트북을 생산하는 데에는 재료비와 인건비 등 총 B만원의 가변 비용
//노트북 가격이 C만원

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