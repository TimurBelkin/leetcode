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


void findCombin(vector<int>& candidates,
	int target,
	int begin,
	vector<int>& numbers,
	vector<vector<int>>* result)
{
	if (target == 0 && begin != 0)
	{
		result->push_back(numbers);
	}
	for (int it = begin; it < candidates.size() &&  target - candidates[it] >= 0; ++it)
	{
		
		numbers.push_back(candidates[it]);
		findCombin(candidates,
			target - candidates[it],
			it + 1,
			numbers,
			result);
		numbers.pop_back();

		while (it < candidates.size() - 1 && candidates[it] == candidates[it + 1])
		{
			++it;
		}

	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	sort(candidates.begin(), candidates.end());
	vector<int> numbers;
	if (candidates.size() == 0)
	{
		return result;
	}
	else
	{
		findCombin(candidates,
			target,
			0,
			numbers,
			&result);
	}
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
	//[10,1,2,7,6,1,5]
	vector<int> vct;
	vct.push_back(10);
	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(7);
	vct.push_back(6);
	vct.push_back(1);
	vct.push_back(5);

	vector<vector<int>> vctv2 = combinationSum2(vct, 8);
	
	 printMatrix(vctv2);

	 //[2,5,2,1,2], target = 5,

	 vector<int> vct2;
	 vct2.push_back(2);
	 vct2.push_back(5);
	 vct2.push_back(2);
	 vct2.push_back(1);
	 vct2.push_back(2);


	 vector<vector<int>> vctv3 = combinationSum2(vct2, 5);
	 printMatrix(vctv3);
	
	while (true);
	return 0;
}
