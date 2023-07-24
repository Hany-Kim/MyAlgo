#include <iostream>
using namespace std;

#define MAX_NODE 1000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt; // 노드 끝위치 바라봄
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

// 초기화
void init() {
	head = nullptr;
	nodeCnt = 0;
}

// 맨 앞에 노드 추가
void addNode2Head(int data) {
	Node* new_node = getNode(data);

	new_node->next = head;
	head = new_node;
}

// 맨 뒤에 노드 추가
void addNode2Tail(int data) {
	Node* new_node = getNode(data);

	Node* last_node = head;
	int cnt = nodeCnt - 2;
	while(cnt--) {
		last_node = last_node->next;
	}

	new_node->next = last_node->next;
	last_node->next = new_node;
}

// 지정된 순서(num)에 노드 추가
void addNode2Num(int data, int num) {
	Node* new_node = getNode(data);

	if (num == 1) {
		new_node->next = head;
		head = new_node;
	}
	else {
		Node* cur_node = head;
		int cnt = num;

		Node* prev_node = head;
		while (cnt--) {
			if (cnt == 1) {
				prev_node = cur_node;
			}
			if (cnt == 0) {
				new_node->next = cur_node;
				prev_node->next = new_node;
				break;
			}
			cur_node = cur_node->next;
		}
	}
}

// 주어진 data값을 가진 노드 삭제
void removeNode(int data) {
	Node* prev_ptr = head;
	
	if (prev_ptr->data == data) { // 첫 원소
		head = head->next;
	}
	else {
		while (prev_ptr->next != nullptr && prev_ptr->next->data != data) {
			prev_ptr = prev_ptr->next;
		}
		if (prev_ptr->next != nullptr) {
			prev_ptr->next = prev_ptr->next->next;
		}
	}

	nodeCnt--;
}

// output[] 배열에 리스트 노드의 data를 차례로 넣고, 총 노드 갯수를 리턴
int getList(int output[MAX_NODE]) {
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

void sol() {
	while (1) {
		int cmd = 0, data = 0, num = 0, cnt = 0, i = 0;
		int output[MAX_NODE] = { 0, };

		cin >> cmd;

		switch (cmd)
		{
		case ADD_HEAD:
			cin >> data;
			addNode2Head(data);
			break;
		case ADD_TAIL:
			cin >> data;
			addNode2Tail(data);
			break;
		case ADD_NUM:
			cin >> data >> num;
			addNode2Num(data, num);
			break;
		case REMOVE:
			cin >> data;
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
			cout << '\n';
			while (cnt--) {
				cout << output[i++];
			}
			break;
		case END:
			return;

		default:
			break;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC = 0;
	cin >> TC;
	for (register int testcase = 1; testcase <= TC; ++testcase) {
		cout << "#" << testcase << ' ';
		init();
		sol();
		cout << '\n';
	}

	return 0;
}