#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); ++i){
        if(arr[i] % divisor == 0){
            s.insert(arr[i]);
        }
    }
    
    for(set<int>::iterator itr = s.begin(); itr != s.end(); ++itr){
        answer.push_back(*itr);
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}