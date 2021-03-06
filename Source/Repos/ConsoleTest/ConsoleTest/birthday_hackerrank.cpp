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

int birthday(vector<int> s, int d, int m) {
	if (m > (int)s.size()
		|| d < 0
		|| m < 0
		|| s.size() == 0)
	{
		return 0;
	}
	int it = 0, sum = 0;
	for (; it < m; ++it)
	{
		sum += s[it];
	}
	int result = 0;

	if (sum == d)
	{
		++result;
	}

	for (; it < s.size(); ++it)
	{
		sum += s[it];
		sum -= s[it - m];
		if (sum == d)
		{
			++result;
		}
	}
	return result;
}

int main() {

	vector<int> birth = { 1, 2, 1, 3, 2 };
	cout <<	birthday(birth, 3, 2) << endl;

	birth = { 4};
	cout << birthday(birth, 4, 1) << endl;

	birth = { 1, 1, 1, 1, 1, 1, 1 };
	cout << birthday(birth, 3, 3) << endl;
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
