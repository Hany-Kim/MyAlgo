#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

int map[510][510];
int dy[2] = { 1,1 };
int dx[2] = { 0,1 };
int dp[510][510];

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	FOR(y, 0, triangle.size()) {
		FOR(x, 0, triangle[y].size()) {
			map[y][x] = triangle[y][x];
		}
	}

	dp[0][0] = map[0][0];
	FOR(y, 0, triangle.size() - 1) {
		FOR(x, 0, triangle[y].size()) {
			FOR(i, 0, 2) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				dp[ny][nx] = max(dp[ny][nx], dp[y][x] + map[ny][nx]);
			}
		}
	}

	FOR(i, 0, triangle[triangle.size() - 1].size()) {
		answer = max(answer, dp[triangle.size() - 1][i]);
	}

	return answer;
}