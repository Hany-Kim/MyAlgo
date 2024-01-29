#include <iostream>
#include <vector>
using namespace std;

int TC, n;
vector<vector<char>> cube;

void init() {
	//cube = vector<vector<char>>(18, vector<char>(3));
	/*cube = {
		{'w','w','w'},
		{'w','w','w'},
		{'w','w','w'},

		{'y','y','y'},
		{'y','y','y'},
		{'y','y','y'},
		
		{'r','r','r'},
		{'r','r','r'},
		{'r','r','r'},
		
		{'o','o','o'},
		{'o','o','o'},
		{'o','o','o'},
		
		{'g','g','g'},
		{'g','g','g'},
		{'g','g','g'},
		
		{'b','b','b'},
		{'b','b','b'},
		{'b','b','b'}
	};*/
	cube = {
		{'w','w','w','w','w','w','w','w','w'}, // U
		{'y','y','y','y','y','y','y','y','y'}, // D
		{'r','r','r','r','r','r','r','r','r'}, // F
		{'o','o','o','o','o','o','o','o','o'}, // B
		{'g','g','g','g','g','g','g','g','g'}, // L
		{'b','b','b','b','b','b','b','b','b'}  // R
	};
}

// 0 1 2	6 3 0
// 3 4 5 -> 7 4 1
// 6 7 8	8 5 2
void rotate_upside() {
	cube[0] = { cube[0][6], cube[0][3], cube[0][0], cube[0][7], cube[0][4], cube[0][1], cube[0][8], cube[0][5], cube[0][2] };

	vector<char> temp = { cube[2][0],cube[2][1],cube[2][2] };
	cube[2][0] = cube[5][0];
	cube[2][1] = cube[5][1];
	cube[2][2] = cube[5][2];
	cube[5][0] = cube[3][0];
	cube[5][1] = cube[3][1];
	cube[5][2] = cube[3][2];
	cube[3][0] = cube[4][0];
	cube[3][1] = cube[4][1];
	cube[3][2] = cube[4][2];
	cube[4][0] = temp[0];
	cube[4][1] = temp[1];
	cube[4][2] = temp[2];
}
// 0 1 2	2 5 8
// 3 4 5 -> 1 4 7
// 6 7 8	0 3 6	
void rev_rotate_upside() {
	cube[0] = { cube[0][2], cube[0][5], cube[0][8], cube[0][1], cube[0][4], cube[0][7], cube[0][0], cube[0][3], cube[0][6] };

	vector<char> temp = { cube[2][0],cube[2][1],cube[2][2] };
	cube[2][0] = cube[4][0];
	cube[2][1] = cube[4][1];
	cube[2][2] = cube[4][2];
	cube[4][0] = cube[3][0];
	cube[4][1] = cube[3][1];
	cube[4][2] = cube[3][2];
	cube[3][0] = cube[5][0];
	cube[3][1] = cube[5][1];
	cube[3][2] = cube[5][2];
	cube[5][0] = temp[0];
	cube[5][1] = temp[1];
	cube[5][2] = temp[2];
}

void rotate_downside() {
	cube[1] = { cube[1][6], cube[1][3], cube[1][0], cube[1][7], cube[1][4], cube[1][1], cube[1][8], cube[1][5], cube[1][2] };

	vector<char> temp = { cube[2][6],cube[2][7],cube[2][8] };
	cube[2][6] = cube[4][6];
	cube[2][7] = cube[4][7];
	cube[2][8] = cube[4][8];
	cube[4][6] = cube[3][6];
	cube[4][7] = cube[3][7];
	cube[4][8] = cube[3][8];
	cube[3][6] = cube[5][6];
	cube[3][7] = cube[5][7];
	cube[3][8] = cube[5][8];
	cube[5][6] = temp[0];
	cube[5][7] = temp[1];
	cube[5][8] = temp[2];
}
void rev_rotate_downside() {
	cube[1] = { cube[1][2], cube[1][5], cube[1][8], cube[1][1], cube[1][4], cube[1][7], cube[1][0], cube[1][3], cube[1][6] };

	vector<char> temp = { cube[2][6],cube[2][7],cube[2][8] };
	cube[2][6] = cube[5][6];
	cube[2][7] = cube[5][7];
	cube[2][8] = cube[5][8];
	cube[5][6] = cube[3][6];
	cube[5][7] = cube[3][7];
	cube[5][8] = cube[3][8];
	cube[3][6] = cube[4][6];
	cube[3][7] = cube[4][7];
	cube[3][8] = cube[4][8];
	cube[4][6] = temp[0];
	cube[4][7] = temp[1];
	cube[4][8] = temp[2];
}

