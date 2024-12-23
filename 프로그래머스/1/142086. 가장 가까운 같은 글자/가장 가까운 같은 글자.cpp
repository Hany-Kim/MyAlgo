#include <string>
#include <vector>
#include <cstring>

using namespace std;

int arr[26];

vector<int> solution(string s) {
    vector<int> answer;
    
    memset(arr,-1,sizeof(arr));
    
    for(int i=0; i<s.size(); ++i){
        if(arr[int(s[i] - 'a')] == -1){
            arr[int(s[i] - 'a')] = i;
            answer.push_back(-1);
        }
        else {
            answer.push_back(i - arr[int(s[i] - 'a')]);
            arr[int(s[i] - 'a')] = i;
        }
    }
    
    return answer;
}