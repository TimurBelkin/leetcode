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

void printVec(vector<int> input)
{
	for (size_t it = 0; it < input.size(); ++it)
	{
		cout << input[it] << " ";
	}
	cout << endl;
}

void sortColors(vector<int>& nums) {
	if (nums.size() < 2)
	{
		return;
	}
	vector<int> colors;
	colors.push_back(-1);
	colors.push_back(-1);
	colors.push_back(-1);
	for (size_t iter = 0; iter < nums.size(); ++iter)
	{
		cout << "iter " << iter << " " << nums[iter] << " " ;
		int prev = -2;
		for (size_t it = nums[iter]; it <= 2; ++it)
		{
				++colors[it];
				if (prev != colors[it])
				{
					nums[colors[it]] = it;
				}
				prev = colors[it];
		}
		cout << endl;
		printVec(nums);
	}
}



int main() {
	//[2,0,2,1,1,0]
	
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(0);
	/*
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);
	*/
	printVec(nums);
	sortColors(nums);
	printVec(nums);
	while (true);
	return 0;
}
