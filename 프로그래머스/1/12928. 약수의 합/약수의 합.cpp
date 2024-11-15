#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_set<int> us;

int solution(int n) {
    int answer = 0;
    
    for(int i=1; i<=n; ++i){
        if(n % i == 0){
            us.insert(i);
        }
    }
    
    for(unordered_set<int>::iterator itr = us.begin(); itr != us.end(); itr++){
        answer += *itr;
    }
    
    return answer;
}