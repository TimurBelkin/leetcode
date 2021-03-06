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


void printVecVecStr(vector<vector<string>> input_vec)
{
	for (vector<vector<string>>::iterator it = input_vec.begin(); it < input_vec.end(); ++it)
	{
		for (vector<string>::iterator iter = it->begin(); iter < it->end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> result;
	if (strs.size() == 0)
	{
		return result;
	}
	vector<pair<string, int>> sorted_strs;
	for (size_t it = 0; it < strs.size(); ++it)
	{
		pair<string, int> element(strs[it], it);
		sort(element.first.begin(), element.first.end());
		sorted_strs.push_back(element);
	}
	sort(sorted_strs.begin(), sorted_strs.end());
	//printVec(sorted_strs);
	string prev = "";
	for (size_t it = 0; it < sorted_strs.size(); ++it)
	{
		if (prev != sorted_strs[it].first || it == 0)
		{
			vector<string> new_list;
			new_list.push_back(strs[sorted_strs[it].second]);
			result.push_back(new_list);
			prev = sorted_strs[it].first;
		}
		else
		{
			result[result.size() - 1].push_back(strs[sorted_strs[it].second]);
		}
	}
	return result;
}

void printVec(vector<string> input_vec)
{
	for (vector<string>::iterator it = input_vec.begin(); it < input_vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
//["eat", "tea", "tan", "ate", "nat", "bat"]
	vector<string> words;
	
	words.push_back("eat");
	/*
	words.push_back("tea");
	words.push_back("tan");
	words.push_back("ate");
	words.push_back("nat");
	words.push_back("bat");
	*/
	printVec(words);
	vector<vector<string>> res = groupAnagrams(words);
	printVecVecStr(res);
	while (true);
	return 0;
}
