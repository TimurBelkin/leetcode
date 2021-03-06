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


vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	if (nums.size() < 4)
	{
		return result;
	}
	sort(nums.begin(), nums.end());
	int prev_num1;
	for (int it1 = 0; it1 < (int)nums.size() - 3;)
	{
		int prev_num2;
		for (int it2 = it1 + 1; it2 < (int)nums.size() - 2;)
		{
			int prev_end, prev_begin;
			for (int begin = it2 + 1, end = (int)nums.size() - 1;
				begin < end;)
			{
				long step_target = nums[begin] + nums[end] + nums[it1] + nums[it2];
				if (step_target == target)
				{
					vector<int> new_vect = { nums[it1], nums[it2], nums[begin], nums[end]};
					result.push_back(new_vect);
				}


				if (step_target - target < 0 || step_target - target == 0)
				{
					prev_begin = nums[begin];
					++begin;
					while (begin < end && prev_begin == nums[begin])
					{
						++begin;
					}
				}
				else if(step_target - target > 0 || step_target - target == 0)
				{
					prev_end = nums[end];
					--end;
					while (begin < end && prev_end == nums[end])
					{
						--end;
					}
				}
			}
			prev_num2 = nums[it2];
			++it2;
			while (it2 < (int)nums.size() - 2 && prev_num2 == nums[it2])
			{
				++it2;
			}
		}
		prev_num1 = nums[it1];
		++it1;
		while (it1 < (int)nums.size() - 3 && prev_num1 == nums[it1])
		{
			++it1;
		}
	}
	return result;
}


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

int main() {
	vector<int> nums ={1, 0, -1, 0, -2, 2, 1, 0, -2, -2, -1};
	vector<vector<int>> result = fourSum(nums, 0);
	printVecVecInt(result);

	cout << endl;
	nums = { 1, 0, -1, 0, -2, 2};
	result = fourSum(nums, 0);
	printVecVecInt(result);

	cout << endl;
	nums = { };
	result = fourSum(nums, 0);
	printVecVecInt(result);
	
	cout << endl;
	nums = { 1, 0};
	result = fourSum(nums, 0);
	printVecVecInt(result);

	cout << endl;
	nums = { 1, 0, -1, 0, -2, 2 };
	result = fourSum(nums, 5);
	printVecVecInt(result);

	cout << endl;
	nums = { 1, 1, 1, 1, 1, 1, 1, 1 };
	result = fourSum(nums, 4);
	printVecVecInt(result);

	cout << endl;
	nums = { -1, -1, 1, 1, 5, 6, 4, -3, 0, 2, -3, -2, -1, -4, 3, 4, 8, 9, 0, -7 };
	result = fourSum(nums, 2);
	printVecVecInt(result);

	while (true);
	return 0;
}
