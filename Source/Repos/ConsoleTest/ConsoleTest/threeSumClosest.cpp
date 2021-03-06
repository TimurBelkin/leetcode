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


int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	long closed_to_target = nums[0] + nums[1] + nums[2];
	long abs_dif_target = ((closed_to_target - target) > 0) ? closed_to_target - target : target - closed_to_target;
	for (int i = 0; i < (int)nums.size() - 2; ++i)
	{
		for (int begin = i + 1, end = (int)nums.size() - 1;
			begin < end;
			)
		{
			long step_target = nums[begin] + nums[end] + nums[i];
			if (step_target == target)
			{
				return step_target;
			}

			long abs_step_dif = (step_target - target > 0) ? step_target - target : target - step_target;

			if (abs_step_dif < abs_dif_target)
			{
				closed_to_target = step_target;
				abs_dif_target = abs_step_dif;
			}
					
			if (step_target - target < 0)
			{
				++begin;
			}
			else
			{
				--end;
			}
		}
	}
	return closed_to_target;
}

int main() {
	//[-1, 2, 1, -4]
	vector<int> vct;
	vct.push_back(-1);
	vct.push_back(2);
	vct.push_back(1);
	vct.push_back(-4);
	
	cout << threeSumClosest(vct, 1) << " right answer is " << 2 << endl;
	cout << threeSumClosest(vct, -4) << " right answer is " << -4 << endl;
	vct.push_back(1);
	cout << threeSumClosest(vct, 1) << " right answer is " << 1 << endl;

	
	vector<int> vct2;
	vct2.push_back(0);
	vct2.push_back(2);
	vct2.push_back(1);
	vct2.push_back(-3);

	cout << threeSumClosest(vct2, 1) << " right answer is " << 0 << endl;

	//[0, 2, 1, -3]
	//1
	
	while (true);
	return 0;
}
