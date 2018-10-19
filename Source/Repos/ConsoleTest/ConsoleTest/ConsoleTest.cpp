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


void myCombinationSum(vector<int>& candidates,
	int target,
	int begin,
	vector<int>& currentSum,
	vector<vector<int>>* result)
{
	if (target == 0)
	{
		result->push_back(currentSum);
	}
	for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i)
	{
		currentSum.push_back(candidates[i]);
		myCombinationSum(candidates, target - candidates[i], i, currentSum, result);
		currentSum.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	if (candidates.size() == 0)
	{
		return result;
	}
	sort(candidates.begin(), candidates.end());
	vector<int> currentSum;
	myCombinationSum(candidates, target, 0, currentSum, &result);
	return result;
}


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

int main() {
	//[2,3,5]
	vector<int> vct;
	vct.push_back(2);
	vct.push_back(3);
	vct.push_back(5);
	vector<vector<int>> mat = combinationSum(vct, 8);
	printMatrix(mat);
	while (true);
	return 0;
}
