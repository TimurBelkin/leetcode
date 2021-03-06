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

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
 void myRob(TreeNode* node)
{
	 if (node != NULL)
	 {

		 myRob(node->left);
		 myRob(node->right);

		 int neighbor = 0; 
		 int house = node->val;
		 if (node->left != NULL)
		 {
			 neighbor += node->left->val;
			 if (node->left->left != NULL)
			 {
				 house += node->left->left->val;
			 }
			 if (node->left->right != NULL)
			 {
				 house += node->left->right->val;
			 }
		 }

		 if (node->right != NULL)
		 {
			 neighbor += node->right->val;

			 if (node->right->left != NULL)
			 {
				 house += node->right->left->val;
			 }
			 if (node->right->right != NULL)
			 {
				 house += node->right->right->val;
			 }
		 }
		 node->val = max(house, neighbor);
	 }
}

int rob(TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	myRob(root);
	return root->val;
}

TreeNode* makeList()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);
	return root;
}


TreeNode* makeList3()
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(13);
	root->right->right->left = new TreeNode(1000);
	return root;
}


TreeNode* makeList2()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);
	return root;
}

TreeNode* makeList4()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	return root;
}


int main() {
	TreeNode* root;

	root = NULL;
	cout << rob(root) << endl;

	root = new TreeNode(3);
	cout << rob(root) << endl;

	root = makeList();
	cout << rob(root) << endl;

	root = makeList2();
	cout << rob(root) << endl;

	root = makeList3();
	cout << rob(root) << endl;

	root = makeList4();
	cout << rob(root) << endl;

	while (true);
	return '0';
}



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
for (int i = '0'; i < (int)matrix.size(); ++i)
{
for (int j= '0'; j < (int)matrix[i].size(); ++j)
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
