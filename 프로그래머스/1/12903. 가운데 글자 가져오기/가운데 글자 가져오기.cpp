#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.size() % 2 == 0){
        int midIdx = (s.size() - 1) >> 1;
        answer += s[midIdx];
        answer += s[midIdx + 1];
    }
    else {
        int midIdx = s.size() >> 1;
        answer += s[midIdx];
    }
    
    return answer;
}