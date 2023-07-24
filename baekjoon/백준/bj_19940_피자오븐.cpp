#include <iostream>
#include <queue>
using namespace std;

int T;
struct Combi
{
	int one;
	int two;
	int three;
	int four;
	int five;
	int time;
};
Combi N[61];
bool used[61];

void bfs() {
	queue<Combi> q;

	q.push({ 0,0,0,0,0,0 });

	while (!q.empty()) {
		Combi now = q.front();
		q.pop();

		if (now.time < 0 || now.time > 60)continue;
		if (used[now.time]) continue;
		used[now.time] = 1;
		N[now.time] = now;
		q.push({ now.one, now.two, now.three, now.four, now.five + 1, now.time - 1 });
		q.push({ now.one, now.two, now.three, now.four + 1, now.five, now.time + 1 });
		q.push({ now.one, now.two, now.three + 1, now.four, now.five, now.time - 10 });
		q.push({ now.one, now.two + 1, now.three, now.four, now.five, now.time + 10 });
		q.push({ now.one + 1, now.two, now.three, now.four, now.five, now.time + 60 });
	}
}
void sol() {
	bfs();
	cin >> T;
	for (int i = 0; i < T; i++) {
		int num = 0;
		cin >> num;

		int nnum = num / 60;
		int remain = num % 60;
		cout << N[remain].one + nnum << ' ' << N[remain].two << ' ' << N[remain].three << ' '
			<< N[remain].four << ' ' << N[remain].five << '\n';
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}