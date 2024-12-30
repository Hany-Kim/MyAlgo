#include <string>
#include <vector>
#include <climits>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int temp = section[0] + m;
	answer++;
    
    for(int i=1; i<section.size(); ++i){
        if (section[i] < temp) continue;
		else {
			temp = section[i] + m;
			answer++;
		}
    }
    
    return answer;
}