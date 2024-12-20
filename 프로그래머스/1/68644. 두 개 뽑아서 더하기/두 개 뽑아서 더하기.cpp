#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i=0; i<numbers.size(); ++i){
        for(int j=i + 1; j<numbers.size(); ++j){
            if(i==j) continue;
            int num = numbers[i] + numbers[j];
            
            s.insert(num);
        }
    }
    
    for(set<int>::iterator itr=s.begin(); itr!=s.end(); itr++){
        answer.push_back(*itr);
    }
    
    return answer;
}