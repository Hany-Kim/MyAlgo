#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int sIdx = 0;
    int eIdx = s.find(' ', 0);
    while (eIdx != -1) {
        for (int i = sIdx; i < eIdx; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if ((i-sIdx) % 2 == 0) {
                    answer += char((s[i] - 'a') + 'A');
                }
                else {
                    answer += s[i];
                }
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                if ((i - sIdx) % 2 == 1) {
                    answer += char((s[i] - 'A') + 'a');
                }
                else {
                    answer += s[i];
                }
            }
        }
        answer += ' ';
        sIdx = eIdx + 1;
        eIdx = s.find(' ', eIdx + 1);
    }

    for (int i = sIdx; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if ((i-sIdx) % 2 == 0) {
                answer += char((s[i] - 'a') + 'A');
            }
            else {
                answer += s[i];
            }
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            if ((i - sIdx) % 2 == 1) {
                answer += char((s[i] - 'A') + 'a');
            }
            else {
                answer += s[i];
            }
        }
    }

    return answer;
}