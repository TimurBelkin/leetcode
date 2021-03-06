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

void getSubets(vector<int>& nums,
	vector<int>& current,
	size_t index, vector<vector<int>>& result) {
	if (index >= nums.size())
	{
		result.push_back(current);

	}
	else
	{
		getSubets(nums,
			current,
			index + 1,
			result);

		vector<int> new_cur = current;
		new_cur.push_back(nums[index]);
		
		getSubets(nums,
			new_cur,
			index + 1,
			result);
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.size() == 0)
	{
		return result;
	}
	vector<int> current;
	getSubets(nums, current, 0, result);
	return result;
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
	vector<int> nums = {1,2,3,4,5};
	printVec(nums);
	vector<vector<int>> result;
	result = subsets(nums);
	cout << "result: " << endl;
	printVecVecInt(result);
	while (true);
	return 0;
}
