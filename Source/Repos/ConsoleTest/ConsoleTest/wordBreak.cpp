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


bool wordBreak(string s, vector<string>& wordDict) {
	if (s.size() == 0)
	{
		return 0;
	}
	vector<bool> result(s.size() + 1, false);
	result[0] = true;
	for (int it = 1; it <= (int)s.size(); ++it)
	{
		for (int j = it - 1; j >= 0; --j)
		{
			if (result[j]
				&& find(wordDict.begin(), wordDict.end(), s.substr(j, it - j)) != wordDict.end())
			{
				result[it] = true;
			}
		}
	}
	return result[result.size() - 1];
}

int main() {
	vector<string> dict = { "leet", "code" };
	cout << wordBreak("leetcode", dict);

	dict = { "apple", "pen" };
	cout << wordBreak("applepenapple", dict);

	dict = { "cats", "dog", "sand", "and", "cat" };
	cout << wordBreak("catsandog", dict) << endl;

	dict = { "" };
	cout << wordBreak("catsandog", dict) << endl;

	dict = { "cats", "dog", "sand", "and", "cat" };
	cout << wordBreak("catsanddog", dict) << endl;

	dict = { "cats", "dog", "sand", "and", "cat" };
	cout << wordBreak("", dict) << endl;

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
