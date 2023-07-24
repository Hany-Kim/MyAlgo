#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string N;
int x, y;
bool success;

int count_pos(string N) {
	return N.length();
}

void solution(vector<int>& result) {
	int len = count_pos(N);
	bool carry = false;

	for (int i = 0; i < len; i++) {
		int num = N[i] - '0';
		if (carry) {
			result.push_back(y);
		}
		else if (num >= y) {
			result.push_back(y);
			if (num > y) carry = true;
		}
		else if (num >= x) {
			if (x == 0 && result.empty()) {
				carry = true;
				continue;
			}
			result.push_back(x);
			if (num > x) carry = true;
		}
		else {
			if (!result.empty()) {
				int pos = result.size() - 1;
				for (int i = result.size() - 1; i >= 0; i--) {
					if (result[i] == x) {
						if (i == 0) result[i] = -1;
						else result[i] = y;
					}
					else {
						result[i] = x;
						break;
					}
				}
				result.push_back(y);
				carry = true;
			}
			else {
				carry = true;
			}
		}
	}
}



int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("sample_input.txt", "r", stdin);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> result;
		success = true;
		cin >> N >> x >> y;
		solution(result);

		cout << "#" << test_case << " ";
		if (result.empty()) success = false;
		if (!success) {
			cout << -1;
		}
		else {
			string answer = "";
			for (int i = 0; i < result.size(); i++) {
				if (result[i] == -1) continue;
				answer += to_string(result[i]);
			}
			cout << answer;
		}
		cout << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/* input
16
85428 6 8
66662 6 8
62 6 8
662 6 8
88778 8 9
555530 5 7
77550000 5 7
6818165691 0 7
6 6 9
12345678909876543210123456789098765432101234567890987654321012345678909876543210123456789098765432101234567890987654321012345678909876543210123456789098765432101234567890987654321012345678909876543210123456789098765432101234567890987654321012345678909876543210123456789098765432101234567890987654321012345678909876543210123456789098765432101234567890987654321012345678909876543210123456789098765432101234567890987654321012345678909876543210123456789098765432101234567890987654321012345678909876543210123456789098765432101234567890987654321012345678909876543210 1 7
41324 2 4
43311 2 4
16 1 3
2 6 9
5 0 8
422223324 2 4

output
#1 68888
#2 8888
#3 8
#4 88
#5 9999
#6 77777
#7 75777777
#8 777777777
#9 6
#10 1177777777...
#11 24444
#12 42444
#13 13
#14 -1
#15 -1
#16 422222333
*/