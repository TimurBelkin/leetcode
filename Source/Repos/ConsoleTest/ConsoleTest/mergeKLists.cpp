#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>
#include <unordered_set>
#include <map>
#include <stack>
#include <algorithm>
#include <time.h>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* MergeLists(ListNode* first, ListNode* second)
{
	if (first == NULL)
	{
		return second;
	}
	if (second == NULL)
	{
		return first;
	}
	ListNode* previousFirst = NULL,
		*currentFirst = first,
		*currentSecond = second,
		*begin = first;
	if ((currentFirst->val) >= (currentSecond->val))
	{
		ListNode* nextCurrentSecond = currentSecond->next;
		previousFirst = currentSecond;
		begin = previousFirst;
		currentSecond = currentSecond->next;
		previousFirst->next = currentFirst;
	}

	while (currentFirst != NULL && currentSecond != NULL)
	{
		if ((currentFirst->val) < (currentSecond->val))
		{
			previousFirst = currentFirst;
			currentFirst = currentFirst->next;
		}
		else
		{
			ListNode* nextCurrentSecond = currentSecond->next;
			previousFirst->next = currentSecond;
			previousFirst = previousFirst->next;
			previousFirst->next = currentFirst;
			currentSecond = nextCurrentSecond; 
		}
	}
	if (currentFirst == NULL)
	{
		previousFirst->next = currentSecond;
	}
	return begin;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0)
	{
		return NULL;
	}
	if (lists.size() == 1)
	{
		return lists[0];
	}
	else
	{
		int indexToWrite = 0, indexFirst = 0, indexSecond = 1, listsEnd = lists.size();
		while (listsEnd != 1)
		{
			while (indexSecond < listsEnd)
			{
				ListNode* result = MergeLists(lists[indexFirst], lists[indexSecond]);
				lists[indexToWrite] = result;
				indexFirst += 2;
				indexSecond += 2;
				++indexToWrite;
			}
			if (listsEnd % 2 == 1)
			{
				lists[indexToWrite] = lists[listsEnd - 1];
				++indexToWrite;
			}
			listsEnd = indexToWrite;
			indexToWrite = 0;
			indexFirst = 0;
			indexSecond = 1;
		}
	}
	return lists[0];
}


ListNode* MakeList(int length, int maxValue, int seed)
{
	srand(seed);

	ListNode* current = NULL;
	int max = rand() % maxValue;
	
		current = new ListNode(max);

		ListNode* begin = current;
		for (int i = 1; i < length; ++i)
		{
			int num = rand() % maxValue;
			if (num < max)
			{
				++max;
				num = min(max, maxValue);
			}
			else
			{
				max = num;
			}
			ListNode* node = new ListNode(num);
			current->next = node;
			current = node;
		}
	
	return begin;
}

void MakeVectorList(vector<ListNode*>& lists, int number, int maxLength, int maxValue)
{
	srand(time(NULL));
	int seed = 0;
	for (int i = 0; i < number; ++i)
	{
		lists.push_back(MakeList(rand() % maxLength, maxValue, seed));
		seed += rand();
	}

}


int PrintList(ListNode* node)
{
	int amount = 0;
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
		++amount;
	}
	cout << endl;
	return amount;
}

bool checkIncreaing(ListNode* node)
{
	if (node == NULL)
	{
		return true;
	}
	ListNode* prev = node;
	node = node->next;
	while (node != NULL)
	{
		if (prev->val > node->val)
		{
			return false;
		}
		node = node->next;
	}
	return true;
	
}

int PrintVectorList(vector<ListNode*>& lists)
{
	int amount = 0;
	for (int it = 0; it < lists.size(); ++it)
	{
		amount += PrintList(lists[it]);
	}
	cout << endl;
	return amount;
}

