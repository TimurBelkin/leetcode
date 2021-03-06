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

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
	{
		return 0;
	}
	vector<vector<int>> lengths(matrix.size(), vector<int>(matrix[0].size(), 0));
	for (int it_row = 0; it_row < matrix.size(); ++it_row)
	{
		int sum = 0;
		for (int it_column = 0; it_column < matrix[it_row].size(); ++it_column)
		{
			if (matrix[it_row][it_column] == '0')
			{
				sum = 0;
			}
			else
			{
				sum += 1;
			}
			lengths[it_row][it_column] = sum;
		}
	}
	int max_square = 0;
	for (int it_column = 0; it_column < matrix[0].size(); ++it_column)
	{
		for (int it_row = 0; it_row < matrix.size(); ++it_row)
		{
			int index = it_row;
			int height = lengths[it_row][it_column];
			while (index >= 0 && lengths[index][it_column] != 0)
			{
				height = min(lengths[index][it_column], height);
				int local_square = (it_row - index + 1) * height;
				if (local_square > max_square)
				{
					max_square = local_square;
				}
				--index;
			}
		}
	}
	return max_square;
}

int main() {
	vector<vector<char>> matrix;
		matrix = {
		{ '1', '0', '1', '0', '0' },
	{ '1', '0', '1', '1', '1' },
	{ '1', '1', '1', '1', '1' },
	{ '1', '0', '0', '1', '0' }
	};
	cout << maximalRectangle(matrix) << endl;

	 matrix = {
	};
	cout << maximalRectangle(matrix) << endl;

	 matrix = {
		{ '1', '0', '1', '0', '0' }
	};
	cout << maximalRectangle(matrix) << endl;

	 matrix = {
		{ '1'}
	};
	cout << maximalRectangle(matrix) << endl;

	 matrix = {
		{ '0'}
	};
	cout << maximalRectangle(matrix) << endl;

	 matrix = {
	{ '1', '0', '1', '1', '1' },
	{ '1', '0', '1', '1', '1' },
	{ '1', '1', '1', '1', '1' },
	{ '1', '0', '0', '1', '1' }
	};
	cout << maximalRectangle(matrix) << endl;
	
	matrix = { { '1', '0', '1', '1', '1'},
			   { '0', '1', '0', '1', '0' },
			   { '1', '1', '0', '1', '1' },
			   { '1', '1', '0', '1', '1' },
			   { '0', '1', '1', '1', '1' } };
	cout << maximalRectangle(matrix) << endl;
	
	while (true);
	return 0;
}


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