void rotate_frontside() {
	cube[2] = { cube[2][6], cube[2][3], cube[2][0], cube[2][7], cube[2][4], cube[2][1], cube[2][8], cube[2][5], cube[2][2] };

	vector<char> temp = { cube[0][6],cube[0][7],cube[0][8] };
	cube[0][6] = cube[4][8];
	cube[0][7] = cube[4][5];
	cube[0][8] = cube[4][2];
	cube[4][8] = cube[1][2];
	cube[4][5] = cube[1][1];
	cube[4][2] = cube[1][0];
	cube[1][2] = cube[5][0];
	cube[1][1] = cube[5][3];
	cube[1][0] = cube[5][6];
	cube[5][0] = temp[0];
	cube[5][3] = temp[1];
	cube[5][6] = temp[2];
}
void rev_rotate_frontside() {
	cube[2] = { cube[2][2], cube[2][5], cube[2][8], cube[2][1], cube[2][4], cube[2][7], cube[2][0], cube[2][3], cube[2][6] };

	vector<char> temp = { cube[0][6],cube[0][7],cube[0][8] };
	cube[0][6] = cube[5][0];
	cube[0][7] = cube[5][3];
	cube[0][8] = cube[5][6];
	cube[5][0] = cube[1][2];
	cube[5][3] = cube[1][1];
	cube[5][6] = cube[1][0];
	cube[1][2] = cube[4][8];
	cube[1][1] = cube[4][5];
	cube[1][0] = cube[4][2];
	cube[4][8] = temp[0];
	cube[4][5] = temp[1];
	cube[4][2] = temp[2];
}

void rotate_backside() {
	cube[3] = { cube[3][6], cube[3][3], cube[3][0], cube[3][7], cube[3][4], cube[3][1], cube[3][8], cube[3][5], cube[3][2] };

	vector<char> temp = { cube[0][0],cube[0][1],cube[0][2] };
	cube[0][0] = cube[5][2];
	cube[0][1] = cube[5][5];
	cube[0][2] = cube[5][8];
	cube[5][2] = cube[1][8];
	cube[5][5] = cube[1][7];
	cube[5][8] = cube[1][6];
	cube[1][8] = cube[4][6];
	cube[1][7] = cube[4][3];
	cube[1][6] = cube[4][0];
	cube[4][6] = temp[0];
	cube[4][3] = temp[1];
	cube[4][0] = temp[2];
}
void rev_rotate_backside() {
	cube[3] = { cube[3][2], cube[3][5], cube[3][8], cube[3][1], cube[3][4], cube[3][7], cube[3][0], cube[3][3], cube[3][6] };

	vector<char> temp = { cube[0][0],cube[0][1],cube[0][2] };
	cube[0][0] = cube[4][6];
	cube[0][1] = cube[4][3];
	cube[0][2] = cube[4][0];
	cube[4][6] = cube[1][8];
	cube[4][3] = cube[1][7];
	cube[4][0] = cube[1][6];
	cube[1][8] = cube[5][2];
	cube[1][7] = cube[5][5];
	cube[1][6] = cube[5][8];
	cube[5][2] = temp[0];
	cube[5][5] = temp[1];
	cube[5][8] = temp[2];
}

