#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());
    
    int idx = 0;
    for(int i=0; i<score.size(); ++i){
        if(score[i] == k){
            idx = i;
            break;
        }
    }
    for(int i=idx + (m-1); i<score.size(); i+=m){
        answer += (score[i] * m);
    }
    
    return answer;
}