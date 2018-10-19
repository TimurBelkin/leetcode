#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>

using namespace std;



void swap(vector<int>* next_num_p, int begin, int iter)
{
	int temp_swap = (*next_num_p)[begin];
	(*next_num_p)[begin] = (*next_num_p)[iter];
	(*next_num_p)[iter] = temp_swap;
}
void permuteMy(vector<int>& nums,
	size_t begin,
	vector<vector<int>>* result_p)
{
	if (begin == nums.size() - 1)
	{
		result_p->push_back(nums);
	} else 
	{
		for (size_t iter = begin; iter < nums.size(); ++iter)
		{
			if (begin != iter && nums[iter] == nums[iter - 1])
			{
				continue;
			}
			vector<int>* next_num_p = new vector<int>(nums);
			//result_p->push_back(*next_num_p);
			swap(next_num_p, begin, iter);
			sort(next_num_p->begin() + begin + 1, next_num_p->end());
			permuteMy(*next_num_p,
				begin + 1,
				result_p);
		}
	}
}
 vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>>* result_p = new vector<vector<int>>();
	if (nums.size() == 0)
	{
		return *result_p;
	}
	std::sort(nums.begin(), nums.end());

	permuteMy(nums,
		0,
		result_p);
	return *result_p;
}

void printVector(vector<int> input_vec)
{
	cout << '[';
	for (size_t i = 0; i < input_vec.size(); ++i)
	{
		cout << input_vec[i] << ",";
	}
	cout << ']';
}

void print2DimVector(vector<vector<int>> input_vec)
{
	cout << '[';
	for (size_t i = 0; i < input_vec.size(); ++i)
	{
		
		printVector(input_vec[i]);
		cout << "," << endl;
	}
	cout << ']' << endl ;
}


int main() {
	vector<int> test;
	vector<vector<int>> res;
	/*
	printVector(test);
	cout << endl;
	 res = permuteUnique(test);
	print2DimVector(res);

	test.push_back(3);

	printVector(test);
	cout << endl;
	 res = permuteUnique(test);
	print2DimVector(res);

	test.push_back(0);
	test.push_back(3);

	printVector(test);
	cout << endl;
	res = permuteUnique(test);	
	print2DimVector(res);
	
	test.push_back(3);

	printVector(test);
	cout << endl;
	res = permuteUnique(test);
	print2DimVector(res);
	*/
	test.push_back(0);
	test.push_back(1);
	test.push_back(0);
	test.push_back(0);
	test.push_back(9);
	printVector(test);
	cout << endl;
	res = permuteUnique(test);
	print2DimVector(res);

	//cout <<"test size is " << test.size() << " res size is " << res.size();

	while(true);
	return 0;
}