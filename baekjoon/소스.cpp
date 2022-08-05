#include <iostream>
#include <vector>
using namespace std;

int tc;
vector <int> student;
int student_num;
int score;

void input() {
	cin >> student_num;
	for (int i = 0; i < student_num; i++) {
		cin >> score;
		student.push_back(score);
	}
}

float average() {
	int sum = 0;
	for (int i = 0; i < student_num; i++) {
		sum += student[i];
	}
	float avg = sum / student_num;
	return avg;
}

int score_cmp(float avg) {
	int cnt = 0;
	for (int i = 0; i < student_num; i++) {
		if (avg < student[i])cnt++;
	}
	return cnt;
}

void sol() {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		input();
		float avg = 0.0;
		avg = average();
		int cnt = score_cmp(avg);
		float ratio = 0.0;
		ratio = (cnt * 100) / student_num;
		cout.setf(ios::fixed);
		cout.precision(3);
		cout << ratio << "%\n";
		student.clear();
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	sol();
	

	return 0;
}