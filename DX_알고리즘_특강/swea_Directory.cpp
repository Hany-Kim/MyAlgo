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
#include <string>
using namespace std;
#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999
#define CHILD_MAXLEN 30
#define MAX_SIZE 50000

// The below commented functions are for your reference. If you want 
// to use it, uncomment these functions.

// �� ���ڿ� �� �Լ�
int mstrcmp(const char *a, const char *b)
{ // �� ���ڿ��� ������ 0, ���� ������ 0�� �ƴ� ��
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return a[i] - b[i];
}
// �� ���ڿ� ���ϴ� ���̸�ŭ �� �Լ�
int mstrncmp(const char *a, const char *b, int len)
{// �� ���ڿ��� ���ϴ� ���̸�ŭ ������ 0, ���� ������ 0�� �ƴ� ��
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}
// ���ڿ� ���� ��ȯ
int mstrlen(const char *a)
{
	int len = 0;

	while (a[len] != '\0')
		len++;

	return len;
}
// ���ڿ� ����
void mstrcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}
// ���ڿ� ���ϴ� ���̸�ŭ ����
void mstrncpy(char *dest, const char *src, int len)
{
	for (int i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}

struct Dir {
	char name[NAME_MAXLEN];
	Dir* parent;
	Dir* child[CHILD_MAXLEN];
};
Dir dir_pool[MAX_SIZE];
Dir* root;
int dirCnt;
int cnt;

Dir* get_dir(char dir_name[NAME_MAXLEN + 1]) { // O(30)
	mstrcpy(dir_pool[dirCnt].name, dir_name); // ���ڿ� ����
	dir_pool[dirCnt].parent = nullptr;
	for (register int i = 0; i < CHILD_MAXLEN; ++i)
		dir_pool[dirCnt].child[i] = nullptr;
	return &dir_pool[dirCnt++];
}

void init(int n) { // O(n)
	// dir_pool �ʱ�ȭ
	for (register int i = 0; i < n; ++i) { // O(n * 30)
		char dummy[NAME_MAXLEN + 1] = { '\0' };
		mstrcpy(dir_pool[i].name, dummy); // ���ڿ� ����
		dir_pool[i].parent = nullptr;
		for (register int j = 0; j < CHILD_MAXLEN; ++j)
			dir_pool[i].child[j] = nullptr;
	}
	dirCnt = 0; // dir_pool ������ ��ġ ������ dirCnt �ʱ�ȭ

	// root ���丮 ����
	char root_name[NAME_MAXLEN + 1] = { '/' };
	root = nullptr;
	root = get_dir(root_name); // O(30)
}

// path ��� ���� ã��
Dir* find_path(char path[PATH_MAXLEN + 1]) { //O(419, 790)
	Dir* ptr = root;

	string pathToFind = "";
	pathToFind = path;

	int s = 0;
	int idx = pathToFind.find('/', s); // O(1999)
	string cur_dir = pathToFind.substr(s, idx + 1);

	while (1) { // O(1999 * 30 * 7) = O(419,790)
		s = idx + 1;
		idx = pathToFind.find('/', s); // O(1999)
		if (idx == -1) break;

		cur_dir = pathToFind.substr(s, idx - s);
		for (int i = 0; i < CHILD_MAXLEN; ++i) { // O(30 * 7)
			if (ptr->child[i] == nullptr) continue;
			if (mstrcmp(ptr->child[i]->name, cur_dir.c_str()) == 0) { // O(7)
				ptr = ptr->child[i];
				break;
			}
		}
	}

	return ptr;
}

// ����
void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
	// path[] / name[] ����
	Dir* new_dir = get_dir(name);

	Dir* ptr = find_path(path); // path ��� ���� ã��

	// ���ο� dir ����
	for (int i = 0; i < CHILD_MAXLEN; ++i) {
		if (ptr->child[i] == nullptr) {
			new_dir->parent = ptr;
			ptr->child[i] = new_dir;
			break;
		}
	}
}

// ����
void cmd_rm(char path[PATH_MAXLEN + 1]) {
	Dir* ptr = find_path(path);

	// ptr �θ�� ���� ����
	for (register int i = 0; i < CHILD_MAXLEN; ++i) {
		if (ptr->parent->child[i] == nullptr) continue;

		if (mstrcmp(ptr->parent->child[i]->name, ptr->name) == 0) {
			ptr->parent->child[i] = nullptr;
			ptr->parent = nullptr;
			break;
		}
	}
}

void cp_tree_by_preorder(Dir* parentPtr, Dir* dstPtr, Dir* srcPtr, int idx) { // ���� ��ȸ�� Ʈ�� ����
	if (srcPtr) {
		dstPtr = get_dir(srcPtr->name);
		dstPtr->parent = parentPtr;
		parentPtr->child[idx] = dstPtr;
		for (register int i = 0; i < CHILD_MAXLEN; ++i) {
			if (srcPtr->child[i] == nullptr) continue;
			cp_tree_by_preorder(dstPtr, dstPtr->child[i], srcPtr->child[i], i);
		}
	}
}
// ����
void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	Dir* srcPtr = find_path(srcPath); // bb ���� ����dir ����
	Dir* dstPtr = find_path(dstPath); // aa ������ ����

	for (register int i = 0; i < CHILD_MAXLEN; ++i) {
		if (dstPtr->child[i] == nullptr) {
			Dir* new_dir_tree = nullptr;
			cp_tree_by_preorder(dstPtr, new_dir_tree, srcPtr, i);
			break;
		}
	}
}

// �̵�
void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	Dir* srcPtr = find_path(srcPath); // bb ���� ����dir �̵�
	Dir* dstPtr = find_path(dstPath); // aa ������ �̵�

	// srcPtr �θ�� ���� ����
	for (register int i = 0; i < CHILD_MAXLEN; ++i) {
		if (srcPtr->parent->child[i] == nullptr) continue;

		if (mstrcmp(srcPtr->parent->child[i]->name, srcPtr->name) == 0) {
			srcPtr->parent->child[i] = nullptr;
			srcPtr->parent = nullptr;
			break;
		}
	}

	// srcPtr, dstPtr ����
	for (register int i = 0; i < CHILD_MAXLEN; ++i) {
		if (dstPtr->child[i] == nullptr) {
			dstPtr->child[i] = srcPtr;
			srcPtr->parent = dstPtr;
			break;
		}
	}
}

void dir_counter(Dir* ptr) {
	if (ptr) {
		cnt++;
		for (register int i = 0; i < CHILD_MAXLEN; ++i) {
			if (ptr->child[i] == nullptr) continue;
			dir_counter(ptr->child[i]);
		}
	}
}
// ã��
int cmd_find(char path[PATH_MAXLEN + 1]) {
	Dir* ptr = find_path(path);

	cnt = 0;
	dir_counter(ptr);

	return cnt - 1;
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