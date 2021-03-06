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

using namespace std;



int numTrees(int n) {
	if (n <= 0)
	{
		return 0;
	}
	vector<int> result;
	result.push_back(1);
	for (int it = 1; it <= n; ++it)
	{
		int sum = 0;
		for (int i2 = 0; i2 < it; ++i2)
		{
			sum += result[i2] * result[it - i2 - 1];
		}
		result.push_back(sum);
	}
	return result.back();
}

int main() {
	cout << numTrees(0) << endl;
	cout << numTrees(1) << endl;
	cout << numTrees(2) << endl;
	cout << numTrees(3) << endl;
	cout << numTrees(4) << endl;
	cout << numTrees(5) << endl;
	while (true);
	return 0;
}

/*
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
