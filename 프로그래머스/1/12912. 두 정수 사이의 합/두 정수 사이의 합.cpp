#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long minNum, maxNum;

long long solution(int a, int b) {
    long long answer = 0;
    
    minNum = min(a,b);
    maxNum = max(a,b);
    
    for(long long i=minNum; i<=maxNum; ++i){
        answer += i;
    }
    
    return answer;
}