#include <iostream>
#define MAX_TABLE (10007)
typedef unsigned long long int ull;
using namespace std;

int N, M;
struct POKETMON {
	int index;
	char name[21];
	POKETMON* next;
};
POKETMON HASH_TABLE[MAX_TABLE];
POKETMON POOL[100000 + 5000];
int pcnt;
POKETMON ARR[100000 + 5000];
struct NODE {
	int node;
	NODE* next;
};

ull myhash(const char* str) {
	unsigned long hash = 5381;
	int c = 0;
	while (c = *str++) {
		hash = (((hash << 5) + hash) % MAX_TABLE);
	}
	return hash % MAX_TABLE;
}
void mystrcpy(char* a, const char* b) {
	while (*a++ = *b++);
}
int mystrcmp(const char* a, const char* b) {
	while (*a && *a == *b) ++a, ++b;
	return *a - *b;
}
int change(char* str) {
	int i = 0, len = 0;
	int sum = 0, mul = 1;

	for (i = 0; str[i]; i++) {
		len = i;
	}
	for (i = len - 1; i >= 0; i--) {
		sum += (str[i] - '0') * mul;
		mul += 10;
	}
	return sum;
}
//void Make(int p, int c) {
//	NODE* nd = &POOL[pcnt++];
//	nd->node = c;
//
//	nd->next = HEAD[p].next;
//	HEAD[p].next = nd;
//}
void sol() {
	char str[21];
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> str;
		ull h = myhash(str);
		POKETMON* nd = &POOL[pcnt++];

		nd->index = i;
		mystrcpy(nd->name, str);

		nd->next = HASH_TABLE[h].next;
		HASH_TABLE[h].next = nd;

		mystrcpy(ARR[i].name, str);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if ('0' < str[0] && str[0] <= '9') {
			int index = change(str);
			cout << ARR[index].name << '\n';
		}
		else {
			ull h = myhash(str);
			POKETMON* nd = HASH_TABLE[h].next;

			while (nd) {
				if (!mystrcmp(nd->name, str)) {
					cout << nd->index << '\n';
					break;
				}
				nd = nd->next;
			}
		}
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