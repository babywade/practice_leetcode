#pragma once

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <set>
#include <list>

#define MAX 20

using namespace std;

void testBST();
void newcode1();
void testconstruct();
void Leetcode1();
void Leetcode15();
void printgroup(std::list<int>& a);
std::vector<int> removal(std::vector<int>& a);

int *SumArray(int* pa, int* pb, int* len) {
	int* r[MAX] = { NULL };
	if (len <= 0) {
		return NULL;
	}
	r[MAX] = (int*)malloc(sizeof(int) * *len); //malloc返回的是void*类型指针，需要强制类型转换为int*；
											   //new返回指定类型的指针，并且可以自动计算所需要的内存大小；
											   //malloc只管分配内存，并不能对所得到的内存进行初始化，所以得到的内存中值是随机的；

	for (int i = 0; i < *len; i++) {
		*r[i] = *pa + *pb;
		pa = pa + sizeof(int);
		pb = pb + sizeof(int);
	}
	return r[0];
}

void Leetcode1() {
	vector<int> res;
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;

	int a, b;
	for (vector<int>::const_iterator it1 = nums.cbegin(); it1 < nums.cend() - 1; it1++) {
		a = *it1;
		for (vector<int>::const_iterator it2 = it1 + 1; it2 < nums.cend(); it2++) {
			b = *it2;
			if (a + b == target) {
				res.push_back(it1 - nums.cbegin());
				res.push_back(it2 - nums.cbegin());
			}
		}
	}
	cout << res[0] << " " << res[1] << endl;
}

vector<int> removal(vector<int>& a) {
	vector<int> rem;
	return rem;
}

void printgroup(set<int>& a) {
	for (set<int>::iterator it = a.cbegin(); it != a.cend(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		vector<int> right_sub_tree;
		vector<int> left_sub_tree;
		int len = sequence.cend() - sequence.cbegin();
		int count = 0;

		if (len == 0) {
			return true;
		}

		for (int i = 0; i < len; i++) {
			if (sequence[i] < sequence[len - 1]) {
				count++;
				right_sub_tree.push_back(sequence[i]);
				continue;
			}
			else {
				break;
			}
		}
		while (count < len) {
			if (sequence[count] > sequence[len - 1]) {
				count++;
				left_sub_tree.push_back(sequence[count]);
				continue;
			}
			else {
				break;
			}
		}
		if (count + 1 == len) {
			return VerifySquenceOfBST(right_sub_tree) && VerifySquenceOfBST(left_sub_tree) && true;
		}
		else {
			return false;
		}
	}

	int removeDuplicates(vector<int>& nums) {
		vector<int>::iterator pint = nums.begin();
		int tmp;
		int count = 0;

		while (pint <= nums.cend()) {
			tmp = *pint;
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
};

class base1 {
private: int a, b;
public:
	base1(int i) : b(i + 1), a(b) {}
	base1() :b(0), a(b) {}
	int get_a() { return a; }
	int get_b() { return b; }
};

void testBST() {
	vector<int> s;
	int a;
	int num = 7;
	for (int i = 0; i < num; i++) {
		cin >> a;
		s.push_back(a);
	}
	Solution solution;
	bool res = solution.VerifySquenceOfBST(s);
	cout << "res: " << res << endl;
}

void newcode1() {
	int arr[] = { 1,2,3,4,5,6,7 };
	int *p = arr;
	*(p++) += 89;
	printf("%d\n", *p);
	printf("%d,%d\n", *p, *(++p));

	int *a = arr;
	cout << "arr数组:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << *a << " ";
		a++;
	}
}

void testconstruct() {
	base1 obj1(11);
	cout << obj1.get_a() << endl << obj1.get_b() << endl;
}

void Leetcode15() {
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	list<int> group;
	vector<list<int>> res;

	int a, b, c;
	for (vector<int>::const_iterator it1 = nums.cbegin(); it1 < nums.cend() - 2; it1++) {
		a = *it1;
		for (vector<int>::const_iterator it2 = it1 + 1; it2 < nums.cend() - 1; it2++) {
			b = *it2;
			for (vector<int>::const_iterator it3 = it2 + 1; it3 < nums.cend(); it3++) {
				c = *it3;
				if (a + b + c == 0) {
					group.push_back(a);
					group.push_back(b);
					group.push_back(c);
					res.push_back(group);
					group.pop_back;
					group.pop_back;
					group.pop_back;
				}
			}
		}
	}

	for (size_t i = 0; i < res.size(); i++) {
		group = res[i];
		printgroup(group);
	}
}