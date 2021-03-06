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


int divide(int dividend, int divisor) {
	if (!divisor || (dividend == INT32_MIN && divisor == -1))
	{
		return INT32_MAX;
	}
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long div = dividend;
	long long dis = divisor;
	div = (div < 0) ? -div : div;
	dis = (dis < 0) ? -dis : dis;
	long long res = 0;
	while (div >= dis)
	{
		long long temp_dis = dis;
		long long temp_res = 1;
		while (div >= (temp_dis << 1))
		{
			temp_dis <<= 1;
			temp_res <<= 1;
		}
		res += temp_res;
		div -= temp_dis;
	}
	return (int)(res*sign);
}


int main() {
	
	cout << divide(15, 3) << endl;
	cout << divide(15, 4) << endl;
	cout << divide(15, 23) << endl;
	cout << divide(16, 4) << endl;
	cout << divide(16, 3) << endl;
	
	cout << divide(-16, 3) << endl;
	cout << divide(INT32_MIN, -1) << endl;
	
	cout << divide(INT32_MIN, 1) << endl;
	cout << divide(INT32_MAX, 3) << endl;
	cout << divide(INT32_MIN, -2) << endl;
	while(true);
	return 0;
}