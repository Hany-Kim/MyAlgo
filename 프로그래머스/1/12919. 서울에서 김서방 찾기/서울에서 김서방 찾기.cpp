#include <string>
#include <vector>

using namespace std;

bool mstrcmp(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    
    for(int i=0; i<s1.size(); ++i){
        if(s1[i] != s2[i]) return false;
    }
    
    return true;
}

string solution(vector<string> seoul) {
    string answer = "";
    
    for(int i=0; i<seoul.size(); ++i){
        if(mstrcmp(seoul[i], "Kim")){
            answer += "김서방은 ";
            answer += to_string(i);
            answer += "에 있다";
            break;
        }
    }
    
    return answer;
}