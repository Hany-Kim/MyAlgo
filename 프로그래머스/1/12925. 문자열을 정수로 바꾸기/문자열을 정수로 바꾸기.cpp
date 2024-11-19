#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int num = 1;

    string ns = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+' && i == 0) num *= 1;
        else if (s[i] == '-' && i==0) num *= -1;
        else ns += s[i];
    }
    int n = stoi(ns);

    answer = n * num;

    return answer;
}