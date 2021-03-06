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
#include <unordered_map>

using namespace std;

string decodeString(string s) {
	string result = "";
	for (int it = 0; it < s.size(); )
	{
		if (s[it] > '0' && s[it] < '9')
		{
			int num = s[it] - '0';
			while (s[++it] != '[')
			{
				num *= 10;
				num += s[it] - '0';
			}
			int begin = ++it;
			int numSq = 1;
			while (numSq != 0)
			{
				if (s[it] == '[')
				{
					++numSq;
				}
				if (s[it] == ']')
				{
					--numSq;
				}
				++it;
			}
			int end = it - 1;
			string subString = decodeString(s.substr(begin, end - begin));
			while (num-- > 0)
			{
				result += subString;
			}
		}
		else
		{
			result += s[it];
			++it;
		}
	}
	return result;
}

int main() {
	string s;
	string result; ;

	s = "3[a]2[bc]";
	result  = "aaabcbc";

	s = decodeString(s);
	cout << s << " " << (result == s) << endl;
	
	s = "3[a2[c]]";
	result = "accaccacc";
	s = decodeString(s);
	cout << s << " " << (result == s) << endl;
	
	
	s = "2[abc]3[cd]ef";
	result = "abcabccdcdcdef";
	s = decodeString(s);
	cout << s << " " << (s == result) << endl;
	

	s = "3[a2[c]]";
	result = "accaccacc";
	s = decodeString(s);
	cout << s << " " << (result == s) << endl;

	s = "3[a2[c]]ty2[e2[m1[bn]w]]";
	result = "accaccacctyembnwmbnwembnwmbnw";
	s = decodeString(s);
	cout << s << " " << (result == s) << endl;

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
