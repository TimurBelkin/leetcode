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


bool canJump(vector<int>& nums) {

	int step = 0, iter = 0;
	for (; iter < nums.size(); ++iter, --step)
	{
		if (nums[iter] > step)
		{
			step = nums[iter];
		}
		if (step == 0)
		{
			break;
		}
	}
	if (iter >= ((int)(nums.size()) - 1))
	{
		return true;
	}
	return false;

}
int main() {
	//[3,2,1,0,4]
	
	vector<int> vct;
	vct.push_back(3);
	vct.push_back(2);
	vct.push_back(1);
	vct.push_back(0);
	vct.push_back(4);
	///vct.push_back(3);
	//nextPermutation(vct);
	cout << canJump(vct) << endl;
	


	//[2,3,1,1,4]
	vector<int> vct2;
	vct2.push_back(2);
	vct2.push_back(3);
	vct2.push_back(1);
	vct2.push_back(1);
	vct2.push_back(4);
	cout << canJump(vct2) << endl;
	vct2.push_back(0);
	cout << canJump(vct2) << endl;
	vct2.push_back(0);
	cout << canJump(vct2) << endl;
	vct2.push_back(0);
	cout << canJump(vct2) << endl;
	vct2.push_back(0);
	cout << canJump(vct2) << endl;
	vct2.push_back(0);
	cout << canJump(vct2) << endl;
	vct2.push_back(0);
	cout << canJump(vct2) << endl;

	vector<int> vct3;
	vct3.push_back(0);
	vct3.push_back(1);
	cout << canJump(vct3) << endl;

	vector<int> vct4;
	vct4.push_back(0);
	cout << canJump(vct4) << endl;



	
	while (true);
	return 0;
}
