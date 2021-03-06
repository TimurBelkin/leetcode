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


void nextPermutation(vector<int>& nums) {
	if (nums.size() > 1)
	{

		int it = (int)nums.size() - 2;
		for (;
			it >= 0 && nums[it] >= nums[it + 1];
			--it);
		if (it < 0)
		{
			reverse(nums.begin(), nums.end());
		}
		else
		{
			int iter = nums.size() - 1;
			for (; iter > it && nums[iter] <= nums[it]; --iter);
			//cout << it << " " << iter << endl;
			swap(nums[it], nums[iter]);
			reverse(nums.begin() + it + 1 ,nums.end());
		} 
	}
}

void printVec(vector<int> rt)
{
	for (size_t i = 0; i < rt.size(); ++i)
	{
		cout << rt[i] << " ";
	}
	cout << endl;
}
int main() {
	
	vector<int> vct;
	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(3);
	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(3);
	//nextPermutation(vct);
	printVec(vct);

	nextPermutation(vct);
	printVec(vct);

	nextPermutation(vct);
	printVec(vct);

	nextPermutation(vct);
	printVec(vct);

	nextPermutation(vct);
	printVec(vct);

	nextPermutation(vct);
	printVec(vct);

	nextPermutation(vct);
	printVec(vct);

	nextPermutation(vct);
	printVec(vct);
	
	vector<int> vct2;
	vct2.push_back(1);
	vct2.push_back(1);
	vct2.push_back(5);
	printVec(vct2);

	nextPermutation(vct2);
	printVec(vct2);

	nextPermutation(vct2);
	printVec(vct2);

	nextPermutation(vct2);
	printVec(vct2);

	nextPermutation(vct2);
	printVec(vct2);

	nextPermutation(vct2);
	printVec(vct2);

	nextPermutation(vct2);
	printVec(vct2);


	
	while (true);
	return 0;
}
