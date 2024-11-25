#include <string>
#include <vector>
using namespace std;

int solution(int num) {
    int answer = -1;
    
    int times = 0;
    long long n = num;
    while(500>times){
        if(n == 1) {
            answer = times;
            break;
        }
        
        if(n % 2==0){
            n /= 2;
        }else {
            n = n * 3 + 1;
        }
        times++;
    }
    
    return answer;
}