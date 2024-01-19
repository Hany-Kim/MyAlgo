#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

string path[51];
vector<bool> used;
int min_num = 2134567890;

int mstrcmp(string str1, string str2) {
    int diff = 0;
    
    FOR(i, 0, str1.size()) {
        if (str1[i] == str2[i]) ++diff;
    }

    return diff;
}

void dfs(string begin, string target, vector<string> words, int lv) {
    // 타겟 문자찾으면 return
    if (path[lv - 1] == target) {
        if (min_num > (lv - 1)) {
            min_num = lv - 1;
        }
        return;
    }

    FOR(i, 0, words.size()) {
        if (used[i] == true) continue;
        if (mstrcmp(path[lv - 1], words[i]) == begin.size() - 1) {
            path[lv] = words[i];
            used[i] = true;
            dfs(begin, target, words, lv + 1);
            used[i] = false;
            path[lv] = "";
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    used = vector<bool>(words.size(), false);

    path[0] = begin;
    dfs(begin, target, words, 1);

    if (min_num == 2134567890) {
        answer = 0;
    }
    else {
        answer = min_num;
    }

    return answer;
}