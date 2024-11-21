#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

long long solution(long long n) {
    long long answer = 0;
    
    while(n>0){
        v.push_back(n % 10);
        
        n /= 10;
    }
    
    sort(v.begin(), v.end());
    
    reverse(v.begin(), v.end());
    
    for(int i=0; i<v.size(); ++i){
        answer *= 10;
        answer += v[i];
    }
    
    return answer;
}