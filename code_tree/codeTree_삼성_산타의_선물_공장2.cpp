#include <stdio.h>
#include <unordered_map>
using namespace std;

struct BOX
{
	int belt;
	int idx;
	BOX* prev;
	BOX* next;

	BOX() {
		belt = -1;
		prev = NULL;
		next = NULL;
	}
};

struct BELT {
	BOX* head;
	BOX* tail;
	int count;
	BELT() {
		count = 0;
		head = new BOX();
		tail = new BOX();

		head->next = tail;
		tail->prev = head;

		head->prev = NULL;
		tail->next = NULL;
	}
};

int q, cmd, n, m;
unordered_map<int, BOX*> box_map;
BOX box[100000];
BELT belt[100000];

bool empty(int belt_num) {
	return (belt[belt_num].count == 0);
}

void push_back(int belt_num, BOX* _box) {
	box_map[_box->idx] = _box;

	BOX* prev = belt[belt_num].tail->prev;
	BOX* next = belt[belt_num].tail;

	_box->prev = prev;
	_box->next = next;

	prev->next = _box;
	next->prev = _box;

	++belt[belt_num].count;
}

void move(int dst, int src, BOX* from, BOX* to, int count) {
	BOX* fprev = from->prev;
	BOX* tnext = to->next;

	BOX* prev = belt[dst].head;
	BOX* next = belt[dst].head->next;

	fprev->next = tnext;
	tnext->prev = fprev;

	from->prev = prev;
	to->next = next;

	prev->next = from;
	next->prev = to;

	belt[src].count -= count;
	belt[dst].count += count;
}

void move(int dst, int src, int count) {
	BOX* from = belt[src].head->next;
	BOX* to = from;
	for (int i = 1; i < count; ++i) {
		to = to->next;
	}
	move(dst, src, from, to, count);
}

void q_100() {
	scanf("%d %d", &n, &m);
	int belt_num;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &belt_num);
		--belt_num;

		box[i].idx = i;
		box[i].belt = belt_num;
		push_back(belt_num, &box[i]);
	}
}
int q_200() {
	int src, dst;
	scanf("%d %d", &src, &dst);
	--src, --dst;
	int count = belt[src].count;
	if (count > 0) {
		BOX* from = belt[src].head->next;
		BOX* to = belt[src].tail->prev;

		move(dst, src, from, to, count);
	}
	return belt[dst].count;
}
int q_300() {
	int src, dst;
	scanf("%d %d", &src, &dst);
	--src, --dst;

	if (empty(src) && empty(dst)) {
		return 0;
	}
	else if (empty(src)) {
		move(src, dst, 1);
	}
	else if (empty(dst)) {
		move(dst, src, 1);
	}
	else {
		move(dst, src, 1);
		move(src, dst, 2);
		move(dst, src, 1);
	}

	return belt[dst].count;
}
int q_400() {
	int src, dst;
	scanf("%d %d", &src, &dst);
	--src, --dst;

	int count = belt[src].count / 2;
	if (count > 0) {
		move(dst, src, count);
	}
	return belt[dst].count;
}
int q_500() {
	int idx;
	scanf("%d", &idx);
	--idx;

	BOX* item = box_map[idx];
	BOX* prev = item->prev;
	BOX* next = item->next;

	int a = (prev->belt == -1) ? (-1) : (prev->idx + 1);
	int b = (next->belt == -1) ? (-1) : (next->idx + 1);

	return (a + (b * 2));
}
int q_600() {
	int belt_num;
	scanf("%d", &belt_num);
	--belt_num;

	BOX* begin = belt[belt_num].head->next;
	BOX* end = belt[belt_num].tail->prev;

	int a = (begin->belt == -1) ? (-1) : (begin->idx + 1);
	int b = (end->belt == -1) ? (-1) : (end->idx + 1);
	int c = belt[belt_num].count;

	return (a + (b * 2) + (c * 3));
}

void sol() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 100:
			q_100();
			break;
		case 200:
			printf("%d\n", q_200());
			break;
		case 300:
			printf("%d\n", q_300());
			break;
		case 400:
			printf("%d\n", q_400());
			break;
		case 500:
			printf("%d\n", q_500());
			break;
		case 600:
			printf("%d\n", q_600());
			break;
		}
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();
	return 0;
}