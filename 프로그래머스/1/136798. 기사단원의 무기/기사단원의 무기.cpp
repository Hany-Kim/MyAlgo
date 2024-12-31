#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

vector<int> arr;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int j=1; j<=number; ++j){
        vector<int> v;
        for(int i=1; i<=sqrt(j); ++i){
            if (j % i == 0) {
                v.push_back(i);
                if (i != j / i) v.push_back(j / i);
            }
		}
        
        arr.push_back(v.size());
    }
    
    for(int i=0; i<arr.size(); ++i){
        cout << arr[i] << ' ';
        if(arr[i] <= limit){
            answer += arr[i];
        }
        else {
            answer += power;
        }
    }
    
    return answer;
}