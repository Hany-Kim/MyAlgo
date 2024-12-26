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

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int idx1 = 0;
    int idx2 = 0;
    
    for(int i=0; i<goal.size(); ++i){
        if(idx1 < cards1.size()){
            if(mstrcmp(cards1[idx1], goal[i])){
                idx1++;
                continue;
            }
        }
        if(idx2 < cards2.size()) {
            if(mstrcmp(cards2[idx2], goal[i])){
                idx2++;
                continue;
            }
        }
        
        return "No";
    }
    
    return answer;
}