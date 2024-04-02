#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int pct[4] = { 40, 30, 20, 10 };
vector<int> path; // 이모티콘 수만큼 pct 조합
struct NODE {
    int isJoinNum;
    int price;
};
vector<vector<int>> userList;
vector<int> emoticonList;
vector<NODE> v;

bool cmp(NODE left, NODE right) {
    if (left.isJoinNum > right.isJoinNum) return true;
    if (left.isJoinNum < right.isJoinNum) return false;

    if (left.price > right.price) return true;
    if (left.price < right.price) return false;

    return false;
}

void dfs(int lv) {
    if (lv == path.size()) {
        int isJoinNum = 0;
        int price = 0;
        for (int i = 0; i < userList.size(); ++i) { // 모든 유저
            bool isJoin = false;
            int cur_price = 0;
            for (int j = 0; j < path.size(); ++j) { // 모든 이모티콘
                if (userList[i][0] <= path[j]) {
                    // 할인율이 사용자 생각보다 크다면 구매
                    cur_price += ((emoticonList[j] / 100) * (100 - path[j]));
                }
                else {
                    // 아니면 구매안해
                }
            }
            if (userList[i][1] <= cur_price) {
                // 예산보다 구매비용이 더 비싸면 가입
                isJoinNum += 1;
            }
            else {
                price += cur_price;
            }
        }

        v.push_back({ isJoinNum, price });

        return;
    }
    for (int i = 0; i < 4; ++i) {
        path[lv] = pct[i];
        dfs(lv + 1);
        path[lv] = 0;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    userList = users;
    emoticonList = emoticons;
    path = vector<int>(emoticons.size(), 0);
    dfs(0);

    sort(v.begin(), v.end(), cmp);

    answer.push_back(v[0].isJoinNum);
    answer.push_back(v[0].price);

    return answer;
}