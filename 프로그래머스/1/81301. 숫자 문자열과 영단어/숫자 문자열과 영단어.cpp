#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int solution(string s) {
    long long answer = 0;
    
    um["zero"] = 0;
    um["one"] = 1;
    um["two"] = 2;
    um["three"] = 3;
    um["four"] = 4;
    um["five"] = 5;
    um["six"] = 6;
    um["seven"] = 7;
    um["eight"] = 8;
    um["nine"] = 9;
    
    for(int i=0; i<s.size(); ++i){
        string str = "";
        
        for(int j=i; j<s.size(); ++j){
            if(s[j] >= '0' && s[j] <= '9'){
                answer += int(s[j] - '0');
                answer *= 10;
                i = j;
                break;
            } else {
                str += s[j];
            
                unordered_map<string,int>::iterator itr = um.find(str);
                if(um.end() != itr){
                    answer += um[str];
                    answer *= 10;
                    str = "";
                    i = j;
                    break;
                }
            }
        }
    }
    
    answer /= 10;
    
    int ans = int(answer);
    return ans;
}