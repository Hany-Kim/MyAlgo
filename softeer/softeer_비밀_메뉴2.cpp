// 1. �ı� ���Ǳ��� ��ư�� Ư�� ������� ������ ���� -> ��ҿʹ� �ٸ� ������ �ı��� ����
// 2. �ı��� ��Ĵ뿡 ���� -> ��� ��� �޴��� ����
// 3. � �޴��� ��������??? �������ϴ� ��ư ���� �� ��
// ��� �޴��� ������ ���۹� 2���� �߰�

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