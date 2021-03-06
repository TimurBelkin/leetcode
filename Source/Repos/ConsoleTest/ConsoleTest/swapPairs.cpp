#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>

using namespace std;



 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

	ListNode * swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode* prev = new ListNode(0);
		ListNode* first = head;
		ListNode* second = head->next;
		ListNode* begin = head->next;
		for (;;)
		{
			first->next = second->next;
			second->next = first;
			prev->next = second;
			if (first->next != NULL && first->next->next != NULL)
			{
				second = first->next->next;
				prev = first;
				first = first->next;
			}
			else
			{
				break;
			}
		}
		
		return begin;
	}



ListNode* createList(vector<int> data)
{
	if (data.size() == 0)
	{
		return NULL;
	}
	ListNode* head = new ListNode(data[0]);
	ListNode* previous = head;
	for (size_t i = 1; i < data.size(); ++i)
	{
		ListNode* new_node = new ListNode(data[i]);
		previous->next = new_node;
		previous = new_node;
	}
	return head;
}

void printList(ListNode* head)
{
	ListNode* iter = head;
	while (iter != NULL)
	{
		cout << iter->val;
		if (iter->next != NULL)
		{
			cout << "->";
		}
		else
		{
			cout << endl;
			break;
		}
		iter = iter->next;
	}
}


int main() {
	vector<int> test;
	//test.push_back(1);
	
	//test.push_back(2);
	/*
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.push_back(6);
	*/
	ListNode* head = createList(test);
	printList(head);

	ListNode* res = swapPairs(head);
	printList(res);

	while(true);
	return 0;
}