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


bool isValidSudoku(vector<vector<char>>& board) {
	if (board.size() == 0)
	{
		return false;
	}
	//int des1[9][9] = { 0 }, des2[9][9] = { 0 }, des3[9][9] = { 0 };
	vector<vector<int>> des1(9, vector<int>(9,0));
	vector<vector<int>> des2(9, vector<int>(9, 0));
	vector<vector<int>> des3(9, vector<int>(9, 0));
	for (int it1 = 0; it1 < (int)board.size(); ++it1)
	{
		for (int it2 = 0; it2 < (int)board[it1].size(); ++it2)
		{
			if (board[it1][it2] != '.')
			{
				int board_number = board[it1][it2] - '0' - 1;
				if (des1[it1][board_number]
					|| des2[it2][board_number]
					|| des3[3 * (it1 / 3) + it2 / 3][board_number])
				{
					return false;
				}
				else {
					des1[it1][board_number] =
						des2[it2][board_number] =
						des3[3 * (it1 / 3) + it2 / 3][board_number] = 1;
				}
			}
		}
	}
	return true;
}


int main() {
	
	vector<vector<char>> sudoku{
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	cout << isValidSudoku(sudoku) << endl;

	vector<vector<char>> sudoku2
	{
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};
	cout << isValidSudoku(sudoku2) << endl;
	while (true);
	return 0;
}
