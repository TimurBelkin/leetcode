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

bool isCicle(vector<vector<int>>& graph, int node, vector<int>& visited, vector<int>& onWay)
{
	if (visited[node])
	{
		return false;
	}
	visited[node] = onWay[node] = true;
	for (int it = 0; it < (int)graph[node].size(); ++it)
	{
		if (onWay[graph[node][it]] || isCicle(graph, graph[node][it], visited, onWay))
		{
			return true;
		}
	}
	return onWay[node] = false;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<vector<int>> graph(numCourses, vector<int>());
	vector<int> visited(numCourses, false);
	vector<int> onWay(numCourses, false);
	for (int it = 0; it < prerequisites.size(); ++it)
	{
		graph[prerequisites[it].second].push_back(prerequisites[it].first);
	}
	for (int it = 0; it < numCourses; ++it)
	{
		if (!visited[it] && isCicle(graph, it, visited, onWay))
		{
			return false;
		}
	}
	return true;
}





int main() {
	
	vector<pair<int, int>> prer;
	prer = {make_pair(0, 1)};
	cout << canFinish(2, prer) << endl;

	//[[1,0],[0,1]]
	prer = { make_pair(1, 0),  make_pair(0, 1) };
	cout << canFinish(2, prer) << endl;

	prer = { make_pair(2, 1),  make_pair(0, 1), make_pair(3, 2),  make_pair(3, 0) };
	cout << canFinish(4, prer) << endl;

	prer = { make_pair(0, 1), make_pair(2, 0),  make_pair(3, 2), make_pair(0, 3),  make_pair(4, 3) };
	cout << canFinish(5, prer) << endl;

	prer = { make_pair(2, 1),  make_pair(0, 1), make_pair(3, 2),  make_pair(3, 0),  make_pair(1, 3)};
	cout << canFinish(4, prer) << endl;
	
	prer = { make_pair(2, 1),  make_pair(0, 1), make_pair(3, 2),  make_pair(3, 0), make_pair(4, 3) };
	cout << canFinish(5, prer) << endl;

	while (true);
	return 0;
}



/*

void print(ListNode* input)
{
while (input != NULL)
{
cout << input->val << "->";
input = input->next;
}
cout << "NULL" << endl;
}

ListNode* hd = new ListNode(-1);
ListNode* cur = hd;
cur->next = new ListNode(5);
cur = cur->next;
cur->next = new ListNode(3);
cur = cur->next;
cur->next = new ListNode(4);
cur = cur->next;
cur->next = new ListNode(0);
cur = cur->next;
cur->next = new ListNode(-9);
cur = cur->next;
cur->next = new ListNode(-4);
cur = cur->next;
cur->next = new ListNode(7);
test = copyList(hd);
print(sortList(test));

ListNode* copyList(ListNode* input)
{
ListNode* copy = NULL;
ListNode* it = input;
ListNode* copyHead = copy;
while (it != NULL)
{
if (copy == NULL)
{
copy = new ListNode(it->val);
copyHead = copy;
}
else
{
copy->next = new ListNode(it->val);
copy = copy->next;
}
it = it->next;
}
return copyHead;
}

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
