#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>
#include <unordered_set>

using namespace std;


void myParenth(vector<string>& result, string str, int m, int n)
{
	if (m == 0 && n == 0)
	{
		result.push_back(str);
	}
	else
	{
		if (m > 0)
		{
			myParenth(result, str + ")", m - 1, n);
		}
		if (n > 0)
		{
			myParenth(result, str + "(", m + 1, n - 1);
		}
	}
}
vector<string> generateParenthesis(int n) 
{
	vector<string> result;
	string str = "";
	myParenth(result, str, 0, n);
	return result;
}

void print_vect(vector<string> vec_string)
{
	for (size_t i = 0; i < vec_string.size(); ++i)
	{
		cout << vec_string[i] << " " ;
	}
	cout << endl;
}

int main() {
	
	vector<string> str;
	for (int number = -1; number < 6; ++number)
	{
		cout << number << endl;
		str = generateParenthesis(number);
		print_vect(str);
	}


	while(true);
	return 0;
}