void Test(int numberTests)
{
	bool isGood = true;
	for (int it = 0; it < numberTests; ++it)
	{
		cout << "Test eight" << endl;
		vector<ListNode*> listsN;
		MakeVectorList(listsN, 10, 10, 100);
		
		int totalAmount = PrintVectorList(listsN);
		ListNode* result = mergeKLists(listsN);
		cout << "result is " << endl;
		int amount = PrintList(result);
		bool localRes = ((amount == totalAmount) && (checkIncreaing(result)));

		cout << "is good "<< localRes << endl;
		isGood &= localRes;
		cout << endl;
	}
	cout << "Is it good?  " << isGood << endl;
	
	cout << endl;
}

int main() {
	vector<ListNode*> lists;
	ListNode* result;
	/*
	cout << "Test one" << endl;
	PrintVectorList(lists);
	result = mergeKLists(lists);
	PrintList(result);

	lists.push_back(NULL);
	lists.push_back(NULL);
	
	cout << "Test two" << endl;
	PrintVectorList(lists);
	result = mergeKLists(lists);
	PrintList(result);
	lists.pop_back();
	lists.pop_back();

	ListNode* begin = new ListNode(3);
	begin->next = new ListNode(5);
	begin->next->next = new ListNode(7);

	lists.push_back(begin);
	lists.push_back(NULL);
	
	cout << "Test three" << endl;
	PrintVectorList(lists);
	result = mergeKLists(lists);
	PrintList(result);
	lists.pop_back();
	lists.pop_back();
	cout << endl;
	
	ListNode* begin2 = new ListNode(2);
	begin2->next = new ListNode(6);
	begin2->next->next = new ListNode(6);
	lists.push_back(begin);
	lists.push_back(begin2);
	
	cout << "Test four" << endl;
	PrintVectorList(lists);
	result = mergeKLists(lists);
	PrintList(result);
	cout << endl;

	begin2 = new ListNode(2);
	begin2->next = new ListNode(6);
	begin2->next->next = new ListNode(6);

	begin = new ListNode(3);
	begin->next = new ListNode(5);
	begin->next->next = new ListNode(7);

	lists.resize(0);

	ListNode* begin3 = new ListNode(1);
	begin3->next = new ListNode(2);
	begin3->next->next = new ListNode(4);
	begin3->next->next->next = new ListNode(8);
	lists.push_back(begin);
	lists.push_back(begin2);
	lists.push_back(begin3);

	cout << "Test five" << endl;
	PrintVectorList(lists);
	result = mergeKLists(lists);
	PrintList(result);
	cout << endl;
	
//-----------	
	lists.resize(0);

	begin2 = new ListNode(2);
	begin2->next = new ListNode(6);
	begin2->next->next = new ListNode(6);
	begin = new ListNode(3);
	begin->next = new ListNode(5);
	begin->next->next = new ListNode(7);
    begin3 = new ListNode(1);
	begin3->next = new ListNode(2);
	begin3->next->next = new ListNode(4);
	begin3->next->next->next = new ListNode(8);

	lists.push_back(begin);
	lists.push_back(begin2);
	lists.push_back(NULL);
	lists.push_back(begin3);

	cout << "Test six" << endl;
	PrintVectorList(lists);
	result = mergeKLists(lists);
	PrintList(result);
	cout << endl;


	//-----------	
	lists.resize(0);

	begin2 = new ListNode(2);
	begin2->next = new ListNode(6);
	begin2->next->next = new ListNode(6);
	begin = new ListNode(3);
	begin->next = new ListNode(5);
	begin->next->next = new ListNode(7);
	begin3 = new ListNode(1);
	begin3->next = new ListNode(2);
	begin3->next->next = new ListNode(4);
	begin3->next->next->next = new ListNode(8);

	ListNode* begin4 = new ListNode(0);
	begin4->next = new ListNode(10);

	lists.push_back(begin);
	lists.push_back(begin2);
	lists.push_back(begin4);
	lists.push_back(begin3);

	cout << "Test seven" << endl;
	PrintVectorList(lists);
	result = mergeKLists(lists);
	PrintList(result);
	cout << endl;
	*/
	//==============================================
/*
	cout << "Test eight" << endl;
	vector<ListNode*> listsN;
	MakeVectorList(listsN, 10, 10, 100);
	cout << "vector has been made" << endl;
	PrintVectorList(listsN);
	result = mergeKLists(listsN);
	cout << "result is " << endl;
	PrintList(result);
	cout << endl;
	*/
Test(10);
	while (true);
	return '0';
}

