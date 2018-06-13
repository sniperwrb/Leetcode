#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	vector<unordered_set<int>> g;
	unordered_set<int> u;
	vector<int> s;
	int i, l, x, f;
	l = edges.size();
	auto it = u.begin();
	for (i = 0; i < l; i++)
	{
		g.push_back(u);
		s.push_back(0);
	}
	for (i = 0; i < l; i++)
	{
		g[edges[i][0] - 1].insert(edges[i][1] - 1);
		g[edges[i][1] - 1].insert(edges[i][0] - 1);
		s[edges[i][0] - 1]++;
		s[edges[i][1] - 1]++;
	}
	f = 0;
	while (f == 0)
	{
		f = 1;
		for (i = 0; i < l; i++)
		{
			if (s[i] == 1)
			{
				f = 0;
				it = g[i].begin();
				x = *it;
				g[x].erase(i);
				g[i].clear();
				s[x]--;
				s[i] = 0;
			}
		}
	}
	i = l - 1;
	while ((s[edges[i][0] - 1] == 0) || (s[edges[i][1] - 1] == 0))
	{
		i--;
	}
	return edges[i];
}

int main()
{
	vector<vector<int>> vv;
	vector<int> v;
	int i, n = 5;
	v.push_back(1); v.push_back(2); vv.push_back(v);
	v[0] = 2; v[1] = 3; vv.push_back(v);
	v[0] = 3; v[1] = 4; vv.push_back(v);
	v[0] = 1; v[1] = 4; vv.push_back(v);
	v[0] = 1; v[1] = 5; vv.push_back(v);
	v = findRedundantConnection(vv);
	for (i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cin >> i;
	return 0;
}