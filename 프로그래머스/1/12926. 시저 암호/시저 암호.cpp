#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.size(); ++i){
        for(int j=0; j<n; ++j){
            if(s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 1;
                if(s[i] > 'Z') s[i] = 'A';
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                s[i] += 1;
                if(s[i] > 'z') s[i] = 'a';
            }
        }
        answer += s[i];
    }
    
    return answer;
}