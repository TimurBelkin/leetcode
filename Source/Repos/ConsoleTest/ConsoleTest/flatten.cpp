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

void flatten(TreeNode* root) 
{
	if (root != NULL)
	{
		while (root)
		{
			TreeNode* cur;
			if (root->left != NULL && root->right != NULL)
			{
				cur = root->left;
				while (cur->right != NULL)
				{
					cur = cur->right;
				}
				cur->right = root->right;
			}
			if (root->left != NULL)
			{
				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
	}
}



int main() {
	TreeNode* root = NULL;
	flatten(root);
	int y = 2;
	root = new TreeNode(1);
	flatten(root);
	root->right = new TreeNode(5);
	//flatten(root);
	root->right->right = new TreeNode(6);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	//flatten(root);
	/*
	vector<int> preorder;
	vector<int> inorder;
	TreeNode* root;
	
	 preorder = { 3, 9, 20, 15, 7 };
	 inorder = { 9, 3, 15, 20, 7 };
	root = buildTree(preorder, inorder);
	
	preorder = {};
	inorder = {};
	root = buildTree(preorder, inorder);

	preorder = {1};
	inorder = {1};
	root = buildTree(preorder, inorder);
	
	preorder = {3, 9, 6, 2, 1, 20, 15, 7};
	inorder = {6, 9, 1, 2, 3, 15, 20, 7};
	root = buildTree(preorder, inorder);

	preorder = { 3, 9, 6, 2, 1, 10, 5, 20, 15, 7 };
	inorder = { 6, 9, 1, 2, 5, 10, 3, 15, 20, 7 };
	root = buildTree(preorder, inorder);
	*/
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
