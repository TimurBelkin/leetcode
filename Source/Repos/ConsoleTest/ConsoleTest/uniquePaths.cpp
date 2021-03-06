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

long factorial(int end, int begin)
{
	if (begin == 0)
	{
		begin = 1;
	}
	long result = 1;
	for (int iter = begin; iter <= end; ++iter)
	{
		result *= iter;
	}
	return result;
}
int uniquePaths(int m, int n) {
	if (n < m)
	{
		return uniquePaths(n, m);
	}
	if (n <= 0 || m <= 0)
	{
		return 0;
	}
	if (n == 1 && m == 1)
	{
		return 1;
	}
	--n;
	--m;
	return factorial(m + n, n + 1) / factorial(m, 1);
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
	cout << uniquePaths(1, 1) << endl;
	cout << uniquePaths(2, 2) << endl;
	cout << uniquePaths(1, 100) << endl;
	cout << uniquePaths(2, 100) << endl;
	cout << uniquePaths(4, 5) << endl;
	while (true);
	return 0;
}
