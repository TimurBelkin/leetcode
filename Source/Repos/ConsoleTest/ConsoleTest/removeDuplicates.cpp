#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>

using namespace std;



int removeDuplicates(vector<int>& nums) {
	if (nums.size() < 2)
	{
		return nums.size();
	}
	size_t iter = 1, iter_to_swap = 0;
	for (; iter < nums.size(); ++iter)
	{
		if (nums[iter - 1] != nums[iter])
		{
			    ++iter_to_swap;
				nums[iter_to_swap] = nums[iter];
		}
	}
	return iter_to_swap + 1;

}

void printVector(vector<int> input_vec)
{
	for (size_t i = 0; i < input_vec.size(); ++i)
	{
		cout << input_vec[i] << " ";
	}
	cout << endl;
}


int main() {
	vector<int> test;
	printVector(test);

	cout << removeDuplicates(test) << endl;
	printVector(test);

	test.push_back(0);

	printVector(test);
	cout << removeDuplicates(test) << endl;
	printVector(test);

	test.push_back(0);

	printVector(test);
	cout << removeDuplicates(test) << endl;
	printVector(test);

	test.push_back(1);
	test.push_back(1);
	test.push_back(1);

	printVector(test);
	cout << removeDuplicates(test) << endl;
	printVector(test);

	test.push_back(2);
	test.push_back(2);
	test.push_back(3);
	test.push_back(3);
	test.push_back(4);
	test.push_back(4);

	printVector(test);
	
	cout << removeDuplicates(test) << endl;

	printVector(test);

	while(true);
	return 0;
}