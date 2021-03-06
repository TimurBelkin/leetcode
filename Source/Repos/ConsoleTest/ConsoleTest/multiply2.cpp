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
	vector<int> factor(k + 1, 1);
	for (int it = 1; it <= k; ++it)
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
		int index = k / (factor[k - 1] + 1);
		string str = to_string(numbers(index));
		for (int it = index; it < (int)numbers.size() - 1; ++it)
		{
			numbers[index] = numbers[index + 1];
		}
		result += str;
		k %= factor[k - 1];
	}
	return result;
}


int main() {

	cout << getPermutation(4, 9) << endl;
	while (true);
	return 0;
}
