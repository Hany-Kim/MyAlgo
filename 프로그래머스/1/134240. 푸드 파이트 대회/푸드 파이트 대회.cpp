#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> rev;
    
    for(int i=1; i<food.size(); ++i){
        if(food[i] % 2 == 1){
            food[i] -= 1;
        }
        
        int times = food[i] / 2;
        for(int j=0; j<times; ++j){
            answer += to_string(i);
            rev.push_back(i);
        }
        
    }
    
    answer += '0';
    
    for(int i=rev.size() - 1; i>=0; i--){
        answer += to_string(rev[i]);
    }
    return answer;
}