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

using namespace std;


class TreeNode1 {
public:
	vector<TreeNode1*> next;
	bool End;
	TreeNode1()
	{
		End = false;
		next = vector<TreeNode1*>(26, NULL);
	}
};

class Trie {
public:
	TreeNode1 * root;
	/** Initialize your data structure here. */
	Trie() {
		root = new TreeNode1();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TreeNode1* node = root;
		int it = 0;
		for (; it < word.size(); ++it)
		{
			if (node->next[word[it] - 'a'] == NULL)
			{
				node->next[word[it] - 'a'] = new TreeNode1();
			}
			node = node->next[word[it] - 'a'];
		}
		node->End = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TreeNode1* node = root;
		for (int it = 0; it < word.size() && node != NULL; ++it)
		{
			node = node->next[word[it] - 'a'];
		}
		if (node != NULL && node->End)
		{
			return true;
		}
		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TreeNode1* node = root;
		for (int it = 0; it < prefix.size() && node != NULL; ++it)
		{
			node = node->next[prefix[it] - 'a'];
		}
		if (node != NULL)
		{
			return true;
		}
		return false;
	}
};

int main() {

	Trie* trie = new Trie();
	trie->insert("ab") ;
	cout << trie->search("a") << "0" << endl;
	cout << trie->startsWith("a") << "1" << endl;

	while (true);
	return 0;
}



/*

void print(ListTNode* input)
{
while (input != NULL)
{
cout << input->val << "->";
input = input->next;
}
cout << "NULL" << endl;
}

ListTNode* hd = new ListTNode(-1);
ListTNode* cur = hd;
cur->next = new ListTNode(5);
cur = cur->next;
cur->next = new ListTNode(3);
cur = cur->next;
cur->next = new ListTNode(4);
cur = cur->next;
cur->next = new ListTNode(0);
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
for (int i = 0; i < (int)matrix.size(); ++i)
{
for (int j= 0; j < (int)matrix[i].size(); ++j)
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
if (x == (int)grid.size() - 1
&& y == (int)grid[0].size() - 1)
{
++result;
}
else
{
if (x < (int)grid.size() - 1 && grid[x + 1][y] != 1)
{
minotaurMaze(grid, x + 1, y, result);
}
if (y < (int)grid[0].size() - 1 && grid[x][y + 1] != 1)
{
minotaurMaze(grid, x, y + 1, result);
}
}
}
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
if (grid.size() == 0
|| grid[0].size() == 0
|| grid[0][0] == 1)
{
return 0;
}
int result = 0;
(grid, 0, 0, result);
return result;
}

int paths(vector<vector<int>>& grid,
int x,
int y)
{
if (x == 0 && y == 0)
{
return grid[0][0] == 1 ? 0 : 1;
}
else
{
if (grid[x][y] == 1)
{
return 0;
}
else
{
return paths(grid, x - 1, y) + paths(grid, x, y - 1);
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
ListTNode * begin_p = new ListTNode(0);
ListTNode * prev_p = begin_p;
for (int it = 1; it < n; ++it)
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
