#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    for(int i=0; i<phone_number.size(); ++i){
        if (i < phone_number.size() - 4){
            answer += "*";
        }
        else { answer += phone_number[i]; }
    }
    
    return answer;
}