#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#endif

#include<stdio.h>

#define CMD_MKDIR 1
#define CMD_RM 2
#define CMD_CP 3
#define CMD_MV 4
#define CMD_FIND 5

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

extern void init(int n);
extern void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]);
extern void cmd_rm(char path[PATH_MAXLEN + 1]);
extern void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]);
extern void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]);
extern int cmd_find(char path[PATH_MAXLEN + 1]);

////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
#define MAX_SIZE 50010

// The below commented functions are for your reference. If you want 
// to use it, uncomment these functions.

int mstrcmp(const char *a, const char *b)
{ // 두 문자열 같으면 0, 같지 않으면 0이 아닌값
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return a[i] - b[i];
}

int mstrncmp(const char *a, const char *b, int len)
{ // 두 문자열이 원하는 길이만큼 같으면 0, 같지 않으면 0이 아닌값
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}

int mstrlen(const char *a)
{ // 문자열 길이
	int len = 0;

	while (a[len] != '\0')
		len++;

	return len;
}

void mstrcpy(char *dest, const char *src)
{ // 문자열 복사
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void mstrncpy(char *dest, const char *src, int len)
{ // 문자열 원하는 길이만큼 복사

	for (int i = 0; i<len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}


struct Dir {
	char name[7];
	Dir* parent;
	vector<Dir*> child;
};
Dir dir_pool[MAX_SIZE];
Dir* root;
int dirCnt;
Dir* mstd;

Dir* get_dir(char name[7]) {
	mstrcpy(dir_pool[dirCnt].name, name);
	dir_pool->parent = nullptr;
	dir_pool[dirCnt].child = vector<Dir*>();
	return &dir_pool[dirCnt++];
}

void preorder(Dir* ptr, char path[], string cmp) {
	if (ptr) {
		//cout << ptr->name; // 현재 위치 dir name
		cmp += ptr->name;
		if (path == cmp) {
			mstd = ptr;
			return;
		}
		for (register int i = 0; i < ptr->child.size(); ++i) {// 자식 dir 모두 순회
			preorder(ptr->child[i], path, cmp);
		}
	}
}

void init(int n) {
	dirCnt = 0;
	char root_name[7] = { '/' };
	root = get_dir(root_name);
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
	string cmp = ""; // cmp 목표 경로와 같은지 비교
	preorder(&dir_pool[0], path, cmp); // 전위 순회로 path 찾기
	
	Dir* ptr = mstd;
	mstd = nullptr; // 전역변수 바로 초기화

	int len = mstrlen(name);
	name[len] = '/';
	name[len + 1] = '\0'; // !배열범위 벗어나는 오류 가능성있음 name최대크기 1 늘려줘
	Dir* new_dir = get_dir(name);
	new_dir->parent = ptr;
	ptr->child.push_back({ new_dir });
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {

}

void preorder_and_new_node(Dir* ptr) {
	if (ptr) {
		Dir* new_dir = get_dir(ptr->name);

		for (register int i = 0; i < ptr->child.size(); ++i) {
			preorder_and_new_node(ptr->child[i]);
		}
	}
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) { // 복사
	string srcCmp = ""; // cmp 목표 경로와 같은지 비교
	preorder(&dir_pool[0], srcPath, srcCmp); // 전위 순회로 path 찾기

	Dir* srcPtr = mstd; // src의 루트 노드
	mstd = nullptr; // 전역변수 바로 초기화

	string dstCmp = ""; // cmp 목표 경로와 같은지 비교
	preorder(&dir_pool[0], dstPath, dstCmp); // 전위 순회로 path 찾기

	Dir* dstPtr = mstd; // dst의 루트 노드
	mstd = nullptr; // 전역변수 바로 초기화

	Dir* tmp = srcPtr;

	int de = 1;
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {

}

int cmd_find(char path[PATH_MAXLEN + 1]) {

	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

static bool run(int m) {

	bool isAccepted = true;
	int cmd;
	char name[NAME_MAXLEN + 1];
	char path1[PATH_MAXLEN + 1], path2[PATH_MAXLEN + 1];

	while (m--) {

		scanf("%d", &cmd);

		if (cmd == CMD_MKDIR) {
			scanf("%s%s", path1, name);
			cmd_mkdir(path1, name);
		}
		else if (cmd == CMD_RM) {
			scanf("%s", path1);
			cmd_rm(path1);
		}
		else if (cmd == CMD_CP) {
			scanf("%s%s", path1, path2);
			cmd_cp(path1, path2);
		}
		else if (cmd == CMD_MV) {
			scanf("%s%s", path1, path2);
			cmd_mv(path1, path2);
		}
		else {
			int ret;
			int answer;

			scanf("%s", path1);
			ret = cmd_find(path1);
			scanf("%d", &answer);

			isAccepted &= (ret == answer);
		}
	}

	return isAccepted;
}

int main(void) {

	int test, T;
	int n, m;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (test = 1; test <= T; ++test) {

		scanf("%d%d", &n, &m);

		init(n);

		if (run(m)) {
			printf("#%d 100\n", test);
		}
		else {
			printf("#%d 0\n", test);
		}
	}

	return 0;
}