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

string getPermutation(int n, int k) {
	if (n < 1 || k < 1)
	{
		return "";
	}
	vector<int> factor(n + 1, 1);
	for (int it = 1; it <= n; ++it)
	{
		factor[it] = factor[it - 1] * it;
	}
	vector<int> numbers(n);
	for (int it = 0; it < n; ++it)
	{
		numbers[it] = it + 1;
	}
	string result = "";
	while (n-- > 0)
	{
		int index = (k - 1)/ (factor[n]);
		string str = to_string(numbers[index]);
		for (int it = index; it < (int)numbers.size() - 1; ++it)
		{
			numbers[it] = numbers[it + 1];
		}
		result += str;
		k = (k - 1) % factor[n] + 1;
	}
	return result;
}


int main() {
	/*
	cout << getPermutation(3, 3) << endl;
	cout << getPermutation(4, 9) << endl;
	cout << getPermutation(4, 1) << endl;
	cout << getPermutation(4, 19) << endl;
	cout << getPermutation(4, 24) << endl;
	cout << getPermutation(3, 6) << endl;
	cout << getPermutation(1, 1) << endl;
	cout << getPermutation(5, 120) << endl;
	*/
	cout << getPermutation(1, 1) << endl;
	cout << getPermutation(5, 120) << endl;

	for (int it = 1; it <= 2; ++it)
	{
		cout << getPermutation(2, it) << endl;
	}

	for (int it = 1; it <= 6; ++it)
	{
		cout << getPermutation(3, it) << endl;
	}
	cout << endl;
	for (int it = 1; it <= 24; ++it)
	{
		cout << getPermutation(4, it) << endl;
	}
	while (true);
	return 0;
}
