#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>

using namespace std;

pair <int, int>  findTag(pair <int, int> border, vector<string> doc, string tag)
{
	int begin = -1;
	int parity = 0;
	for (int it = border.first; it < border.second; ++it)
	{
		size_t res = doc[it].find("<" + tag + " ");
		if (res == 0)
		{
			if (parity != 0)
			{
				return pair <int, int>(-1, -1);
			}
			begin = it;
			break;
		}
		else if( res == string::npos)
		{
			res = doc[it].find("</");
			if (res != string::npos)
			{
				--parity;
			}
			else
			{
				++parity;
			}
		}
	}
	if (begin == -1)
	{
		return pair <int, int>(-1, -1);
	}

	int end = 0;

	for (int it = begin; it < border.second; ++it)
	{
		size_t res = doc[it].find("</" + tag + ">");
		if (res == 0)
		{
			end = it;
			break;
		}
	}

	return  pair <int, int> (begin, end);
}

string getAttr(int index, vector<string> doc, string attrName)
{
	size_t res = doc[index].find(" " + attrName + " = ");
	if (res == string::npos)
	{
		return "Not Found!";
	}
	else
	{
		size_t begin = doc[index].find('\"', res + 1);
		size_t end = doc[index].find('\"', begin + 1);
		return doc[index].substr(begin + 1, end - begin - 1);
	}
}

vector<string> splitString(string object, char delimiter)
{
	vector<string> result = vector<string>();
	string::iterator start = object.begin();
	for (string::iterator iter = object.begin(); iter != object.end(); ++iter)
	{
		if (*iter == delimiter)
		{
			result.push_back(object.substr(start - object.begin(), iter - start));
			start = iter + 1;
		}
	}
	result.push_back(object.substr(start - object.begin(), object.end() - object.begin()));
	return result;
}

string performQuery(string qr, vector<string> doc)
{
	vector<string> pathToAttr = splitString(qr, '~');
	string attrName = pathToAttr[1];
	pathToAttr = splitString(pathToAttr[0], '.');
	int start = 0;
	pair <int, int> border(-1, doc.size());
	for (vector<string>::iterator iter = pathToAttr.begin(); iter < pathToAttr.end(); ++iter)
	{
		border.first += 1;
		border = findTag(border, doc, *iter);
		if (border.first == -1)
		{
			return "Not Found!";
		}
	}
	return getAttr(border.first, doc, attrName);
}

void standardInput(vector <string>* query, vector<string>* doc)
{
	int length = 0, qNum = 0;
	cin >> length >> qNum;
	string t;
	getline(cin, t);
	for (int it = 0; it < length; ++it)
	{
		string line;
		getline(cin, line);
		(*doc).push_back(line);


	}
	for (int it = 0; it < qNum; ++it)
	{
		string line;
		getline(cin, line);
		(*query).push_back(line);
	}
}

void fileInput(vector <string>* query, vector<string>* doc)
{
	ifstream myfile("C:/Outputfile/example.txt");
	if (myfile.is_open())
	{
		int length = 0, qNum = 0;
		myfile >> length >> qNum;
		string t;
		getline(myfile, t);
		for (int it = 0; it < length; ++it)
		{
			string line;
			getline(myfile, line);
		   (*doc).push_back(line);


		}
		for (int it = 0; it < qNum; ++it)
		{
			string line;
			getline(myfile, line);
			(*query).push_back(line);
		}

		myfile.close();
	}
}

void standardOutput(vector <string>& query, vector<string>& doc)
{
	for (int it = 0; it < query.size(); ++it)
	{
		cout << performQuery(query[it], doc) << '\n';
	}
}


	string longestPalindrome(string s) {
		if (s == "")
		{
			return "";
		}
		if (s.size() == 1)
		{
			return s;
		}
		int max_length = 0, begin = 0, end = 0;;
		for (int iter = 0; iter < s.size(); )
		{
			int backward_iter = iter - 1, forward_iter = iter + 1;
			while (forward_iter < s.size() && s[iter] == s[forward_iter])
			{
				++forward_iter;
			}
			iter = forward_iter;
			while (backward_iter >= 0
				&& forward_iter < s.size()
				&& s[backward_iter] == s[forward_iter])
			{
				backward_iter--;
				++forward_iter;
			}
			/*
			cout << "current char " << s[iter] << "\n";
			cout << "forward_iter " << forward_iter << "\n";
			cout << "backward_iter " << backward_iter << "\n";
			*/
			int current_length = (forward_iter - backward_iter) - 1;
			//cout << "current_lenght " << current_length << " " << (forward_iter - backward_iter) - 1 <<  "\n";
			if (current_length > max_length)
			{
				max_length = current_length;
				//cout << "max_lenght " << max_length << "\n";
				begin = backward_iter + 1;
				end = forward_iter;
			}

		}
		string result(s, begin, max_length);
		return result;
	}
int main() {
	cout << longestPalindrome("babad") << "\n";
	cout << longestPalindrome("cbbd") << "\n";
	cout << longestPalindrome("aaaa") << "\n";
	cout << longestPalindrome("acaaaad") << "\n";
	cout << longestPalindrome("acsdfgfdsd") << "\n";
	while(true);
	return 0;
}