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

vector<int> inorderTraversal(TreeNode* root) {
	stack<TreeNode*> path;
	TreeNode* lnode = root;
	while (lnode != NULL)
	{
		path.push((lnode));
		lnode = lnode->left;
	}
	vector<int> result;
	while (!path.empty())
	{
		TreeNode* node = path.top();
		path.pop();
		result.push_back(node->val);
		lnode = node->right;
		while (lnode != NULL)
		{
			path.push((lnode));
			lnode = lnode->left;
		}
	}
	return result;
}

bool isValidBST(TreeNode* root) {
	vector<int> inorder =  inorderTraversal(root);
	for (int iter = 1; iter < (int)inorder.size(); ++iter)
	{
		if (inorder[iter] <= inorder[iter - 1])
		{
			return false;
		}
	}
	return true;
	}

int main() {
	
	TreeNode root(2);
	cout << isValidBST(&root) << endl;
	root.left = new TreeNode(1);
	root.right = new TreeNode(3);
	cout << isValidBST(&root) << endl;
	
	TreeNode root2(10);
	root2.left = new TreeNode(5);
	//root2.left->left = new TreeNode(0);
	//cout << isValidBST(&root2) << endl;
	root2.right = new TreeNode(15);
	root2.right->right = new TreeNode(20);
	root2.right->left = new TreeNode(6);
	cout << isValidBST(&root2) << endl;

	TreeNode root3(5);
	root3.left = new TreeNode(1);
	//root2.left->left = new TreeNode(0);
	//cout << isValidBST(&root2) << endl;
	root3.right = new TreeNode(7);
	root3.right->right = new TreeNode(8);
	root3.right->left = new TreeNode(6);
	cout << isValidBST(&root3) << endl;

	//[10, 5, 15, null, null, 6, 20]

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
