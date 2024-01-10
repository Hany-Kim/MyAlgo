#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> used;
int cnt;

void bfs(int com_num, int n, vector<vector<int>> computers) {
    queue<int> q;

    q.push(com_num);
    used[com_num] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < computers[now].size(); ++i) {

            if (used[computers[now][i]] == 1) continue;

            used[computers[now][i]] = 1;
            q.push(computers[now][i]);
        }
    }

    ++cnt;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<vector<int>> my_computers;

    my_computers = vector<vector<int>>(n);
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            if (computers[y][x] != 1) continue;
            my_computers[y].push_back(x);
        }
    }

    used = vector<int>(n, 0);
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < my_computers[y].size(); ++x) {
            if (used[my_computers[y][x]] != 1) bfs(my_computers[y][x], n, my_computers);
        }
    }

    answer = cnt;
    return answer;
}