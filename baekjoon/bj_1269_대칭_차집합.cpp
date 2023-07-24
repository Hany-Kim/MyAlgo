#include <iostream>
#include <vector>
using namespace std;

int numA, numB;
struct Zip
{
	bool A;
	bool B;
};
Zip arr[100000001];
int cnt;

void sol() {
	cin >> numA >> numB;
	for (int i = 0; i < numA; i++) {
		int num = 0;
		cin >> num;
		arr[num].A = 1;
	}
	for (int i = 0; i < numB; i++) {
		int num = 0;
		cin >> num;
		arr[num].B = 1;
	}
	for (int i = 0; i < 100000001; i++) {
		if ((arr[i].A == 1) && (arr[i].B == 0))cnt++;
		if ((arr[i].A == 0) && (arr[i].B == 1))cnt++;
	}
	cout<<cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}