#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

vector<int> p1 = { 1,2,3,4,5 };
vector<int> p2 = { 2,1,2,3,2,4,2,5 };
vector<int> p3 = { 3,3,1,1,2,2,4,4,5,5 };
int p1_cnt;
int p2_cnt;
int p3_cnt;
int max_num;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    FOR(i, 0, answers.size()) {
        if (answers[i] == p1[i % (p1.size())]) {
            ++p1_cnt;
        }
        if (answers[i] == p2[i % (p2.size())]) {
            ++p2_cnt;
        }
        if (answers[i] == p3[i % (p3.size())]) {
            ++p3_cnt;
        }
        max_num = max(max_num, max(p1_cnt, max(p2_cnt, p3_cnt)));
    }

    if (p1_cnt == max_num) answer.push_back(1);
    if (p2_cnt == max_num) answer.push_back(2);
    if (p3_cnt == max_num) answer.push_back(3);

    return answer;
}