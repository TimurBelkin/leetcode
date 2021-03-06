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
#include <unordered_map>
#include <numeric>
#include <bitset>
#include <thread>
#include <mutex>
using namespace std;



void printMatrix(const vector<vector<int>>& matrix)
{
	for (int i = 0; i < (int)matrix.size(); ++i)
	{
		for (int j = 0; j < (int)matrix[i].size(); ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


int getNeighborNumber(const vector<vector<int>>& board, int i, int j)
{
	int neighborNum = board[i][j] / 2;
	
	if (j != 0)
	{
		neighborNum += board[i][j - 1] / 2 + board[i][j - 1] % 2;
	}
	if (j != board[0].size() - 1)
	{
		neighborNum += board[i][j + 1] / 2 + board[i][j + 1] % 2;
	}

	if (i < board.size() - 1)
	{
		for (int it = max(0, j - 1); it <= min((int)(board[0].size() - 1), j + 1); ++it)
		{
			neighborNum += board[i + 1][it] % 2;
		}
	}

	return neighborNum;
}

void gameOfLife(vector<vector<int>>& board) {
	if (board.size() == 0)
	{
		return;
	}
	if (board[0].size() == 0)
	{
		return;
	}
	for (int i = (int)(board.size()) - 1; i > 0; --i)
	{
		for (int j = 0; j < (int)board[0].size(); ++j)
		{
			board[i][j] = board[i - 1][j] << 1 | board[i][j];
		}
	}


	for (int i = 0; i < (int)board.size(); ++i)
	{
		int cur = 0;
		int prev = 0;
		for (int j = 0; j < (int)board[0].size(); ++j)
		{
			cur = 0;
			int neigbourNum = getNeighborNumber(board, i, j);
			if (board[i][j] % 2 == 1)
			{
				if (neigbourNum >= 2 && neigbourNum <= 3)
				{
					cur = 1;
				}
			}
			else
			{
				if (neigbourNum == 3)
				{
					cur = 1;
				}
			}

			if (j > 0)
			{
				board[i][j - 1] = prev;
			}
			prev = cur;
		}
		board[i][board[0].size() - 1] = prev;

	}

}



void changeMatrix(vector<vector<int>>& board)
{
	for (int i = board.size() - 1; i > 0; --i)
	{
		for (int j = 0; j < board[0].size() ; ++j)
		{
			board[i][j] = board[i - 1][j] << 1 | board[i][j];
		}
	}
}

void changeMatrix2(vector<vector<int>>& board)
{
	for (int i = 0 ; i < board.size() - 1; ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			int origin = (board[i][j] & 1);
			board[i][j] = board[i][j] >> 1;
			board[i][j] = board[i][j] << 1;
			
			board[i][j] |= (board[i + 1][j] & 7);
			board[i][j] = board[i][j] << 1;
			board[i][j] |= origin;
		}
	}
}


void changeMatrix3(vector<vector<int>>& board)
{
	for (int i = 0; i < (int)(board.size() - 1); ++i)
	{
		for (int j = 1; j < board[0].size(); ++j)
		{
			int origin = (board[i][j] & 1);
			board[i][j] = board[i][j] >> 1;
			board[i][j] = board[i][j] << 1;

			board[i][j] |= (board[i][j - 1] & 7);
			board[i][j] = board[i][j] << 1;
			board[i][j] |= origin;
		}
	}
}

void changeMatrix4(vector<vector<int>>& board)
{
	for (int i = 0; i < board.size() - 1; ++i)
	{
		for (int j = 0; j < board[0].size() - 1; ++j)
		{
			int origin = (board[i][j] & 1);
			board[i][j] = board[i][j] >> 1;
			board[i][j] = board[i][j] << 1;

			board[i][j] |= (board[i][j + 1] & 7);
			board[i][j] = board[i][j] << 1;
			board[i][j] |= origin;
		}
	}
}



void count(vector<vector<int>>& board)
{
	for (int i = 0; i < board.size() - 1; ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			int origin = board[i][j] & 1;
			board[i][j] = board[i][j] >> 1;
			int sum = 0;
			for(int it = 0; it < 8; ++it)
			{
				sum += board[i][j] & 1;
				board[i][j] = board[i][j] >> 1;
			}
			board[i][j] = sum;
		}
	}
}



int main() {
	int k = 0;
	vector<vector<int>> matrix;

	cout << endl;
	printMatrix(matrix);
	gameOfLife(matrix);
	cout << endl;
	printMatrix(matrix);

	matrix = {
		{ }};

	cout << endl;
	printMatrix(matrix);
	gameOfLife(matrix);
	cout << endl;
	printMatrix(matrix);

	matrix = {
		{ 0, 1, 0 } };


	cout << endl;
	printMatrix(matrix);
	gameOfLife(matrix);
	cout << endl;
	printMatrix(matrix);


	matrix = {
		{ 1} };

	cout << endl;
	printMatrix(matrix);
	gameOfLife(matrix);
	cout << endl;
	printMatrix(matrix);

	matrix = {
		{ 0} };

	cout << endl;
	printMatrix(matrix);
	gameOfLife(matrix);
	cout << endl;
	printMatrix(matrix);

	matrix = {
		{ 0},{ 1 },{ 0 } };

	cout << endl;
	printMatrix(matrix);
	gameOfLife(matrix);
	cout << endl;
	printMatrix(matrix);

	matrix = {
	{0, 1, 0},
	{ 0, 0, 1 },
	{ 1, 1, 1 },
	{0, 0, 0}
};
	
	cout << endl;
	printMatrix(matrix);
	gameOfLife(matrix);
	cout << endl;
	printMatrix(matrix);

	while (true);
	return '0';
}

/*
int prev = 0;
for (int i = 0; i < board.size(); ++i)
{
for (int j = 0; j < board[0].size(); ++j)
{
int new_num = 0;

if (i < board.size() - 1)
{
for (int j1 = max(j - 1, 0); j1 <= min(j + 1, (int)(board[0].size() - 1)); ++j1)
{
new_num += (board[i + 1][j1] & 1);
}
}

if (j > 0)
{
new_num += ((board[i][j - 1] & 1) & (board[i][j - 1] & 2));
board[i][j - 1] = prev;
}

if (j < board[0].size() - 1)
{
new_num += ((board[i][j + 1] & 1) & (board[i][j + 1] & 2));
prev = new_num;
}
else
{
prev = 0;
board[i][j + 1]
}

}
}

*/

/*

A[0] = 1
A[1] = 5
A[2] = 2
A[3] = 1
A[4] = 4
A[5] = 0
*/

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
for (int i = 0; i < (int)matrix.size(); ++i)
{
for (int j = 0; j < (int)matrix[i].size(); ++j)
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
