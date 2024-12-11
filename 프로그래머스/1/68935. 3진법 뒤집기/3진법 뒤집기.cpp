#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v;
    int num = n;
    while(num != 0){
        v.push_back(num % 3);
        num = num / 3;
    }
    
    for(int i=v.size() - 1; i>=0; i--){
        int gisu = v.size() - 1 - i;
        answer += (pow(3, gisu) * v[i]);
    }
    
    return answer;
}