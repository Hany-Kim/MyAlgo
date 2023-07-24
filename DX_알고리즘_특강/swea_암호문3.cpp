#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX_SIZE 9000000

int N;
int cmd_num;
struct Node {
	int data;
	Node* next;
};
Node node[MAX_SIZE];
int nodeCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init() {
	N = 0;
	cmd_num = 0;
	head = nullptr;
	tail = head;
	nodeCnt = 0;
}

void addNode2Head(int data) {
	Node* new_node = getNode(data);

	new_node->next = head;
	head = new_node;

	tail = new_node; // 말단 노드 위치
}

void addNode2Tail(int data) {
	if (head == nullptr) addNode2Head(data);
	else {
		Node* new_node = getNode(data);

		tail->next = new_node;
		tail = tail->next;
	}
}

void insertNode2Num(Node* group_node, Node* edge_node, int num) {
	if (num == 0) {
		edge_node->next = head;
		head = group_node;
	}
	else {
		Node* start_ptr = head;
		for (register int i = 1; i < num; ++i) {
			if (start_ptr->next == nullptr) break;
			start_ptr = start_ptr->next;
		}

		edge_node->next = start_ptr->next;
		start_ptr->next = group_node;
	}
}

void deleteNodeGroup(int ptr, int num) {
	Node* start_node = head;

	for (register int i = 0; i < ptr; ++i) {
		start_node = start_node->next;
	}

	if (num > 0) {
		Node* end_node = start_node;

		for (register int i = 0; i < num; ++i) {
			end_node = end_node->next;
		}

		start_node->next = end_node;
	}
}

void addNodeGroup(Node* group_node) {
	Node* now_node = head;

	while (1) {
		if (now_node->next == nullptr)break;
		now_node = now_node->next;
	}

	now_node->next = group_node;
}

void sol() {
	cin >> N;
	for (register int i = 0; i < N; ++i) {
		int data = 0;
		cin >> data;
		addNode2Tail(data);
	}
	cin >> cmd_num;
	for (register int i = 0; i < cmd_num; ++i) {
		char cmd = ' ';
		int x = 0, y = 0, s = 0;
		cin >> cmd;
		switch (cmd)
		{
		case 'I':
		{
			cin >> x >> y;
			Node* group_node = nullptr;
			Node* now_node = nullptr;
			for (register int j = 0; j < y; ++j) {
				cin >> s;
				if (j == 0) {
					group_node = getNode(s);
					now_node = group_node;
				}
				else {
					Node* new_node = getNode(s);

					now_node->next = new_node;
					now_node = now_node->next;
				}
			}
			insertNode2Num(group_node, now_node, x);
		}
			break;
		case 'D':
			cin >> x >> y;
			deleteNodeGroup(x, y);
			break;
		case 'A':
		{
			cin >> y;
			Node* group_node = nullptr;
			Node* now_node = nullptr;
			for (register int j = 0; j < y; ++j) {
				cin >> s;
				if (j == 0) {
					group_node = getNode(s);
					now_node = group_node;
				}
				else {
					Node* new_node = getNode(s);

					now_node->next = new_node;
					now_node = now_node->next;
				}
			}
			addNodeGroup(group_node);
		}
			break;
		}
	}
	Node* now_node = head;
	for (register int i = 0; i < 10; ++i) {
		cout << now_node->data << ' ';
		now_node = now_node->next;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC = 10;
	for (register int testcase = 1; testcase <= TC; ++testcase) {
		cout << "#" << testcase << ' ';
		init();
		sol();
		cout << '\n';
	}
}