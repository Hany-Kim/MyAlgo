/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define N_MAX 8

struct NODE {
	int y, x, h;
};
int N, K;
int mmap[N_MAX][N_MAX];
vector<NODE> v;
int bestHeight;
int visited[N_MAX][N_MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int ans;

void in() {
	cin >> N >> K;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> mmap[y][x];
			
			NODE now;
			now.y = y;
			now.x = x;
			now.h = mmap[y][x];

			v.push_back(now);

			bestHeight = max(bestHeight, mmap[y][x]);
		}
	}
}

void init() {
	v.clear();
	bestHeight = 0;
	ans = 0;
	memset(visited, 0, sizeof(visited));
	memset(mmap, 0, sizeof(mmap));
}

bool cmp(NODE left, NODE right) {
	if (left.h < right.h) return true;
	if (left.h > right.h)return false;

	return false;
}

void sortedHeight() {
	sort(v.begin(), v.end(), cmp);
}

void dfs(NODE cur, bool useCut, int length) {

	for (int i = 0; i < 4; ++i) {
		int ny = cur.y + dy[i];
		int nx = cur.x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (visited[ny][nx] == 1) continue;

		int past = mmap[ny][nx];
		for (int j = 0; j <= K; ++j) {
			int nextHeight = mmap[ny][nx] - j;

			if (j != 0 && useCut) continue;
			if (nextHeight >= mmap[cur.y][cur.x]) continue;

			NODE next;
			next.y = ny;
			next.x = nx;
			mmap[ny][nx] = nextHeight;
			visited[ny][nx] = 1;
			if (j == 0) {
				dfs(next, useCut, length + 1);
			}
			else {
				dfs(next, true, length + 1);
			}
			mmap[ny][nx] = past;
			visited[ny][nx] = 0;
		}
	}

	ans = max(ans, length);
}

void sol() {
	init();
	in();
	sortedHeight();
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].h != bestHeight) continue;
		visited[v[i].y][v[i].x] = 1;
		dfs(v[i], false, 1);
		visited[v[i].y][v[i].x] = 0;
	}
	cout << ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
		sol();
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}