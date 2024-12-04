#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left; i<=right; ++i){
        int cnt = 0;
        
        int num = 1;
        while(i > pow(num, 2)){
            if(i % num == 0) cnt += 2;
            num++;
        }
        
        if(i == pow(num, 2)) cnt++;
        
        if(cnt % 2 == 0) answer += i;
        else if(cnt % 2 == 1) answer -= i;
    }
    
    return answer;
}