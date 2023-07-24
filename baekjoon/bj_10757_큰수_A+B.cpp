#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
string rA, rB;
int sA, sB;
int carry;
string ans;

void sol() {
	cin >> A >> B;
	
	rA = A;
	reverse(rA.begin(), rA.end());
	rB = B;
	reverse(rB.begin(), rB.end());

	sA = rA.size();
	sB = rB.size();

	if (sA < sB) {
		for (int i = 0; i < (sB - sA); i++) {
			rA += '0';
		}
		for (int i = 0; i < sB; i++) {
			int sum = 0;
			sum = int(rA[i] - '0') + int(rB[i] - '0') + carry;
			if (sum / 10) {
				carry = 1;
			}
			else {
				carry = 0;
			}
			ans += char((sum % 10) + '0');
		}
	}
	else {
		for (int i = 0; i < (sA - sB); i++) {
			rB += '0';
		}
		for (int i = 0; i < sA; i++) {
			int sum = 0;
			sum = int(rA[i]-'0') + int(rB[i]-'0') + carry;
			if (sum / 10) {
				carry = 1;
			}
			else {
				carry = 0;
			}
			ans += char((sum % 10) + '0');
		}
	}
	if (carry) {
		ans += '1';
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}