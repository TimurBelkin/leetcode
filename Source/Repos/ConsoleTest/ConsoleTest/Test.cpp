#include <vector>;

using namespace std;

class Test
{
	/*
	vector<vector<char>> sudoku{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '''1''', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '''1'''},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '''1''', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	*/

/*
	{
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1}
	}


	{
		{0, 1, 2, 0},
		{3, 4, 5, 2},
		{1, 3, 1, 5}
	}
	*/
};


//{{'1', '0', '1', '1', '0', '1'}, {'1', '1', '1', '1', '1', '1'}, {'0', '1', '1', '0', '1', '1'}, {'1', '1', '1', '0', '1', '0'}, {'0', '1', '1', '1', '1', '1'}, {'1', '1', '0', '1', '1', '1'}}

/*
grid = { { ''1'', ''1'', ''1'', ''1'', '0' },
{ ''1'', ''1'', '0', ''1'', '0' },
{ ''1'', ''1'', '0', '0', '0' },
{ '0', '0', '0', '0', '0' }, };
cout << numIslands(grid) << endl;

grid = { { ''1'', ''1'', '0', '0', '0' },
{ ''1'', ''1'', '0', '0', '0' },
{ '0', '0', ''1'', '0', '0' },
{ '0', '0', '0', ''1'', ''1'' }, };

*/


//{{'0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1''}, {'0', '0', '0', '0', '0', ''1'', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0'}, {''1'', ''1'', ''1'', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', ''1'', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', ''1''}, {'0', '0', ''1'', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', ''1'', '0', '0', '0', '0', '0'}, {'0', '0', '0', ''1'', '0', ''1'', '0', '0', '0', '0', ''1'', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', ''1'', '0'}, {''1'', '0', ''1'', ''1'', ''1'', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0'}, {'0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', ''1'', '0', ''1'', '0', '0', '0', ''1'', '0', ''1'', '0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', ''1'', '0', '0', ''1'', '0'}, {'0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', ''1'', '0', '0', '0', ''1'', '0', '0', '0', '0', '0'}, {'0', ''1'', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}, {''1'', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', ''1'', '0', '0', '0', '0', ''1'', '0', ''1'', '0', '0', '0', ''1'', '0', ''1'', '0', '0', '0', '0', ''1''}, {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', ''1'', '0', ''1'', '0', '0', '0', '0', '0', '0', ''1'', ''1'', '0', '0', '0', '0', '0'}, {'0', ''1'', '0', ''1'', '0', '0', '0', '0', ''1'', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', ''1'', ''1'', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0'}, {'0', ''1'', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', ''1'', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', ''1'', ''1'', '0', ''1''}, {''1'', '0', '0', '0', '0', ''1'', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', ''1'', '0', '0', '0', '0', ''1'', ''1'', '0', '0', ''1'', '0', '0', '0', '0', '0', '0'}, {'0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', ''1'', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', ''1'', ''1'', '0', ''1'', '0', '0', '0', '0', ''1'', ''1''}, {'0', ''1'', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', ''1'', ''1'', '0', ''1'', '0', ''1''}, {''1'', ''1'', ''1'', '0', ''1'', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', ''1'', '0', ''1'', '0', ''1'', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', ''1'', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', ''1''}, {'0', '0', '0', ''1'', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', ''1'', '0', '0', '0', '0', '0', ''1'', '0', ''1'', '0', '0', '0', ''1'', '0', '0', '0'}}