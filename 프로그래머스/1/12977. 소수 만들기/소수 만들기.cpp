#include <vector>
#include <iostream>
using namespace std;

int arr[3001];

int solution(vector<int> nums) {
    int answer = -1;

    arr[0] = 1;
    arr[1] = 1;
    
    for(int i=2; i<3001; ++i){
        int num = i;
        int mul = 2;
        while((num * mul) < 3001){
            arr[num * mul++] = 1;
        }
    }
    
    int cnt = 0;
    for(int i=0; i<nums.size(); ++i){
        for(int j=(i+1); j<nums.size(); ++j){
            for(int k=(j+1); k<nums.size(); ++k){
                int num = nums[i] + nums[j] + nums[k];
                if(arr[num] == 0) cnt += 1;
            }
        }
    }

    answer = cnt;
    return answer;
}