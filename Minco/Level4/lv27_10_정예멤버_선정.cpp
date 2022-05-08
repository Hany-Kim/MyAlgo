#include <iostream>

using namespace std;

int A[3][3] = {
	2,6,3,
	7,1,1,
	3,4,2
};
int B[2][4] = {
	6,4,2,4,
	1,1,5,8
};
int C[2][3] = {
	9,2,3,
	4,2,1
};

int output[3][3];

int choiceA() {
	int max_val = 0;
	int idxY = 0, idxX = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (max_val < A[y][x] && A[y][x] != -1) {
				max_val = A[y][x];
				idxY = y;
				idxX = x;
			}
		}
	}
	A[idxY][idxX] = -1;
	return max_val;
}
int choiceB() {
	int min_val = 9999;
	int idxY = 0, idxX = 0;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 4; x++) {
			if (min_val > B[y][x] && B[y][x] != -1) {
				min_val = B[y][x];
				idxY = y;
				idxX = x;
			}
		}
	}
	B[idxY][idxX] = -1;
	return min_val;
}
int choiceC(int i) {
	int max_val = 0, min_val = 9999;
	int idxY = 0, idxX = 0;
	if (i == 2) {
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 3; x++) {
				if (max_val < C[y][x] && C[y][x] != -1) {
					max_val = C[y][x];
					idxY = y;
					idxX = x;
				}
			}
		}
		C[idxY][idxX] = -1;

		return max_val;
	}
	else {
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 3; x++) {
				if (min_val > C[y][x] && C[y][x] != -1) {
					min_val = C[y][x];
					idxY = y;
					idxX = x;
				}
			}
		}
		C[idxY][idxX] = -1;

		return min_val;
	}
}

void answer() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << output[y][x] << " ";
		}
		cout << endl;
	}
}


int main() {
	for (int i = 0; i < 3; i++) {
		output[0][i] = choiceA();
		output[1][i] = choiceB();
		output[2][i] = choiceC(i);
	}

	answer();


	return 0;
}