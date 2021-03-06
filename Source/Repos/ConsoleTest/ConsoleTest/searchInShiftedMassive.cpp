#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>
#include <unordered_set>

using namespace std;

int binarySearch(vector<int>& nums, int begin, int end, int target)
{
	if (end < begin || (int)nums.size() == 0)
	{
		return -1;
	}

	while (begin <= end)
	{
		if (nums[(begin + end) / 2] == target)
		{
			return (begin + end) / 2;
		}
		if (nums[(begin + end) / 2] > target)
		{
			end = (begin + end) / 2 - 1;
		}
		else
		{
			begin = (begin + end) / 2 + 1;
		}
	}
	return -1;
}

int search(vector<int>& nums, int target) {
	if (nums.size() == 0)
	{
		return -1;
	}
	if (nums.size() == 1)
	{
		if (nums[0] == target)
		{
			return 0;
		}
		return -1;
	}
	if (nums[0] < nums[nums.size() - 1])
	{
		return binarySearch(nums, 0, nums.size() - 1, target);
	}
	size_t begin = 0, end = nums.size() - 1;
	while (begin != end - 1 && nums[begin] >= nums[end])
	{
		if (nums[(begin + end) / 2] >= nums[end])
		{
			begin = (begin + end) / 2;
		}
		else
		{
			end = (begin + end) / 2;
		}
	}
	if (target == nums[begin])
	{
		return begin;
	}
	if (target == nums[end])
	{
		return end;
	}
	if (target > nums[nums.size() - 1])
	{
		return binarySearch(nums, 0, begin, target);
	}
	else
	{
		return binarySearch(nums, end, nums.size() - 1, target);
	}
}

int main() {
	//4,5,6,7,0,1,2
	
	vector<int> str;
	cout << search(str, 0) << endl;
	str.push_back(4);
	cout << search(str, 0) << endl;
	cout << search(str, 4) << endl;
	str.push_back(5);
	cout << search(str, 0) << endl;
	str.push_back(6);
	str.push_back(7);
	str.push_back(0);
	str.push_back(1);
	str.push_back(2);
	
	cout << search(str, 0) << endl;
	cout << search(str, 3) << endl;
	cout << search(str, 2) << endl;
	cout << search(str, 4) << endl;
	cout << search(str, 10) << endl;
	
	str.push_back(3);
	cout << search(str, 0) << endl;
	cout << search(str, 3) << endl;
	cout << search(str, 10) << endl;
	
	vector<int> tr;
	tr.push_back(3);
	tr.push_back(4);
	tr.push_back(7);
	tr.push_back(8);
	tr.push_back(9);
	cout << search(tr, 3) << endl;
	cout << search(tr, 10) << endl;
	cout << search(tr, 8) << endl;
	cout << search(tr, 9) << endl;

	while(true);
	return 0;
}