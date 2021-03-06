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
#include <stack>
#include <algorithm>
#include <time.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
	if (nums.size() == 0)
	{
		return 0;
	}
	vector<int> max_length;
	max_length.push_back(nums[nums.size()-1]);
	for (int it = nums.size() - 2; it >= 0; --it)
	{
		int begin = 0, end = max_length.size() - 1;
		if (max_length[end] > nums[it])
		{
			max_length.push_back(nums[it]);
		}
		else if (max_length[begin] < nums[it])
		{
			max_length[begin] = nums[it];
		}
		else
		{
			while (begin < end)
			{
				int middle = (begin + end + 1) / 2;
				if (max_length[middle] == nums[it])
				{
					begin = middle;
					break;
				}
				if (max_length[middle] > nums[it])
				{
					begin = middle;
				}
				else
				{
					end = middle - 1;
				}
			}
			if (max_length[begin] > nums[it] && max_length[begin + 1] < nums[it])
			{
				max_length[begin + 1] = nums[it];
			}
		}
	}
	return max_length.size();
}

int lengthOfLIS2(vector<int>& nums) {
	vector<pair<int, int>> comp;
	int max_glob = 1; 
	for (int it = nums.size() - 1; it >= 0; --it)
	{
		int max = 1;
		for (int it_c = comp.size() - 1; it_c >= 0; --it_c)
		{
			if (nums[it] < comp[it_c].first && max < comp[it_c].second + 1)
			{
				max = comp[it_c].second + 1;
			}
		}
		comp.push_back(pair<int, int>(nums[it], max));
		max_glob = (max > max_glob) ? max : max_glob;
	}
	return max_glob;
}


int search(vector<int> input, int target)
{
	int begin = 0, end = input.size() - 1, center = 0;
	if (input[end] < target)
	{
		return end + 1;
	}
	if (input[begin] > target)
	{
		return -1;
	}
	while (begin < end)
	{
		if (input[(begin + end) / 2] == target)
		{
			return (begin + end) / 2;
		}
		if (input[(begin + end) / 2] > target)
		{
			end = (begin + end) / 2;
		}
		else
		{
			begin = (begin + end) / 2 + 1;
		}
	}
	return end;
}

void test(vector<int>& nums, int max_length, int max)
{
	int length = rand() % max_length + 1;
	for (int i = 0; i < length; ++i)
	{
		int num = rand() % max;
		nums.push_back(num);
		cout << num << " ";
	}
	cout << endl;

}

int main() {
	vector<int> nums;
	
	nums = {10, 9, 2, 2, 2, 2, 5, 3, 7, 101, 18};
	cout << lengthOfLIS(nums) << endl;

	nums = { 10, 9, 2, 2, 2, 2, 5, 3, 7, 101, 18 };
	cout << lengthOfLIS2(nums) << endl;

	nums = {};
	cout << lengthOfLIS(nums) << endl;

	nums = {10};
	cout << lengthOfLIS(nums) << endl;

	nums = { 1, 10, 9, 2, 1 ,2, 5, 3, 7, 101, 18 };
	cout << lengthOfLIS(nums) << endl;


	nums = { 3, 3, 3, 3, 3};
	cout << lengthOfLIS(nums) << endl;

	nums = { 3, 3, 4, 3, 3 };
	cout << lengthOfLIS(nums) << endl;

	nums = { 45, 6 , 7, 3, 10, 14, 6, 23, 67, 2, 90};
	cout << lengthOfLIS(nums) << endl;
	cout << lengthOfLIS2(nums) << endl;
	bool isGood = true;
	srand(time(NULL));
	for (int it = 0; it < 5; ++it)
	{
		vector<int> nums;
		test(nums, 100 , 1500);
		cout << "fast: " << endl;
		int res_fast = lengthOfLIS(nums);
		cout << res_fast << endl;
		cout << "slow: " << endl;
		int res_slow = lengthOfLIS2(nums);
		cout << res_slow << endl;
		if (res_fast != lengthOfLIS2(nums))
		{
			isGood = false;
		}
	}
	cout << "Is Good: " << isGood << endl;

	/*
	vector<int> seq = { 1, 3, 4, 8, 10, 12, 14};
	cout << search(seq, 0) << endl;
	cout << search(seq, 2) << endl;
	cout << search(seq, 3) << endl;
	cout << search(seq, 5) << endl;
	cout << search(seq, 6) << endl;
	cout << search(seq, 9) << endl;
	cout << search(seq, 11) << endl;
	cout << search(seq, 13) << endl;
	cout << search(seq, 14) << endl;
	cout << search(seq, 100) << endl;
	*/
	while (true);
	return '0';
}