void rotate_leftside() {
	cube[4] = { cube[4][6], cube[4][3], cube[4][0], cube[4][7], cube[4][4], cube[4][1], cube[4][8], cube[4][5], cube[4][2] };

	vector<char> temp = { cube[0][0],cube[0][3],cube[0][6] };
	cube[0][0] = cube[3][8];
	cube[0][3] = cube[3][5];
	cube[0][6] = cube[3][2];
	cube[3][8] = cube[1][0];
	cube[3][5] = cube[1][3];
	cube[3][2] = cube[1][6];
	cube[1][0] = cube[2][0];
	cube[1][3] = cube[2][3];
	cube[1][6] = cube[2][6];
	cube[2][0] = temp[0];
	cube[2][3] = temp[1];
	cube[2][6] = temp[2];
}
void rev_rotate_leftside() {
	cube[4] = { cube[4][2], cube[4][5], cube[4][8], cube[4][1], cube[4][4], cube[4][7], cube[4][0], cube[4][3], cube[4][6] };

	vector<char> temp = { cube[0][0],cube[0][3],cube[0][6] };
	cube[0][0] = cube[2][0];
	cube[0][3] = cube[2][3];
	cube[0][6] = cube[2][6];
	cube[2][0] = cube[1][0];
	cube[2][3] = cube[1][3];
	cube[2][6] = cube[1][6];
	cube[1][0] = cube[3][8];
	cube[1][3] = cube[3][5];
	cube[1][6] = cube[3][2];
	cube[3][8] = temp[0];
	cube[3][5] = temp[1];
	cube[3][2] = temp[2];
}

void rotate_rightside() {
	cube[5] = { cube[5][6], cube[5][3], cube[5][0], cube[5][7], cube[5][4], cube[5][1], cube[5][8], cube[5][5], cube[5][2] };

	vector<char> temp = { cube[0][2],cube[0][5],cube[0][8] };
	cube[0][2] = cube[2][2];
	cube[0][5] = cube[2][5];
	cube[0][8] = cube[2][8];
	cube[2][2] = cube[1][2];
	cube[2][5] = cube[1][5];
	cube[2][8] = cube[1][8];
	cube[1][2] = cube[3][6];
	cube[1][5] = cube[3][3];
	cube[1][8] = cube[3][0];
	cube[3][6] = temp[0];
	cube[3][3] = temp[1];
	cube[3][0] = temp[2];
}
void rev_rotate_rightside() {
	cube[5] = { cube[5][2], cube[5][5], cube[5][8], cube[5][1], cube[5][4], cube[5][7], cube[5][0], cube[5][3], cube[5][6] };

	vector<char> temp = { cube[0][2],cube[0][5],cube[0][8] };
	cube[0][2] = cube[3][6];
	cube[0][5] = cube[3][3];
	cube[0][8] = cube[3][0];
	cube[3][6] = cube[1][2];
	cube[3][3] = cube[1][5];
	cube[3][0] = cube[1][8];
	cube[1][2] = cube[2][2];
	cube[1][5] = cube[2][5];
	cube[1][8] = cube[2][8];
	cube[2][2] = temp[0];
	cube[2][5] = temp[1];
	cube[2][8] = temp[2];
}

void sol() {
	cin >> TC;
	for (int testcase = 0; testcase < TC; testcase++) {
		init();
		cin >> n;
		for (int cmd = 0; cmd < n; cmd++) {
			char area = ' ';
			char dir = ' ';
			cin >> area >> dir;

			if (area == 'U') {
				if (dir == '+') rotate_upside();
				else if (dir == '-') rev_rotate_upside();
			}
			else if (area == 'D') {
				if (dir == '+') rotate_downside();
				else if (dir == '-') rev_rotate_downside();
			}
			else if (area == 'F') {
				if (dir == '+') rotate_frontside();
				else if (dir == '-') rev_rotate_frontside();
			}
			else if (area == 'B') {
				if (dir == '+') rotate_backside();
				else if (dir == '-') rev_rotate_backside();
			}
			else if (area == 'L') {
				if (dir == '+') rotate_leftside();
				else if (dir == '-') rev_rotate_leftside();
			}
			else if (area == 'R') {
				if (dir == '+') rotate_rightside();
				else if (dir == '-') rev_rotate_rightside();
			}

		}

		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				cout << cube[0][x + (y*3)];
			}
			cout << '\n';
		}
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}