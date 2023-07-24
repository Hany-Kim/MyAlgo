// 1. 식권 자판기의 버튼을 특정 순서대로 누르고 결제 -> 평소와는 다른 색깔의 식권이 나옴
// 2. 식권을 배식대에 제출 -> 어떠한 비밀 메뉴를 받음
// 3. 어떤 메뉴가 나오는지??? 눌러야하는 버튼 순서 는 모름
// 비밀 메뉴가 나오는 조작법 2가지 발견

#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> button1;
vector<int> button2;
vector<int> copy_arr;
vector<int> path1;
vector<int> path2;
vector<int> temp;


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int input_num;
		cin >> input_num;
		button1.push_back(input_num);
	}
	for (int i = 0; i < M; i++) {
		int input_num;
		cin >> input_num;
		button2.push_back(input_num);
	}

	copy_arr = button1;

	
	return 0;
}