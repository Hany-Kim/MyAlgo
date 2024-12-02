#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size() <= 1) answer.push_back(-1);
    else {
        int idx = 0;
        int minNum = arr[0];
        for(int i=1; i<arr.size(); ++i){
            if(minNum > arr[i]){
                idx = i;
                minNum = arr[i];
            }
        }
        
        arr.erase(arr.begin() + idx);
        
        answer = arr;
    }
    
    return answer;
}