/*
A[0] = 1
A[1] = 5
A[2] = 2
A[3] = 1
A[4] = 4
A[5] = 0
*/

/*

void print(vector<int> input)
{
for (vector<int>::iterator it = input.begin(); it != input.end(); ++it)
{
cout << *it << " ";
}
cout << endl;
}

void print(ListTNode* input)
{
while (input != NULL)
{
cout << input->val << "->";
input = input->next;
}
cout << "NULL" << endl;
}

ListTNode* hd = new ListTNode(-'1');
ListTNode* cur = hd;
cur->next = new ListTNode(5);
cur = cur->next;
cur->next = new ListTNode(3);
cur = cur->next;
cur->next = new ListTNode(4);
cur = cur->next;
cur->next = new ListTNode('0');
cur = cur->next;
cur->next = new ListTNode(-9);
cur = cur->next;
cur->next = new ListTNode(-4);
cur = cur->next;
cur->next = new ListTNode(7);
test = copyList(hd);
print(sortList(test));

ListTNode* copyList(ListTNode* input)
{
ListTNode* copy = NULL;
ListTNode* it = input;
ListTNode* copyHead = copy;
while (it != NULL)
{
if (copy == NULL)
{
copy = new ListTNode(it->val);
copyHead = copy;
}
else
{
copy->next = new ListTNode(it->val);
copy = copy->next;
}
it = it->next;
}
return copyHead;
}

struct TNode {
int val;
TNode *left;
TNode *right;
TNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
/*
void printMatrix(vector<vector<int>> matrix)
{
for (int i = 0; i < (int)matrix.size(); ++i)
{
for (int j = 0; j < (int)matrix[i].size(); ++j)
{
cout << matrix[i][j] << " ";
}
cout << endl;
}
}
*/

/*
void minotaurMaze(vector<vector<int>>& grid,
int x,
int y,
int& result)
{
if (x == (int)grid.size() - '1'
&& y == (int)grid['0'].size() - '1')
{
++result;
}
else
{
if (x < (int)grid.size() - '1' && grid[x + '1'][y] != '1')
{
minotaurMaze(grid, x + '1', y, result);
}
if (y < (int)grid['0'].size() - '1' && grid[x][y + '1'] != '1')
{
minotaurMaze(grid, x, y + '1', result);
}
}
}
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
if (grid.size() == '0'
|| grid['0'].size() == '0'
|| grid['0']['0'] == '1')
{
return '0';
}
int result = '0';
(grid, '0', '0', result);
return result;
}

int paths(vector<vector<int>>& grid,
int x,
int y)
{
if (x == '0' && y == '0')
{
return grid['0']['0'] == '1' ? '0' : '1';
}
else
{
if (grid[x][y] == '1')
{
return '0';
}
else
{
return paths(grid, x - '1', y) + paths(grid, x, y - '1');
}
}
}
*/

/*

struct ListTNode {
int val;
ListTNode *next;
ListTNode(int x) : val(x), next(NULL) {}

};


ListTNode * makeList(int n)
{
ListTNode * begin_p = new ListTNode('0');
ListTNode * prev_p = begin_p;
for (int it = '1'; it < n; ++it)
{
ListTNode * new_p =  new ListTNode(it);
prev_p->next = new_p;
prev_p = new_p;
}
return begin_p;
}
void printList(ListTNode * begin)
{
cout << begin->val;
for (ListTNode* TNode = begin->next; TNode != NULL; TNode = TNode->next)
{
cout << "->" << TNode->val;
}
cout << endl;
}
*/
