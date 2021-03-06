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


string intToRoman(int num) {
	string result = "";
	if (num == 0)
	{
		return result;
	}
	map<int, char> RomanNum;
	RomanNum[1] = 'I';
	RomanNum[5] = 'V';
	RomanNum[10] = 'X';
	RomanNum[50] = 'L';
	RomanNum[100] = 'C';
	RomanNum[500] = 'D';
	RomanNum[1000] = 'M';
	int den = 1000;
	while (num > 0)
	{
		int cur = num / den;
		if (cur == 1)
		{
			result.push_back(RomanNum[den]);
		}
		else if (cur == 5)
		{
			result.push_back(RomanNum[5 * den]);
		}
		else if (cur == 9)
		{
			result.push_back(RomanNum[den]);
			result.push_back(RomanNum[10 * den]);
		}
		else if (cur > 5)
		{
			result.push_back(RomanNum[den * 5]);
			cur -= 5;
			while (cur-- > 0)
			{
				result.push_back(RomanNum[den]);
			}
		}
		else if (cur > 3)
		{
			result.push_back(RomanNum[den]);
			result.push_back(RomanNum[den * 5]);
		}
		else
		{
			while (cur-- > 0)
			{
				result.push_back(RomanNum[den]);
			}
		}
		num %= den;
		den /= 10;
	}
	return result;
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
	cout << intToRoman(1) << endl;
	cout << intToRoman(2) << endl;
	cout << intToRoman(3) << endl;
	cout << intToRoman(4) << endl;
	cout << intToRoman(5) << endl;
	cout << intToRoman(8) << endl;
	cout << intToRoman(9) << endl;
	cout << intToRoman(10) << endl;
	cout << intToRoman(456) << endl;
	cout << intToRoman(58) << endl;
	cout << intToRoman(1994) << endl;
	cout << intToRoman(3999) << endl;
	cout << intToRoman(399) << endl;
	while (true);
	return 0;
}
/*

void printVecotor(vector<int> vec)
{
for (size_t it = 0; it < vec.size(); ++it)
{
cout << vec[it] << " ";
}
cout << endl;
}

*/