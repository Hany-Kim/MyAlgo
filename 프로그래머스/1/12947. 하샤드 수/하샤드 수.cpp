#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int divNum = 0;
    int num = x;
    while(num > 0){
        divNum += (num % 10);
        num /= 10;
    }
    
    if(x % divNum == 0) return true;
    
    return false;
}