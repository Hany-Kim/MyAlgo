#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long endNum = sqrt(n);
    
    for(long long i=1; i<=endNum; ++i){
        if(pow(i,2) == n) return pow(i+1,2);
    }
    
    return -1;
}