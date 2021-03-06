#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <string> 
#include <fstream>

using namespace std;




bool isMatchMy(string s, string p, size_t it_s, size_t it_p ) {

	char prec_elem = '.';
	for (;  it_p < p.size();)
	{
		if (it_p + 1 < p.size() && p[it_p + 1] == '*')
		{
			if (it_s != s.size())
			{
				if (p[it_p] == '.')
				{
					if (it_p + 2 == p.size())
					{
						return true;
					}
					else
					{
						while (it_s < s.size() && it_p < p.size())
						{
							if (isMatchMy(s, p, it_s, it_p + 2))
							{
								return true;
							}

								++it_s;

						}
						continue;
					}
				}
				prec_elem = p[it_p];
				while (it_s != s.size() && s[it_s] == prec_elem)
				{
					if (isMatchMy(s, p, it_s, it_p + 2))
					{
						return true;
					}
					++it_s;
				}
			}
			it_p += 2;
			continue;
		}
		else if (p[it_p] == '.')
		{
			if (it_s == s.size())
			{
				return false;
			}
		}
		else
		{
			if (it_s == s.size() || s[it_s] != p[it_p])
			{
				return false;
			}
		}
		++it_s;
		++it_p;
	}
	if (it_s == s.size() && it_p == p.size())
	{
		return true;
	}
	return false;
}

bool isMatch(string s, string p) {
	if (s == "" && p == "")
	{
		return true;
	}
	return isMatchMy(s, p, 0, 0);
}

int main() {
	cout << "aaa" << " " << "a*a " << "true " << isMatch("aaa", "a*a") << endl;
	cout << "abcdeca" << " " << ".*ca " << "true " << isMatch("abcdeca", ".*ca") << endl;
	cout << "ab" << " " << ".*c " << "false " <<  isMatch("ab", ".*c") << endl;
	cout << "abc" << " " << ".*c " << "true " << isMatch("abc", ".*c") << endl;
	cout << "abcdefc" << " " << ".*c " << "true " << isMatch("abcdefc", ".*c") << endl;
	cout << "ab" << " " << ".* " << "true " << isMatch("ab", ".*") << endl;
	cout << "aab" << " " << "c*a*b " << "true " << isMatch("aab", "c*a*b") << endl;
	cout << "mississippi" << " " << "mis*is*p*." << " false " << isMatch("mississippi", "mis*is*p*.") << endl;
	cout << "" << " " << ".*.*.*.*" << " true " << isMatch("", ".*.*.*.*") << endl;
	cout << "" << " " << ".*.*.*.*." << " false " << isMatch("", ".*.*.*.*.") << endl;
	cout << "op" << " " << "" << "false " << isMatch("op", "") << endl;
	cout << "aaabaabb" << " " << "a*ba*.." << " true " << isMatch("aaabaabb", "a*ba*..") << endl;
	while(true);
	return 0;
}