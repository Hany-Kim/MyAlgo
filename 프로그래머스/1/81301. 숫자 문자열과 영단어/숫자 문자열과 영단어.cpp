#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string,int> um;

int solution(string s) {
    int answer = 0;
    
    // str : int 매핑
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
    
    string str_num = "";
    for(int i=0; i<s.size(); i++){
        if((int(s[i] - '0') >= 0) && (int(s[i] - '0') <= 9)){
            answer *= 10;
            answer += int(s[i] - '0');
        }
        else {
            str_num += s[i];
            
            // key확인
            unordered_map<string,int>::iterator itr = um.find(str_num);
            
            if (itr != um.end()) {
                answer *= 10;
				answer += um[str_num];
                
                str_num = "";
			}
			else {
                continue;
			}
        }
    }
    
    
    return answer;
}