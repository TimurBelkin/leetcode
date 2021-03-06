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

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
void print(ListNode* input)
{
	while (input != NULL)
	{
		cout << input->val << "->";
		input = input->next;
	}
	cout << "NULL" << endl;
}

int maxProduct(vector<int>& nums) {
	if (nums.size() == 0)
	{
		return 0;
	}
	long max = nums[0], max_neg = 0, max_pos = 0;
	if (nums[0] > 0)
	{
		max_pos = nums[0];
	}
	else
	{
		max_neg = nums[0];
	}
	for (int it = 1; it < nums.size(); ++it)
	{
		if (nums[it] == 0)
		{
			max_neg = max_pos = 0;
		}
		else if (nums[it] > 0)
		{
			max_neg *= nums[it];
			if (max_pos == 0)
			{
				max_pos = nums[it];
			}
			else
			{
				max_pos *= nums[it];
			}
		}
		else
		{
			int prev_max_pos = max_pos;
			max_pos = max_neg * nums[it];
			if (prev_max_pos == 0)
			{
				max_neg = nums[it];
			}
			else
			{
				max_neg = nums[it] * prev_max_pos;
			}
		}
		if (max_pos > max)
		{
			max = max_pos;
		}
	}
	return max;
}


int main() {

	
	//[2,3,-2,4]
	//[-2,0,-1]

	vector<int> test;
	test = { 2,3,-2,4 };
	cout << maxProduct(test) << endl;
	test = { -2,0,-1 };
	cout << maxProduct(test) << endl;
	test = { -2};
	cout << maxProduct(test) << endl;
	test = { -2,0};
	cout << maxProduct(test) << endl;
	
	test = { -2,-3,-5 };
	cout << maxProduct(test) << endl;
	test = { 1, 3,-2, 8 };
	cout << maxProduct(test) << endl;

	test = { 1, 3,-2, 8, 9, 0, 5, -2, -1, 4, 8, -3, -2 };
	cout << maxProduct(test) << endl;

	while (true);
	return 0;
}



/*

ListNode* hd = new ListNode(-1);
ListNode* cur = hd;
cur->next = new ListNode(5);
cur = cur->next;
cur->next = new ListNode(3);
cur = cur->next;
cur->next = new ListNode(4);
cur = cur->next;
cur->next = new ListNode(0);
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

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
/*
void printMatrix(vector<vector<int>> matrix)
{
for (int i = 0; i < (int)matrix.size(); ++i)
{
for (int j= 0; j < (int)matrix[i].size(); ++j)
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
if (x == (int)grid.size() - 1
&& y == (int)grid[0].size() - 1)
{
++result;
}
else
{
if (x < (int)grid.size() - 1 && grid[x + 1][y] != 1)
{
minotaurMaze(grid, x + 1, y, result);
}
if (y < (int)grid[0].size() - 1 && grid[x][y + 1] != 1)
{
minotaurMaze(grid, x, y + 1, result);
}
}
}
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
if (grid.size() == 0
|| grid[0].size() == 0
|| grid[0][0] == 1)
{
return 0;
}
int result = 0;
(grid, 0, 0, result);
return result;
}

int paths(vector<vector<int>>& grid,
int x,
int y)
{
if (x == 0 && y == 0)
{
return grid[0][0] == 1 ? 0 : 1;
}
else
{
if (grid[x][y] == 1)
{
return 0;
}
else
{
return paths(grid, x - 1, y) + paths(grid, x, y - 1);
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
ListNode * begin_p = new ListNode(0);
ListNode * prev_p = begin_p;
for (int it = 1; it < n; ++it)
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
for (ListNode* node = begin->next; node != NULL; node = node->next)
{
cout << "->" << node->val;
}
cout << endl;
}
*/
