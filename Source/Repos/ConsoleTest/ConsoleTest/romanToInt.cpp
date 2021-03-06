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


int romanToInt(string s) {
	if (s.size() == 0)
	{
		return 0;
	}
	map<char, int> RomanNum;
	RomanNum['I'] = 1;
	RomanNum['V'] = 5;
	RomanNum['X'] = 10;
	RomanNum['L'] = 50;
	RomanNum['C'] = 100;
	RomanNum['D'] = 500;
	RomanNum['M'] = 1000;
	int prev = 0, result = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (prev > 0)
		{
			if (RomanNum[s[i]] > prev)
			{
				result += (RomanNum[s[i]] - prev);
				prev = 0;
			}
			else if (RomanNum[s[i]] < prev)
			{
				result += prev;
				prev = RomanNum[s[i]];
			}
			else
			{
				prev += RomanNum[s[i]];
			}
		}
		else
		{
			prev = RomanNum[s[i]];
		}
	}
	result += prev;
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
	//[5,7,7,8,8,10]
	string str = "I";
	cout << str << " " << romanToInt(str) << endl;
	str = "II";
	cout << str << " " << romanToInt(str) << endl;
	str = "V";
	cout << str << " " << romanToInt(str) << endl;
	str = "IV";
	cout << str << " " << romanToInt(str) << endl;
	str = "XIX";
	cout << str << " " << romanToInt(str) << endl;
	str = "LVIII";
	cout << str << " " << romanToInt(str) << endl;
	str = "MCMXCIV";
	cout << str << " " << romanToInt(str) << endl;
	str = "LXIX";
	cout << str << " " << romanToInt(str) << endl;
	str = "C";
	cout << str << " " << romanToInt(str) << endl;

	


	while(true);
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