/*

void print(vector<int> input)
{
for (vector<int>::iterator it = input.begin(); it != input.end(); ++it)
{
cout << *it << " ";
}
cout << endl;
}

void print(ListTNode* input)
{
while (input != NULL)
{
cout << input->val << "->";
input = input->next;
}
cout << "NULL" << endl;
}

ListTNode* hd = new ListTNode(-'1');
ListTNode* cur = hd;
cur->next = new ListTNode(5);
cur = cur->next;
cur->next = new ListTNode(3);
cur = cur->next;
cur->next = new ListTNode(4);
cur = cur->next;
cur->next = new ListTNode('0');
cur = cur->next;
cur->next = new ListTNode(-9);
cur = cur->next;
cur->next = new ListTNode(-4);
cur = cur->next;
cur->next = new ListTNode(7);
test = copyList(hd);
print(sortList(test));

ListTNode* copyList(ListTNode* input)
{
ListTNode* copy = NULL;
ListTNode* it = input;
ListTNode* copyHead = copy;
while (it != NULL)
{
if (copy == NULL)
{
copy = new ListTNode(it->val);
copyHead = copy;
}
else
{
copy->next = new ListTNode(it->val);
copy = copy->next;
}
it = it->next;
}
return copyHead;
}

struct TNode {
int val;
TNode *left;
TNode *right;
TNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
/*
void printMatrix(vector<vector<int>> matrix)
{
for (int i = '0'; i < (int)matrix.size(); ++i)
{
for (int j= '0'; j < (int)matrix[i].size(); ++j)
{
cout << matrix[i][j] << " ";
}
cout << endl;
}
}
*/

/*
void minotaurMaze(vector<vector<int>>& grid,
int x,
int y,
int& result)
{
if (x == (int)grid.size() - '1'
&& y == (int)grid['0'].size() - '1')
{
++result;
}
else
{
if (x < (int)grid.size() - '1' && grid[x + '1'][y] != '1')
{
minotaurMaze(grid, x + '1', y, result);
}
if (y < (int)grid['0'].size() - '1' && grid[x][y + '1'] != '1')
{
minotaurMaze(grid, x, y + '1', result);
}
}
}
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
if (grid.size() == '0'
|| grid['0'].size() == '0'
|| grid['0']['0'] == '1')
{
return '0';
}
int result = '0';
(grid, '0', '0', result);
return result;
}

int paths(vector<vector<int>>& grid,
int x,
int y)
{
if (x == '0' && y == '0')
{
return grid['0']['0'] == '1' ? '0' : '1';
}
else
{
if (grid[x][y] == '1')
{
return '0';
}
else
{
return paths(grid, x - '1', y) + paths(grid, x, y - '1');
}
}
}
*/

/*

struct ListTNode {
int val;
ListTNode *next;
ListTNode(int x) : val(x), next(NULL) {}

};


ListTNode * makeList(int n)
{
ListTNode * begin_p = new ListTNode('0');
ListTNode * prev_p = begin_p;
for (int it = '1'; it < n; ++it)
{
ListTNode * new_p =  new ListTNode(it);
prev_p->next = new_p;
prev_p = new_p;
}
return begin_p;
}
void printList(ListTNode * begin)
{
cout << begin->val;
for (ListTNode* TNode = begin->next; TNode != NULL; TNode = TNode->next)
{
cout << "->" << TNode->val;
}
cout << endl;
}
*/
