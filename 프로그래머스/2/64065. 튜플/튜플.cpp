#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    // 전체 묶음 {...} 제거
    s = s.substr(1, s.size() - 2);
    
    vector<vector<int>> tuple_sets;
    
    // 튜플 원소 파싱
    int start = 0;
    int end = s.find("},{");
    while(end != string::npos){
        string str_num = s.substr(start, end - start);
        
        if(str_num[0] == '{') str_num.erase(0, 1);
        if(str_num[str_num.size() - 1] == '}') str_num.erase(str_num.size() - 2, str_num.size() - 1);
        
        // 쉽표 분리
        vector<int> nums;
        stringstream ss(str_num);
        string num;
        
        while(getline(ss, num, ',')){
            if(!num.empty()){
                nums.push_back(stoi(num));
                //cout << "-> " << num << '\n';
            }
        }
        tuple_sets.push_back(nums);
        
        //cout << str_num << '\n';
        
        start = end + 3;
        end = s.find("},{", start);
    }
    
    string str_num = s.substr(start, end - start);
        
    if(str_num.front() == '{') str_num.erase(0, 1);
    if(str_num.back() == '}') str_num.pop_back();
        
    // 쉽표 분리
    vector<int> nums;
    stringstream ss(str_num);
    string num;

    while(getline(ss, num, ',')){
        if(!num.empty()){
            nums.push_back(stoi(num));
            //cout << "-> " << num << '\n';
        }
    }
    tuple_sets.push_back(nums);
    
    // 튜플 갯수 오름차순
    sort(tuple_sets.begin(), tuple_sets.end(), cmp);
    
    
    set<int> found_elements;
    
    for (const auto& current_set : tuple_sets) {
        for (int element : current_set) {
            if (found_elements.find(element) == found_elements.end()) {
                answer.push_back(element);
                found_elements.insert(element);
            }
        }
    }
    
    //cout << s << '\n';
    
    return answer;
}