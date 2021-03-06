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

bool snake(vector<vector<char>>& board,
	vector<vector<int>>& usedCell,
	vector<pair<int, int>>& step,
	int base_y,
	int base_x,
	string& word,
	int index)
{
	if (index == (int)word.size() - 1)
	{
		return true;
	}
	for (int st_i = 0;  st_i < step.size() ; ++st_i)
	{

		int it_y = min(max(0, base_y + step[st_i].first), (int)board.size() - 1);
		int it_x = min(max(0, base_x + step[st_i].second), (int)board[0].size() - 1);
			if (usedCell[it_y][it_x] == 0 
				&& board[it_y][it_x] == word[index + 1])
			{
				usedCell[it_y][it_x] = 1;
				if (snake(board,
					usedCell,
					step,
					it_y,
					it_x,
					word,
					index + 1))
				{
					return true;
				}
				usedCell[it_y][it_x] = 0;
			
		}
	}
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0
		|| board[0].size() == 0)
	{
		return false;
	}
	if (word == "")
	{
		return true;
	}
	vector<vector<int>> usedCell(board.size(),
		vector<int>(board[0].size(), 0));
	vector<pair<int, int>> step;
	step.push_back(pair<int, int>(0, -1));
	step.push_back(pair<int, int>(1, 0));
	step.push_back(pair<int, int>(0, 1));
	step.push_back(pair<int, int>(-1, 0));
	for (int it_y = 0; it_y < board.size(); ++it_y)
	{
		for (int it_x = 0; it_x < board[0].size(); ++it_x)
		{
			if (board[it_y][it_x] == word[0])
			{
				usedCell[it_y][it_x] = 1;
				if (snake(board,
					usedCell,
					step,
					it_y,
					it_x,
					word,
					0))
				{
					return true;
				}
				usedCell[it_y][it_x] = 0;
			}
		}
	}
	return false;
}



int main() {

	vector<vector<char>> board {
		{'A', 'B', 'C', 'E'},
		{ 'S', 'F', 'C', 'S' },
		{ 'A', 'D', 'E', 'E' }
	};
	string word = "ABCCED";
	cout << exist(board, word) << endl;

	word = "SEE";
	cout << exist(board, word) << endl;

	word = "ABCB";
	cout << exist(board, word) << endl;

	board = {
	};
	word = "ABCCED";
	cout << exist(board, word) << endl;
	
	board = { {'a', 'b'},{'c', 'd'} };
	word = "abcd";
	cout << exist(board, word) << endl;
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
