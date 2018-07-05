/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> v;
		int l = intervals.size();
		if (l == 0)
		{
			return v;
		}
		sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs)
		{
			return lhs.start < rhs.start;
		});
		int i, p, vl;
		v.push_back(intervals[0]);
		p = v[0].end;
		vl = 1;
		for (i = 1; i<l; i++)
		{
			if (intervals[i].start>p) //push
			{
				vl++;
				v.push_back(intervals[i]);
				p = v[vl - 1].end;
			}
			else if (intervals[i].end>p) //extend the range
			{
				p = intervals[i].end;
				v[vl - 1].end = p;
			}
		}
		return v;
	}
};