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

int countOptions(vector<int>& nums, const int sum)
{
	vector<int> sumOptions (sum + 1, 0);
	sumOptions[0] = 1;
	for (int it = 0; it < nums.size(); ++it)
	{
		for (int it2 = sum; it2 >= nums[it]; --it2)
		{
			sumOptions[it2] += sumOptions[it2 - nums[it]];
		}
	}
	return sumOptions[sum];
}

int countOptions(vector<int>& nums, unsigned index,   int sum)
{
	if (index == nums.size())
	{
		if (sum == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return countOptions(nums, index + 1, sum - nums[index]) + countOptions(nums, index + 1, sum);
}

int findTargetSumWays2(vector<int>& nums, int S) {
	int sumNums = 0;
	for (int it = 0; it < nums.size(); ++it)
	{
		sumNums += nums[it];
	}
	if ((S + sumNums) & 1)
	{
		return 0;
	}
	return countOptions(nums, 0, (S + sumNums) >> 1);
}


int findTargetSumWays(vector<int>& nums, int S) {
	int sumNums = 0;
	for (int it = 0; it < nums.size(); ++it)
	{
		sumNums += nums[it];
	}
	if ((S + sumNums) & 1)
	{
		return 0;
	}
	return countOptions(nums, (S + sumNums) >> 1);
}

int main() {
	vector<int> inputData;
	int sum;
	inputData = { 1, 1, 1, 1, 1 };
	sum = 3;
	cout << findTargetSumWays(inputData, sum) << endl;
	cout << findTargetSumWays2(inputData, sum) << endl;

	inputData = {0, 0, 0 };
	sum = 3;
	cout << findTargetSumWays(inputData, sum) << endl;
	cout << findTargetSumWays2(inputData, sum) << endl;

	inputData = { 1, 4, 2, 7, 1 };
	sum = 3;
	cout << findTargetSumWays(inputData, sum) << endl;
	cout << findTargetSumWays2(inputData, sum) << endl;

	inputData = { 1, 4, 2, 7, 1 };
	sum = 0;
	cout << findTargetSumWays(inputData, sum) << endl;
	cout << findTargetSumWays2(inputData, sum) << endl;

	inputData = { 1, 4, 2, 3};
	sum = 0;
	cout << findTargetSumWays(inputData, sum) << endl;
	cout << findTargetSumWays2(inputData, sum) << endl;
	
	inputData = { 5, 4, 2, 3 };
	sum = -2;
	cout << findTargetSumWays(inputData, sum) << endl;
	cout << findTargetSumWays2(inputData, sum) << endl;
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
