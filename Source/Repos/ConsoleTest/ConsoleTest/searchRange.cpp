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

vector<int> searchRange(vector<int>& nums, int target) {
	int tap = binarySearch(nums, 0, nums.size() - 1, target);
	if (tap == -1)
	{
		vector<int> res;
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	else {
		int min_tap, max_tap;
		min_tap = max_tap = tap;
		while (min_tap - 1 >= 0 && nums[min_tap - 1] == target)
		{
			--min_tap;
		}
		while (max_tap + 1 < nums.size() && nums[max_tap + 1] == target)
		{
			++max_tap;
		}
		vector<int> res;
		res.push_back(min_tap);
		res.push_back(max_tap);
		return res;
	}
}

void printVecotor(vector<int> vec)
{
	for (size_t it = 0; it < vec.size(); ++it)
	{
		cout << vec[it] << " ";
	}
	cout << endl;
}

int main() {
	//[5,7,7,8,8,10]
	vector<int> res;
	vector<int> str;
	res = searchRange(str, 7);
	printVecotor(res);
	str.push_back(5);
	str.push_back(7);
	str.push_back(7);
	str.push_back(8);
	str.push_back(8);
	str.push_back(10);
	res = searchRange(str, 7);
	printVecotor(res);

	res = searchRange(str, 8);
	printVecotor(res);

	res = searchRange(str, 10);
	printVecotor(res);

	res = searchRange(str, 0);
	printVecotor(res);


	while(true);
	return 0;
}