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



void Myswap(vector<int>::iterator one, vector<int>::iterator two)
{
	int tmp = *one;
	*one = *two;
	*two = tmp;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i1 = m - 1, i2 = n - 1, r = m + n - 1;
	while (i2 >= 0)
	{
		nums1[r--] = (i1 >= 0 && nums1[i1] > nums2[i2]) ? nums1[i1--] : nums2[i2--];
	}
}
/*
int divide(int dividend, int divisor) {

}
*/
int main() {

	cout << mySqrt(2147395600);
	while(true);
	return 0;
}