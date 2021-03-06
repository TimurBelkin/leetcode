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
#include <numeric>
#include <bitset>
#include <thread>
#include <mutex>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* oddEvenList(ListNode* head) {
	if (head == NULL) return head;
	ListNode* end_current = head;
	int count = 1;
	while (end_current->next != NULL)
	{
		++count;
		end_current = end_current->next;
	}
	if (count < 3) return head;
	ListNode* end = end_current, *odd = head, *even = odd->next;
	while (true)
	{
		odd->next = even->next;
		even->next = NULL;
		end_current->next = even;
		end_current = end_current->next;
		odd = odd->next;
		even = odd->next;
		if (odd == end)
		{
			break;
		}
		else if (even == end)
		{
			end = end->next;
		}
	}
	return head;
}

void printList(const ListNode* begin)
{
	if (begin == NULL)
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << begin->val;
		for (ListNode* Node = begin->next; Node != NULL; Node = Node->next)
		{
			cout << "->" << Node->val;
		}
		cout << endl;
	}
	cout << endl;
}



ListNode* copyList(const ListNode* input)
{
	ListNode* copy = NULL;
	const ListNode* it = input;
	ListNode* copyHead = copy;
	while (it != NULL)
	{
		if (copy == NULL)
		{
			copy = new ListNode(it->val);
			copyHead = copy;
		}
		else
		{
			copy->next = new ListNode(it->val);
			copy = copy->next;
		}
		it = it->next;
	}
	return copyHead;
}


int main() {
	ListNode* head = NULL;

	ListNode* copy = copyList(head);

	printList(copy);
	oddEvenList(copy);
	printList(copy);

	head = new ListNode(1);
	copy = copyList(head);
	printList(copy);
	oddEvenList(copy);
	printList(copy);

	head->next = new ListNode(2);
	copy = copyList(head);
	printList(copy);
	oddEvenList(copy);
	printList(copy);

	head->next->next = new ListNode(3);
    copy = copyList(head);
	printList(copy);
	oddEvenList(copy);
	printList(copy);

	head->next->next->next = new ListNode(4);
	copy = copyList(head);
	printList(copy);
	oddEvenList(copy);
	printList(copy);

	head->next->next->next->next = new ListNode(5);
	copy = copyList(head);
	printList(copy);
	oddEvenList(copy);
	printList(copy);

	head->next->next->next->next->next = new ListNode(6);
	copy = copyList(head);
	printList(copy);
	oddEvenList(copy);
	printList(copy);

	while (true);
	return '0';
}

/*
int prev = 0;
for (int i = 0; i < board.size(); ++i)
{
for (int j = 0; j < board[0].size(); ++j)
{
int new_num = 0;

if (i < board.size() - 1)
{
for (int j1 = max(j - 1, 0); j1 <= min(j + 1, (int)(board[0].size() - 1)); ++j1)
{
new_num += (board[i + 1][j1] & 1);
}
}

if (j > 0)
{
new_num += ((board[i][j - 1] & 1) & (board[i][j - 1] & 2));
board[i][j - 1] = prev;
}

if (j < board[0].size() - 1)
{
new_num += ((board[i][j + 1] & 1) & (board[i][j + 1] & 2));
prev = new_num;
}
else
{
prev = 0;
board[i][j + 1]
}

}
}

*/

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

void print(ListNode* input)
{
while (input != NULL)
{
cout << input->val << "->";
input = input->next;
}
cout << "NULL" << endl;
}

ListNode* hd = new ListNode(-'1');
ListNode* cur = hd;
cur->next = new ListNode(5);
cur = cur->next;
cur->next = new ListNode(3);
cur = cur->next;
cur->next = new ListNode(4);
cur = cur->next;
cur->next = new ListNode('0');
cur = cur->next;
cur->next = new ListNode(-9);
cur = cur->next;
cur->next = new ListNode(-4);
cur = cur->next;
cur->next = new ListNode(7);
test = copyList(hd);
print(sortList(test));

ListNode* copyList(ListNode* input)
{
ListNode* copy = NULL;
ListNode* it = input;
ListNode* copyHead = copy;
while (it != NULL)
{
if (copy == NULL)
{
copy = new ListNode(it->val);
copyHead = copy;
}
else
{
copy->next = new ListNode(it->val);
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

struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}

};


ListNode * makeList(int n)
{
ListNode * begin_p = new ListNode('0');
ListNode * prev_p = begin_p;
for (int it = '1'; it < n; ++it)
{
ListNode * new_p =  new ListNode(it);
prev_p->next = new_p;
prev_p = new_p;
}
return begin_p;
}
void printList(ListNode * begin)
{
cout << begin->val;
for (ListNode* TNode = begin->next; TNode != NULL; TNode = TNode->next)
{
cout << "->" << TNode->val;
}
cout << endl;
}
*/
