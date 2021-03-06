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

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

bool compr(Interval first, Interval second)
{
	return first.start < second.start;
}
vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.size() <= 1)
	{
		return intervals;
	}
	sort(intervals.begin(), intervals.end(), compr);
	vector<Interval> result;
	Interval* newInterval = new Interval(intervals[0].start, intervals[0].end);;
	for (size_t iter = 1; iter < intervals.size(); ++iter)
	{
		if (intervals[iter].start <= newInterval->end)
		{
			if (intervals[iter].end > newInterval->end)
			{
				newInterval->end = intervals[iter].end;
			}
		}
		else
		{
			result.push_back(*newInterval);
			newInterval = new Interval(intervals[iter].start, intervals[iter].end);
		}
	}
	result.push_back(*newInterval);
	return result;
}
void printIntervals(vector<Interval> intervals)
{
	for (size_t it = 0; it < intervals.size(); ++it)
	{
		cout << intervals[it].start << " " << intervals[it].end << endl;
	}
}

int main() {
	//[[1,3],[2,6],[8,10],[15,18]]
	
	vector<Interval> vct;
	
	vct.push_back(*(new Interval(1, 3)));
	
	vct.push_back(*(new Interval(2, 6)));
	
	vct.push_back(*(new Interval(6, 10)));

	vct.push_back(*(new Interval(15, 18)));
	vct.push_back(*(new Interval(18, 20)));
	
	printIntervals(vct);
	cout << "After merge " << endl;
	vector<Interval> res = merge(vct);
	printIntervals(res);
	
	
	while (true);
	return 0;
}
