#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    //v = sizes;
    //dfs(0, 0, 0);
    //answer = min_num;

    int max_num1 = 0;
    FOR(y, 0, sizes.size()) {
        FOR(x, 0, 2) {
            max_num1 = max(max_num1, sizes[y][x]);
        }
    }

    int max_num2 = 0;
    FOR(i, 0, sizes.size()) {
        int select_num = min(sizes[i][0], sizes[i][1]);
        max_num2 = max(select_num, max_num2);
    }

    answer = max_num1 * max_num2;

    return answer;
}