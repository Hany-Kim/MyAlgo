#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

vector<int> used;
vector<string> path;
vector<string> tmp;

bool isAllVisit() {
    FOR(i, 0, used.size()) {
        if (used[i] != 1) return false;
    }
    return true;
}

void dic_sort() {
    if (tmp.empty() == true) {
        tmp = path;
    }
    else {
        FOR(i, 0, tmp.size()) {
            if (tmp[i] == path[i]) continue;
            else if (tmp[i] < path[i]) {
                return;
            }
            else if (tmp[i] > path[i]) {
                tmp = path;
                return;
            }
        }
    }
}

void find_path(string start, vector<vector<string>> tickets, int lv) {
    if (isAllVisit() == true) {
        dic_sort();
        return;
    }

    FOR(i, 0, tickets.size()) {
        if (used[i] == 1) continue;
        if (tickets[i][0] == start) {
            used[i] = 1;
            path.push_back(tickets[i][1]);
            find_path(tickets[i][1], tickets, lv + 1);
            path.pop_back();
            used[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    used = vector<int>(tickets.size(), 0);

    path.push_back("ICN");
    find_path("ICN", tickets, 1);

    answer = tmp;

    return answer;
}