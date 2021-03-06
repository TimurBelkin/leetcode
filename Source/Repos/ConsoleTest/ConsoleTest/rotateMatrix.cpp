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

void printMatrix(vector<vector<int>>& matrix)
{
	for (size_t it = 0; it < matrix.size(); ++it)
	{
		for (size_t it2 = 0; it2 < matrix[it].size(); ++it2)
		{
			cout << matrix[it][it2] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void rotate(vector<vector<int>>& matrix) {
	if (matrix.size() > 1)
	{
		int n = matrix.size() - 1;
		for (int k = 0; k < (int)matrix.size() / 2; ++k)
		{
			for (int i = 0; i + k < n - k; ++i)
			{
				int temp = matrix[i + k][n - k];
				
				matrix[i + k][n - k] = matrix[k][i + k];
				matrix[k][i + k] = matrix[n - (i + k)][k];
				matrix[n - (i + k)][k] = matrix[n - k][n - (i + k)];
				matrix[n - k][n - (i + k)] = temp;
				//cout << "iter i " << i << " k " << k << endl;
				//printMatrix(matrix);
			}
		}
	}
}
/*
void Myrotate(vector<vector<int>>& matrix,
	vector<vector<int>>* matrixRotated) {
	for (int it = 0; it < matrix.size(); ++it)
	{
		vector<int> temp;
		for (int it2 = 0; it2 < matrix.size(); ++it2)
		{
			temp.push_back(0);
		}
		matrixRotated->push_back(temp);
	}
	for (int it = 0; it < matrix.size(); ++it)
	{
		for (int it2 = 0; it2 < matrix.size(); ++it2)
		{
			
		}
		matrixRotated->push_back(temp);
	}
}

*/

int main() {

	vector<vector<int>> matrix;
	int it = 0, n = 6, val = 1;
	for (int it = 0; it < n ; ++it)
	{
		vector<int> temp;
		for (int i = 0; i < n ; ++i)
		{
			temp.push_back(val);
			++val;
		}
		matrix.push_back(temp);
	}
	printMatrix(matrix);
	rotate(matrix);
	printMatrix(matrix);

	vector<vector<int>> matrixRotated;
	//Myrotate(matrix, &matrixRotated);
	printMatrix(matrixRotated);
	while (true);
	return 0;
}
/*

void printVecotor(vector<int> vec)
{
for (size_t it = 0; it < vec.size(); ++it)
{
cout << vec[it] << " ";
}
cout << endl;
}

*/