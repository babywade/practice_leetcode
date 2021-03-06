// practice.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <map>
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

	cout << "请输入节点个数:" << endl;
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "第" << i + 1 << "个节点的值：";
		cin >> val;
		Tail->next = new ListNode(0);
		Tail = Tail->next;
		Tail->val = val;
	}
	return Head->next;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* resHead = new ListNode(0);
	ListNode* resTail = new ListNode(0);
	resTail = resHead;
	int carry = 0;

	ListNode* head1 = l1;
	ListNode* head2 = l2;

	int len1 = 0;
	int len2 = 0;

	while (l1->next != NULL) {
		l1 = l1->next;
		len1++;
	}
	while (l2->next != NULL) {
		l2 = l2->next;
		len2++;
	}
	len1++;
	len2++;
	if (len1 > len2) {
		for (int i = 0; i < len1 - len2; i++) {
			l2->next = new ListNode(0);
			l2 = l2->next;
		}
	}
	else if (len1 < len2) {
		for (int i = 0; i < len2 - len1; i++) {
			l1->next = new ListNode(0);
			l1 = l1->next;
		}
	}
	l1 = head1;
	l2 = head2;

	while (l1 != NULL || l2 != NULL) {
		if (l1->val + l2->val + carry >= 10) {
			resTail->next = new ListNode(0);
			resTail = resTail->next;
			resTail->val = (l1->val + l2->val + carry) % 10;
			l1 = l1->next;
			l2 = l2->next;
			carry = 1;
		}
		else {
			resTail->next = new ListNode(0);
			resTail = resTail->next;
			resTail->val = l1->val + l2->val + carry;
			l1 = l1->next;
			l2 = l2->next;
			carry = 0;
		}
	}
	
	if (carry == 1) {
		resTail->next = new ListNode(0);
		resTail = resTail->next;
		resTail->val = 1;
	}
	return resHead->next;
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
		cout << node->val << "->";
		node = node->next;
	}
	cout << endl;
}

int lengthOfLongestSubstring(string s) {
	int maxlen = 1;
	set<char> ss;
	bool res;

	int count = 0;
	for (string::iterator it = s.begin(); it < s.end(); it++) {
		res = ss.insert(*it).second;
		if (res == false) {
			if (count > maxlen) {
				maxlen = count;
			}
			count = 1;
			ss.clear();
			ss.insert(*it);
		}
		count++;
	}
	cout << "maxlen:" << maxlen << endl;
	return maxlen;
}

bool isPalindrome(int x) {
	if (x < 0) {
		//cout << "false" << endl;
		return false;
	}
	if (x == 0) {
		//cout << "true" << endl;
		return true;
	}
	vector<int> bucket;
	int bit = 0;
	int src = x;
	while (x != 0) {
		bit = x % 10;
		bucket.push_back(bit);
		x /= 10;
	}
	int res = 0;
	for (size_t i = 0; i < bucket.size(); i++) {
		res = res * 10 + bucket[i];
	}
	if (res == src) {
		//cout << "true" << endl;
		return true;
	}
	else {
		//cout << "false" << endl;
		return false;
	}
}

bool isPalindrome(ListNode* head) {
	if (head == NULL) {
		return true;
	}
	int x = 0;
	ListNode* node = head;
	while (node != NULL) {
		x = x * 10 + node->val;
		node = node->next;
	}
	bool res = isPalindrome(x);
	return res;
}

int removeDuplicates(vector<int>& nums) {
	vector<int>::iterator pint = nums.begin();
	int tmp = *pint;
	int count = 0;

	while (pint <= nums.cend()) {
		if (*pint == tmp) {
			pint++;
			continue;
		}
		else {
			tmp = *pint;
			count++;
			nums[count] = *pint;
			pint++;
		}
	}
	return count;
}

int mapalindrome(string s) {
	return 0;
}

//空字符串与null的区别：
//""相当于我的钱包里没有钱;
//null相当于我没有钱包。
string longestCommonPrefix(vector<string>& strs) {
	string res = "";
	char ch;
	unsigned int min = 10000;
	if (strs.size() == 0) {
		return res;
	}
	for (size_t i = 0; i < strs.size(); i++) {
		if (strs[i].size() < min) {
			min = strs[i].size();
		}
	}
	for (int i = 0; i < min; i++) {
		ch = strs[0][i];
		for (size_t j = 0; j < strs.size(); j++) {
			if (ch == strs[j][i]) {
				continue;
			}
			else {
				return res;
			}
		}
		res.push_back(ch);
	}
	return res;
}

int romanToInt(string s) {
	map<char, int> dict = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	int res = 0;

	if (s.size() == 0) {
		return res;
	}
	char prev = ' ';
	char curr = s[0];
	for (size_t i = 0; i < s.size(); i++) {
		curr = s[i];
		if ((prev == 'I') && (curr == 'V') || (prev == 'I') && (curr == 'X')) {
			res = res + dict[curr] - 2 * dict[prev];
		} 
		else if ((prev == 'X') && (curr == 'L') || (prev == 'X') && (curr == 'C')) {
			res = res + dict[curr] - 2 * dict[prev];
		}
		else if ((prev == 'C') && (curr == 'D') || (prev == 'C') && (curr == 'M')) {
			res = res + dict[curr] - 2 * dict[prev];
		}
		else {
			res += dict[s[i]];
		}
		prev = s[i];
	}
	cout << res << endl;
	return res;
}

//测试了string.push_back()函数，是跟vector.push_back()一个行为；
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
		//ListNode* list1 = CreateList();
		//cout << "list:";
		//printlist(list1);
		//ListNode* list2 = CreateList();
		//cout << "list2:";
		//printlist(list2);
		//ListNode* resList = addTwoNumbers(list1, list2);
		//cout << "sumlist:";
		//printlist(resList);
		//string instr;
		//cin >> instr;
		//lengthOfLongestSubstring(instr);
		//int input;
		//cin >> input;
		//bool res = isPalindrome(input);
		string s;
		cin >> s;
		romanToInt(s);
	}
	return 0;
}

