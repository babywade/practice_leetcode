// practice.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
//#include <set>
//#include <list>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CreateList() {
	int len;
	int val;

	ListNode* Head = new ListNode(0);
	ListNode* Tail = new ListNode(0);
	Tail = Head;

	cout << "请输入节点个数:";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "第" << i + 1 << "个节点的值：";
		cin >> val;
		Tail->next = new ListNode(0);
		Tail = Tail->next;
		Tail->val = val;
		cout << endl;
	}
	return Head->next;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode resHead(0);
	ListNode resNode = NULL;
	resHead.next = &resNode;
	int carry = 0;

	while (l1 != NULL && l2 != NULL) {
		ListNode Node(0);
		if ((*l1).val + (*l2).val + carry >= 10) {
			(Node).val = ((*l1).val + (*l2).val + carry) % 10;
			l1 = (*l1).next;
			l2 = (*l2).next;
			resNode = Node;
			resNode = *(resNode.next);
			carry = 1;
		}
		else {
			(Node).val = (*l1).val + (*l2).val + carry;
			l1 = (*l1).next;
			l2 = (*l2).next;
			resNode = Node;
			resNode = *(resNode.next);
			carry = 0;
		}
	}
	if (l1 == NULL) {
		resNode = *l2;
	}
	else {
		resNode = *l1;
	}
	return resHead.next;
}

int reverse(int x) {
	const long int max = 2147483647;
	int res = 0;
	vector<int> s;

	while (x != 0) {
		s.push_back(x % 10);
		x = x / 10;
	}
	for (vector<int>::const_iterator it = s.cbegin(); it < s.cend(); it++) {
		if (res > max / 10 || res * 10 < -max) {
			return 0;
		}
		res *= 10;
		res += (*it);
	}

	cout << res << endl;
	return res;
}

void wiggleSort(vector<int>& nums) {
	int flag = 0;
	for (vector<int>::iterator it = nums.begin(); it < nums.end() - 1; it++) {
		if (*it < *(it + 1)) {
			if (flag == 1) {
				vector<int>::iterator it1 = it + 1;
				while (*it1 > *it) {
					it1++;
				}
				int tmp = *it1;
				*it1 = *it;
				*it = tmp;
			}
			flag = 0;
		}
		if (*it > *(it + 1)) {
			if (flag == 0) {
				vector<int>::iterator it2 = it + 1;
				while (*it2 < *it) {
					it2++;
				}
				int tmp = *it2;
				*it2 = *it;
				*it = tmp;
			}
			flag = 1;
		}
	}
}

void printvector(vector<int>& printvec) {
	cout << "[";
	for (vector<int>::const_iterator it = printvec.cbegin(); it < printvec.cend() - 1; it++) {
		cout << *it << ",";
	}
	cout << *(printvec.cend()-1) << "]" << endl;
}

void printlist(ListNode* head) {
	ListNode* node;
	node = head;
	while (node != NULL) {
		cout << (*node).val << "->";
		node = (*node).next;
	}
}

int main()
{
	while (1) {
		//vector<int> input;
		//int a;
		//while (cin >> a) {
		//	if (a == 999) {
		//		break;
		//	}
		//	input.push_back(a);
		//}
		//printvector(input);
		ListNode* list1 = CreateList();
		printlist(list1);
		ListNode* list2 = CreateList();
		printlist(list2);
		ListNode* resList = addTwoNumbers(list1, list2);
	}
	return 0;
}

