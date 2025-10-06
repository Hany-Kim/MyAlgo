#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<arr1.size(); i++){
        arr1[i] = arr1[i] | arr2[i];
        
        string s = "";
        for(int j=n-1; j>=0; j--){
            int t = (arr1[i] >> j) & 1;
            if(t){
                s += '#';
            }
            else {
                s += ' ';
            }
        }
        answer.push_back(s);
    }
    
    return answer;
}