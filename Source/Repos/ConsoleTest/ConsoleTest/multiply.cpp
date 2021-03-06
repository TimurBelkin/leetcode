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


string multiply(string num1, string num2) {
	if (num1.size() == 0 || num2.size() == 0)
	{
		return "0";
	}
	vector<int> reversed_result((int)num1.size()  +  (int)num2.size(), 0);	
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int iter1 = 0; iter1 < (int)num1.size(); ++iter1)
	{
		for (int iter2 = 0; iter2 < (int)num2.size(); ++iter2)
		{
			reversed_result[iter1 + iter2] += (num1[iter1] - '0') * (num2[iter2] - '0');
			reversed_result[iter1 + iter2 + 1] += reversed_result[iter1 + iter2] / 10;
			reversed_result[iter1 + iter2] %= 10;
		}
 	}
	int iter = reversed_result.size() - 1;
	for (; reversed_result[iter] == 0 && iter > 0; --iter);
	string result;
	for (; iter >= 0; --iter)
	{
		result.push_back(reversed_result[iter] + '0');
	}
	return result;
}


int main() {

	cout << multiply("2","3")<< endl;
	cout << multiply("123", "456") << endl;
	cout << multiply("0", "456") << endl;
	cout << multiply("99", "99") << endl;
	while (true);
	return 0;
}
