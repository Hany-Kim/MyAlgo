/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

int cost[5];
int monthPlan[12];
int used[12];
int usedState[12];
int minCost;

int calcCost(int month, int kindOfCost) {
	int cur = 0;
	switch (kindOfCost)
	{
	case 1:
		cur = monthPlan[month] * cost[kindOfCost];
		break;
	case 2:
		cur = cost[kindOfCost];
		break;
	case 3:
		cur = cost[kindOfCost];
		break;
	case 4:
		cur = cost[kindOfCost];
		break;
	}
	return cur;
}

bool setUsed(int month, int kindOfCost, int curUsed[12]) {
	int tmp[12] = { 0, };
	memcpy(tmp, curUsed, sizeof(tmp));

	switch (kindOfCost)
	{
	case 1:
		if (tmp[month] >= 1) return false;
		tmp[month] = 1;
		break;
	case 2:
		if (tmp[month] >= 1) return false;
		tmp[month] = 2;
		break;
	case 3:
		for (int i = month; i < month + 3; ++i) {
			if (i >= 12) continue;
			if (tmp[i] >= 1) return false;
			tmp[i] = 3;
		}
		break;
	case 4:
		for (int i = 0; i < 12; ++i) {
			if (tmp[i] >= 1) return false;
			tmp[i] = 4;
		}
		break;
	}

	memcpy(curUsed, tmp, sizeof(tmp));
	return true;
}

void resetUsed(int month, int kindOfCost) {
	memcpy(used, usedState, sizeof(used));
}

bool completePlan(int curUsed[12]) {
	for (int i = 0; i < 12; ++i) {
		if (monthPlan[i] > 0 && curUsed[i] == 0) return false;
	}
	return true;
}

void dfs(int to, int curCost, int curUsed[12]) {
	if (completePlan(curUsed)) {
		minCost = min(minCost, curCost);
	}
	for (int i = to; i < 12; ++i) {
		//if (monthPlan[i] == 0) continue;
		if (curUsed[i] >= 1) continue;
		for (int kindOfCost = 1; kindOfCost < 5; ++kindOfCost) {
			if (calcCost(i, 1) > calcCost(i, 2)) {
				if (kindOfCost == 1) continue;
			}
			else {
				if (kindOfCost == 2) continue;
			}

			int tmp[12] = { 0, };
			memcpy(tmp, curUsed, sizeof(tmp));
			if (!setUsed(i, kindOfCost, tmp)) {
				//resetUsed(i, kindOfCost);
				continue;
			}
			int cur = calcCost(i, kindOfCost);
			if (curCost + cur > minCost) return;
			dfs(i + 1, curCost + cur, tmp);
		}
	}

	int de = 1;
}

void in() {
	for (int i = 1; i < 5; ++i) {
		cin >> cost[i];
	}
	for (int i = 0; i < 12; ++i) {
		cin >> monthPlan[i];
	}
}

int getStartMinCost() {
	for (int i = 0; i < 12; ++i) {
		if (monthPlan[i] == 0) return INT_MAX;
	}
	return cost[4];
}

void sol() {
	in();
	minCost = getStartMinCost();
	dfs(0, 0, used);
	cout << minCost;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		cout << "#" << test_case << " ";
		sol();
		cout << "\n";
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}