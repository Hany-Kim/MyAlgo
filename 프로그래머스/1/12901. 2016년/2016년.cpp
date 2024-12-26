#include <string>
#include <vector>
#include <iostream>
using namespace std;

int mon[12] = {
    31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
};
string yoil[7] = {
    "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"
};

string solution(int a, int b) {
    //string answer = "";
    
    int day = 0;
    if(a >= 2){
        day = mon[a - 2];
    }
    // for(int i=0; i<(a - 1); ++i){
    //     day += mon[i];
    // }
    cout << day << '\n';
    day += b;
    
    int mod = (day % 7) - 1;
    if(mod == -1) mod = 6;
    //answer = yoil[mod];
    
    return yoil[mod];
}