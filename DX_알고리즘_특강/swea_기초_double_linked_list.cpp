#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init() {
	head = nullptr;
	nodeCnt = 0;
}

void addNode2Head(int data) {
	Node* new_node = getNode(data);

	if (head == nullptr) { // 첫 원소 삽입
		new_node->prev = nullptr;
		new_node->next = nullptr;
		head = new_node;
	}
	else {
		head->prev = new_node;
		new_node->next = head;
		new_node->prev = nullptr;
		head = new_node;
	}
}

void addNode2Tail(int data) {
	if (head == nullptr) addNode2Head(data);
	else {
		Node* new_node = getNode(data);

		Node* cur_node = head;
		while (cur_node->next != nullptr) {
			cur_node = cur_node->next;
		}

		new_node->prev = cur_node;
		new_node->next = cur_node->next;
		cur_node->next = new_node;
	}
}

void addNode2Num(int data, int num) {
	if (num == 1) {
		addNode2Head(data);
	}
	/*else if (num == nodeCnt + 1) {
		addNode2Tail(data);
	}*/
	else {
		Node* new_node = getNode(data);

		Node* cur_node = head;
		int idx = num;

		while (1) {
			if (idx == 2) {
				new_node->prev = cur_node;
				new_node->next = cur_node->next;
				cur_node->next = new_node;
				if(cur_node->next->next != nullptr) cur_node->next->next->prev = new_node;
				break;
			}
			cur_node = cur_node->next;
			--idx;
		}
	}
}

int findNode(int data)
{
	Node* now_node = head;
	int num = 1;
	while (1) {
		if (now_node->data == data)break;
		++num;
		now_node = now_node->next;
	}
	return num;
}

void removeNode(int data) {
	Node* cur_node = head;
	int idx = 0;
	while (1) {
		if (cur_node->data == data) break;
		if (cur_node->next == nullptr) {
			idx = -1; // 원소중에 data랑 일치하는게 없을때
			break;
		}
		cur_node = cur_node->next;
		++idx;
	}

	if (idx == -1) return;
	else if (idx == 0) { // 첫 원소일때
		head = head->next;
		head->prev = nullptr;
	}
	/*else if (idx + 1 == nodeCnt) { // 마지막 원소일 때

	}*/
	else {
		Node* prev_node = head;
		while (1) {
			if (prev_node->next->data == data) {
				prev_node->next = prev_node->next->next;
				if(prev_node->next != nullptr) prev_node->next->prev = prev_node;
				break;
			}
			prev_node = prev_node->next;
		}
	}
}

int getList(int output[MAX_NODE])
{
	Node* ptr = head;
	int cnt = 0;
	while (ptr != nullptr) {
		int a = ptr->data;
		output[cnt] = a;
		cnt++;
		if (ptr == nullptr) break;
		ptr = ptr->next;
	}
	return cnt;
}

int getReversedList(int output[MAX_NODE])
{
	Node* ptr = head;
	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	int cnt = 0;
	while (ptr != nullptr) {
		output[cnt] = ptr->data;
		cnt++;
		if (ptr == nullptr) break;
		ptr = ptr->prev;
	}
	return cnt;
}

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}