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

int minPathSum(vector<vector<int>>& grid) {
	if (grid.size() == 0
		|| grid[0].size() == 0)
	{
		return 0;
	}

	vector<vector<int>> pathsNumber(grid.size(),
		vector<int>(grid[0].size(), 0));
	pathsNumber[0][0] = grid[0][0];

	for (int it = 1; it < grid[0].size(); ++it)
	{
		pathsNumber[0][it] = grid[0][it] + pathsNumber[0][it - 1];
	}



	for (int it = 1; it < grid.size(); ++it)
	{

		pathsNumber[it][0] = grid[it][0] + pathsNumber[it - 1][0];
	}

	if (grid.size() > 1
		&& grid[0].size() > 1)
	{
		for (int it_y = 1; it_y < grid.size(); ++it_y)
		{
			for (int it_x = 1; it_x < grid[0].size(); ++it_x)
			{
				pathsNumber[it_y][it_x] = 
					min(pathsNumber[it_y - 1][it_x] + grid[it_y][it_x],
						pathsNumber[it_y][it_x - 1] + grid[it_y][it_x]);
				
			}
		}
	}

	return pathsNumber[grid.size() - 1][grid[0].size() - 1];
}



int main() {

	vector<vector<int>> grid = {
		{ 1, 3, 1 },
	{ 1, 5, 1 },
	{ 4, 2, 1 }
	};
	cout << minPathSum(grid) << endl;

	grid = {
		{3}
	};
	cout << minPathSum(grid) << endl;

	 grid = {
	{ 1, 3, 1, 1 },
	{ 1, 1, 1, 1 },
	{ 4, 2, 1, 2 },
	{ 4, 2, 5, 1 }
	};
	cout << minPathSum(grid) << endl;

	/*
	//cout << uniquePathsWithObstacles(obstackleGrid) << endl;

	obstackleGrid = {
	{ 0, 0, 0 }
	};
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;

	obstackleGrid = {
	{ 0, 1, 0 },
	};
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;

	obstackleGrid = {
	{ 0}
	};
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;

	obstackleGrid = {
	{ 1 }
	};
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;

	obstackleGrid = {
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 1 }
	};
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;

	obstackleGrid = {
	{ 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0}
	};
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;

	obstackleGrid = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 1, 0 },
	{ 0, 0, 1, 0 }
	};
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;
	
	obstackleGrid = { { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },{ 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },{ 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },{ 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1 },{ 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 },{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1 },{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1 },{ 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 } };
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;
	*/
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
