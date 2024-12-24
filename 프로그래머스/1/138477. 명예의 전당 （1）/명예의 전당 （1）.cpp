#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int> rpq;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    for(int i=0; i<score.size(); ++i){
        pq.push(score[i]);
        
        if(pq.size() <= k){
            int now = pq.top();
            answer.push_back(now);
        }else {
            int now = pq.top();
            pq.pop();
            rpq.push(now);
            
            now = pq.top();
            answer.push_back(now);
        }
    }
    
    return answer;
}