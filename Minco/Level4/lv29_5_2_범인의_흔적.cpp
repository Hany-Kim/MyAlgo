#include <iostream>

using namespace std;

int index;
int start_index;
int evid[7] = {
	-1,0,0,1,2,4,4
};
int timeStamp[7] = {
	8,3,5,6,8,9,10
};

void input() {
	cin >> index;
	start_index = index;
}

void find(int index) {
	if (evid[index] == 0) {
		cout << evid[index] << "��index(���)" << endl;
		return;
	}
	find(evid[index]);
	cout << evid[index] << "��index("<<timeStamp[evid[index]]<<"��)" << endl;
}

void solution() {
	input();
	find(index);
	cout << start_index << "��index(" << timeStamp[start_index] << "��)" << endl;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}