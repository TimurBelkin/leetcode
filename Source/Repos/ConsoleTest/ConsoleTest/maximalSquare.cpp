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


int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
	{
		return 0;
	}
	vector<int> lowRightCorner = vector<int>(matrix[0].size(), 0);
	int result = 0;
	for (int it = 0; it < matrix[0].size(); ++it)
	{
		lowRightCorner[it] = matrix[0][it] - '0';
		result = max(result, lowRightCorner[it]);
	}
	vector<int> curr;
	for (int it_str = 1; it_str < matrix.size(); ++it_str)
	{
		curr = vector<int>(matrix[0].size(), 0);
		curr[0] = matrix[it_str][0] - '0';
		result = max(result, curr[0]);
		for (int it_clmn = 1; it_clmn < matrix[0].size(); ++it_clmn)
		{
			if (matrix[it_str][it_clmn] == '1')
			{
				curr[it_clmn] = min(curr[it_clmn - 1], min(lowRightCorner[it_clmn - 1], lowRightCorner[it_clmn])) + 1;
				result = max(result, curr[it_clmn]);
			}
		}
		lowRightCorner = curr;
	}
	return result * result;
}

int main() {
	vector<vector<char>> matrix;
	
	matrix = { { '1','0','1','0','0' },
	{ '1','0','1','1','1' },
	{ '1','1','1','1','1' },
	{ '1','0','0','1','0' }
	};

	cout << maximalSquare(matrix) << endl;

	matrix = { { '0','1','1','1','1'},
			   { '0','1','1','1','1'},
			   { '0','1','1','1','1'},
			   { '0','1','1','1','1'} 
	};

	cout << maximalSquare(matrix) << endl;

	matrix = { { '0','0','0','1','0' }};

	cout << maximalSquare(matrix) << endl;
	matrix = {};

	cout << maximalSquare(matrix) << endl;

	matrix = {  { '1', '0', '1', '0', '0' },
				{ '1', '0', '1', '1', '1' },
				{ '1', '1', '1', '1', '1' },
				{ '1', '0', '0', '1', '0' } };
	cout << maximalSquare(matrix) << endl;
	
	matrix = {  { '1', '0', '1', '1', '0', '1' },
				{ '1', '1', '1', '1', '1', '1' },
				{ '0', '1', '1', '0', '1', '1' },
				{ '1', '1', '1', '0', '1', '0' },
				{ '0', '1', '1', '1', '1', '1' },
				{ '1', '1', '0', '1', '1', '1' }};
	cout << maximalSquare(matrix) << endl;

	while (true);
	return '0';
}



/*

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
