#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>

using namespace std;

double myPow(double x, int n) {
	int sign = 1;
	unsigned int pw  = 1;
	if (n < 0)
	{
		sign = -1;
		pw = -1 * n;
	}
	else if (n == 0)
	{
		return 1;
	}
	else
	{
		pw = n;
	}
	double fact = x;
	double result = 1;
	while (pw > 0)
	{
		int bit = pw % 2; 
		pw /= 2;
		if(bit != 0)
		{
			result *= fact;
		}
		fact *= fact;
	}
	if (sign == -1)
	{
		result = 1 / result;
	}
	return result;
}
	


int main() {
	/*
	cout << myPow(2, 10) << "\n";
	cout << myPow(2.1, 3) << "\n";
	cout << myPow(2, -2) << "\n";
	cout << myPow(90, 0) << "\n";
	cout << myPow(-3, 5) << "\n";
	//long n = -2147483648;
	*/
	cout << myPow(2.00000, 2147483648) << "\n";

	

	while(true);
	return 0;
}