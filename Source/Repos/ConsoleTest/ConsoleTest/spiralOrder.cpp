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


void printVecVecInt(vector<vector<int>> input_vec)
{
	for (vector<vector<int>>::iterator it = input_vec.begin(); it < input_vec.end(); ++it)
	{
		for (vector<int>::iterator iter = it->begin(); iter < it->end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
}



vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> spiral;
	if (matrix.size() == 0)
	{
		return spiral;
	}
	int begin_column = 0, end_column = (int)(matrix[0].size()) - 1;
	int begin_row = 0, end_row = (int)(matrix.size()) - 1;
	for(; begin_row < end_row && begin_column < end_column; 
		++begin_row , --end_row, ++begin_column, -- end_column)
	{
		for (int it = begin_column; it <= end_column; ++it)
		{
			spiral.push_back(matrix[begin_row][it]);
		}
		for (int it = begin_row + 1; it <= end_row; ++it)
		{
			spiral.push_back(matrix[it][end_column]);
		}
		for (int it = end_column - 1; it >= begin_column; --it)
		{
			spiral.push_back(matrix[end_row][it]);
		}
		for (int it = end_row - 1; it > begin_row; --it)
		{
			spiral.push_back(matrix[it][begin_column]);
		}
	}

	if (begin_column == end_column)
	{
		for(int it = begin_row; it <= end_row; ++it )
		spiral.push_back(matrix[it][end_column]);
	} else if (begin_row == end_row)
	{
		for (int it = begin_column; it <= end_column; ++it)
			spiral.push_back(matrix[begin_row][it]);
	}
	return spiral;
}



vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix;
	if (n <= 0)
	{
		return matrix;
	}
	for (int it = 0; it < n; ++it)
	{
		matrix.push_back(vector<int>(n));
	}
	int begin = 0, end = (int)(matrix.size()) - 1;
	int iter = 1;
	for (; begin < end; ++begin, --end)
	{
		for (int it = begin; it <= end; ++it)
		{
			matrix[begin][it] = iter++;
		}
		for (int it = begin + 1; it <= end; ++it)
		{
			matrix[it][end] = iter++;
		}
		for (int it = end - 1; it >= begin; --it)
		{
			matrix[end][it] = iter++;
		}
		for (int it = end - 1; it > begin; --it)
		{
			matrix[it][begin] = iter++;
		}
	}

	if (begin == end)
	{
		matrix[begin][end] = iter;
	}
	return matrix;
}


void printVec(vector<int> input_vec)
{
	for (vector<int>::iterator it = input_vec.begin(); it < input_vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	
	vector<vector<int>> matrix = { { 1, 2},
	{ 3, 4},
	{ 5, 6} };
	vector<int> res = spiralOrder(matrix);
	printVec(res);
	
	 matrix = { { 1} };
	 res = spiralOrder(matrix);
	printVec(res);

    matrix = { {1, 2, 3},
	{4, 5, 6 }};
	 res = spiralOrder(matrix);
	printVec(res);

	matrix = { { 1, 2, 3, 4},
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 },
	{ 13, 14, 15, 16 } };
	res = spiralOrder(matrix);
	printVec(res);

	matrix = { { 1, 2, 3, 4 },
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 }};
	res = spiralOrder(matrix);
	printVec(res);

	matrix = {};
	res = spiralOrder(matrix);
	printVec(res);

	matrix = { { 1, 2, 3},
	{ 5, 6, 7},
	{ 9, 10, 11},
	{ 13, 14, 15} };
	res = spiralOrder(matrix);
	printVec(res);
	/*
	vector<vector<int>> result;
	for (int i = 0; i < 7; ++i)
	{
		 result = generateMatrix(i);
		 printVecVecInt(result);
	}
	*/
	while (true);
	return 0;
}
