#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0) { // 나눌 수가 0이 될때까지 반복
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    answer.push_back(gcd(n, m));
    
    int num1 = 1, num2 = 1;
    while((num1*n) != (num2*m)){
        if((num1*n) < (num2*m)){
            num1 += 1;
        }
        else if((num1*n) > (num2*m)){
            num2 += 1;
        }
    }
    answer.push_back(num1*n);
    
    return answer;
}