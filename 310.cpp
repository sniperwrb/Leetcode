#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	//floyd-warshall is bad
	// delete leafs round by round until only 1 or 2 are left
	vector<unordered_set<int>> g;
	unordered_set<int> u;
	vector<int> v, s;
	int i, k, l, p;
	auto it = u.begin();
	for (i = 0; i < n; i++)
	{
		g.push_back(u);
	}
	l = edges.size();
	for (i = 0; i < l; i++)
	{
		g[edges[i].first].insert(edges[i].second);
		g[edges[i].second].insert(edges[i].first);
	}
	for (i = 0; i < n; i++)
	{
		s.push_back(g[i].size());
	}
	k = n;
	while (k > 2)
	{
		for (i = 0; i < n; i++)
		{
			s[i] = g[i].size();
		}
		for (i = 0; i < n; i++)
		{
			if (s[i] == 1)
			{
				k--;
				it = g[i].begin();
				p = *it;
				g[p].erase(i);
				g[i].clear();
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if ((s[i] > 1) || (n <= 2))
		{
			v.push_back(i);
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
	p.first = 1; p.second = 2; vp.push_back(p);
	p.first = 2; p.second = 3; vp.push_back(p);
	v = findMinHeightTrees(n, vp);
	for (i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cin >> i;
	return 0;
}