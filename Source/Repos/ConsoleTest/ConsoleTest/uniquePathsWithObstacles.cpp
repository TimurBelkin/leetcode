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

void minotaurMaze(vector<vector<int>>& obstacleGrid,
	int x,
	int y,
	int& result)
{
	if (x == (int)obstacleGrid.size() - 1
		&& y == (int)obstacleGrid[0].size() - 1)
	{
		++result;
	}
	else
	{
		if (x < (int)obstacleGrid.size() - 1 && obstacleGrid[x + 1][y] != 1)
		{
			minotaurMaze(obstacleGrid, x + 1, y, result);
		}
		if (y < (int)obstacleGrid[0].size() - 1 && obstacleGrid[x][y + 1] != 1)
		{
			minotaurMaze(obstacleGrid, x, y + 1, result);
		}
	}
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.size() == 0 
		|| obstacleGrid[0].size() == 0
		|| obstacleGrid[0][0] == 1)
	{
		return 0;
	}

	vector<vector<int>> pathsNumber(obstacleGrid.size(),
		vector<int>(obstacleGrid[0].size(), 0));


	for (int it = 0; it < obstacleGrid[0].size(); ++it)
	{
		if (obstacleGrid[0][it] == 1)
		{
			break;
		}
		pathsNumber[0][it] = 1;
	}



	for (int it = 0; it < obstacleGrid.size(); ++it)
	{
		if (obstacleGrid[it][0] == 1)
		{
			break;
		}
		pathsNumber[it][0] = 1;
	}

	int t = obstacleGrid.size();
	int p = obstacleGrid[0].size();

	if (obstacleGrid.size() > 1
		&& obstacleGrid[0].size() > 1)
	{
		for (int it_y = 1; it_y < obstacleGrid.size(); ++it_y)
		{
			for (int it_x = 1; it_x < obstacleGrid[0].size(); ++it_x)
			{
				if (obstacleGrid[it_y][it_x] == 1)
				{
					pathsNumber[it_y][it_x] == 0;
				}
				else
				{
					pathsNumber[it_y][it_x] = pathsNumber[it_y - 1][it_x]
						+ pathsNumber[it_y][it_x - 1];
				}
			}
		}
	}

	return pathsNumber[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}



int main() {
	
	vector<vector<int>> obstackleGrid = {
		{0, 0, 0},
			{0, 1, 0},
			{0, 0, 0}
};
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
	*/
	obstackleGrid = { {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, { 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 }, { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 }, { 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }, { 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1 }, { 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1 }, { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1 }, { 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }, { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 }};
	cout << uniquePathsWithObstacles(obstackleGrid) << endl;
	
	while (true);
	return 0;
}


/*
void minotaurMaze(vector<vector<int>>& obstacleGrid,
int x,
int y,
int& result)
{
if (x == (int)obstacleGrid.size() - 1
&& y == (int)obstacleGrid[0].size() - 1)
{
++result;
}
else
{
if (x < (int)obstacleGrid.size() - 1 && obstacleGrid[x + 1][y] != 1)
{
minotaurMaze(obstacleGrid, x + 1, y, result);
}
if (y < (int)obstacleGrid[0].size() - 1 && obstacleGrid[x][y + 1] != 1)
{
minotaurMaze(obstacleGrid, x, y + 1, result);
}
}
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
if (obstacleGrid.size() == 0
|| obstacleGrid[0].size() == 0
|| obstacleGrid[0][0] == 1)
{
return 0;
}
int result = 0;
(obstacleGrid, 0, 0, result);
return result;
}

int paths(vector<vector<int>>& obstacleGrid,
int x,
int y)
{
if (x == 0 && y == 0)
{
return obstacleGrid[0][0] == 1 ? 0 : 1;
}
else
{
if (obstacleGrid[x][y] == 1)
{
return 0;
}
else
{
return paths(obstacleGrid, x - 1, y) + paths(obstacleGrid, x, y - 1);
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
