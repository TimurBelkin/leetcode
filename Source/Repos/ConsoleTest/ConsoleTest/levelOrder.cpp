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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<TreeNode*> nodes;
	if (root != NULL)
	{
		nodes.push_back(root);
	}
	vector<vector<int>> result;
	while (nodes.size() != 0)
	{
		vector<int> element;
		vector<TreeNode*> new_nodes;
		for (int it = 0; it < (int)nodes.size(); ++it)
		{
			element.push_back(nodes[it]->val);
			if (nodes[it]->left != NULL)
			{
				new_nodes.push_back(nodes[it]->left);
			}
			if (nodes[it]->right != NULL)
			{
				new_nodes.push_back(nodes[it]->right);
			}
		}
		result.push_back(element);
		nodes = new_nodes;
	}
	return result;
}

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

int main() {
	
	TreeNode root(3);
	root.left = new TreeNode(9);
	root.left->left = new TreeNode(12);
	root.left->left->right = new TreeNode(22);
	root.right = new TreeNode(20);
	root.right->left = new TreeNode(15);
	root.right->right = new TreeNode(7);

	printMatrix(levelOrder(&root));

	TreeNode root1(3);
	printMatrix(levelOrder(&root1));
	//root.left = new TreeNode(9);
	root1.right = new TreeNode(20);
	root1.right->left = new TreeNode(15);
	//root.right->right = new TreeNode(7);

	printMatrix(levelOrder(&root1));

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
