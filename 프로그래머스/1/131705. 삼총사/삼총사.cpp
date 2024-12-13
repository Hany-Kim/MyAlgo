#include <string>
#include <vector>

using namespace std;

vector<int> v;
vector<int> used;
int path[3];
int cnt;

void dfs(int lv, int to){
    if(lv == 3){
        int sum = 0;
        for(int i=0; i<3; ++i){
            sum += path[i];
        }
        
        if(sum == 0) cnt += 1;
        
        return;
    }
        
    for(int i = to+1; i<v.size(); ++i){
        if(used[i] == 1) continue;
        path[lv] = v[i];
        used[i] = 1;
        dfs(lv + 1, i);
        path[lv] = 0;
        used[i] = -1;
    }
}

int solution(vector<int> number) {
    int answer = 0;
    
    v = number;
    used = vector<int> (v.size(), 0);
    dfs(0, -1);
    
    
    answer = cnt;
    return answer;
}