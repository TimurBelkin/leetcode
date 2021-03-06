#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>

using namespace std;


int myAtoi(string str) {
	int iter = 0;
	for (; iter < str.size() && str[iter] == ' '; ++iter);
	if (iter == str.size() || str.size() == 0)
	{
		return 0;
	}
	int sign = 1;
	if (str[iter] == '-')
	{
		sign = -1;
		++iter;
	}
	else if (str[iter] == '+')
	{
		++iter;
	}
	int number = 0, zero = (int)'0', nine = (int)'9';
	while (zero <= (int)str[iter]
		&& (int)str[iter] <= nine
		&& iter < str.size())
	{
		int next_num = (int)str[iter] - (int)'0';
		if (sign == 1
			&& (number > INT_MAX / 10 
				|| number ==  INT_MAX / 10 && next_num  > INT_MAX % 10))
		{
			return INT_MAX;
		} else if(sign == -1
			&& (sign * number < INT_MIN / 10
				|| sign * number == INT_MIN / 10 && sign * next_num  < INT_MIN % 10))
		{
			return INT_MIN;
		}
		number = number * 10 + next_num;
		++iter;
	}
	number *= sign;
	return number;
}




	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if ((int)nums2.size() < (int)nums1.size())
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		int length2 = (int)nums2.size(), length1 = (int)nums1.size();
		int left_border = 0, right_border = length1;
		int it1 = (left_border + right_border) / 2;
		while (left_border <= right_border)
		{
			int it2 = (length2 + length1 + 1) / 2 - it1;
			if (it1 != length1 && nums2[it2 - 1] > nums1[it1])
			{
				left_border = it1 + 1;
				it1 = (left_border + right_border) / 2;
			}
			else if (it1 > 0 && nums1[it1 - 1] > nums2[it2])
			{
				right_border = it1 - 1;
				it1 = (right_border + left_border) / 2;
			}
			else {
				int max_left, min_right;
				if (it1 == 0)
				{
					max_left = nums2[it2 - 1];
				}
				else if (it2 == 0)
				{
					max_left = nums1[it1 - 1];
				}
				else
				{
					max_left = max(nums1[it1 - 1], nums2[it2 - 1]);
				}

				if ((length1 + length2) % 2 == 1)
				{

					return max_left;
				}

				if (it1 == length1)
				{
					min_right = nums2[it2];
				}
				else if (it2 == length2)
				{
					min_right = nums1[it1];
				}
				else
				{
					min_right = min(nums1[it1], nums2[it2]);
				}


					return (max_left + min_right) / 2.0;
				
			}
		}
		return (nums2[length2 / 2] + nums2[(length2 - 1) / 2]) / 2;
	}


int main() {
	/*
	nums1 = [1, 2]
	nums2 = [3, 4]
	*/
	vector<int> nums1, nums2; 
	nums1.push_back(1);
	nums1.push_back(10);
	nums2.push_back(3);
	nums2.push_back(4);
	cout << findMedianSortedArrays(nums1, nums2);

	/*
	nums1 = [1, 3]
	nums2 = [2]
	*/


	vector<int> nums3, nums4;
	nums3.push_back(1);
	nums3.push_back(3);
	nums4.push_back(2);

	cout <<  " " << findMedianSortedArrays(nums3, nums4);
	vector<int> nums5;
	cout << " " << findMedianSortedArrays(nums3, nums5);
	cout << " " << findMedianSortedArrays(nums5, nums3);
	/*
	string s = "42";
	cout << s << " " << myAtoi(s) << "\n";

	 s = "   -42";
	cout << s << " " << myAtoi(s) << "\n";

	 s = "4193 with words" ;
	cout << s << " " << myAtoi(s) << "\n";

    s = "words and 987";
	cout << s << " " << myAtoi(s) << "\n";

   s = "-91283472332";
	cout << s << " " << myAtoi(s) << "\n";

	s = "-2147483649";
	cout << s << " " << myAtoi(s) << "\n";

	s = "";
	cout << s << " " << myAtoi(s) << "\n";
	*/
	while(true);
	return 0;
}