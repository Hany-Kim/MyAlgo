#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int nIdx;

bool cmp(string left, string right){
    if(left[nIdx] < right[nIdx]) return true;
    if(left[nIdx] > right[nIdx]) return false;
    
    int minSize = min(left.size(), right.size());
    for(int i=0; i<minSize; ++i){
        if(left[i] < right[i]) return true;
        if(left[i] > right[i]) return false;
    }
    return false;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    nIdx = n;
    sort(strings.begin(), strings.end(), cmp);
    
    answer = strings;
    return answer;
}