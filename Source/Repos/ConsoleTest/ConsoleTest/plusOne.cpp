#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	if (digits.size() == 0)
	{
		digits.push_back(1);
		return digits;
	}
	int dec = 1;
	for (int i = (int)digits.size() - 1; i >= 0; --i)
	{
		digits[i] += dec;
		if (digits[i] > 9)
		{
			dec = 1;
			digits[i] %= 10;
		}
		else
		{
			dec = 0;
			break;
		}
	}
	if (dec == 1)
	{
		digits.insert(digits.begin(), dec);
	}
	return digits;
}


void print_vector(vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}


int main() {
	vector<int> test;
	test.push_back(4);
	test.push_back(9);
	test.push_back(3);
	test.push_back(9);
	vector<int> res = plusOne(test);
	print_vector(res);

	while(true);
	return 0;
}