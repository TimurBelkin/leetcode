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



int main() {

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

	while(true);
	return 0;
}