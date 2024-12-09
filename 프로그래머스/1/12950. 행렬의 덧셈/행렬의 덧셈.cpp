#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int y=0; y<arr1.size(); ++y){
        vector<int> tmp;
        for(int x=0; x<arr1[0].size(); ++x){
            int sum = arr1[y][x] + arr2[y][x];
            
            tmp.push_back(sum);
        }
        answer.push_back(tmp);
    }
    
    return answer;
}