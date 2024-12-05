#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char left, char right){
    if(left < right) return false;
    if(left > right) return true;
    
    return false;
}

string solution(string s) {
    string answer = "";
    
    sort(s.begin(), s.end(), cmp);
    
    answer = s;
    return answer;
}