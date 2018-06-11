#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<unordered_set<int>> p, q;
	// p is prerequisites, q is higher classes
	unordered_set<int> u;
	vector<int> v, s;
	// s is number of prerequisites
	int i, k, l, n, x, f;
	n = numCourses;
	for (i = 0; i < n; i++)
	{
		p.push_back(u);
		q.push_back(u);
	}
	l = prerequisites.size();
	for (i = 0; i < l; i++)
	{
		p[prerequisites[i].first].insert(prerequisites[i].second);
		q[prerequisites[i].second].insert(prerequisites[i].first);
	}
	for (i = 0; i < n; i++)
	{
		s.push_back(p[i].size());
	}
	k = n; // courses left
	while (k > 0)
	{
		f = 1;
		for (i = 0; i < n; i++)
		{
			if (s[i] == 0)
			{
				k--;
				v.push_back(i);
				for (auto it = q[i].begin(); it != q[i].end(); ++it)
				{
					x = *it;
					p[x].erase(i);
					s[x]--;
				}
				q[i].clear();
				f = 0;
				s[i] = -1;
			}
		}
		if (f == 1)
		{
			k = 0;
			v.clear();
		}
	}
	return v;
}

int main()
{
	vector<pair<int,int>> vp;
	pair<int, int> p;
	vector<int> v;
	int i, n = 4;
	p.first = 1; p.second = 0; vp.push_back(p);
	p.first = 2; p.second = 0; vp.push_back(p);
	p.first = 3; p.second = 1; vp.push_back(p);
	p.first = 0; p.second = 3; vp.push_back(p);
	v = findOrder(n, vp);
	for (i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cin >> i;
	return 0;
}