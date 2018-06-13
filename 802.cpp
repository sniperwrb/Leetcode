#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	vector<unordered_set<int>> g, h;
	unordered_set<int> u;
	vector<int> s, v;
	int i, j, l, f, x;
	l = graph.size();
	auto it = u.begin();
	for (i = 0; i < l; i++)
	{
		g.push_back(u);
		h.push_back(u);
		s.push_back(0);
	}
	for (i = 0; i < l; i++)
	{
		s[i] = graph[i].size();
		for (j = 0; j < s[i]; j++)
		{
			g[i].insert(graph[i][j]);
			h[graph[i][j]].insert(i);
		}
	}
	f = 0;
	while (f == 0)
	{
		f = 1;
		for (i = 0; i < l; i++)
		{
			if (s[i] == 0)
			{
				f = 0;
				for (it = h[i].begin(); it != h[i].end(); ++it)
				{
					x = *it;
					g[x].erase(i);
					s[x]--;
				}
				h[i].clear();
				s[i] = -1;
			}
		}
	}
	for (i = 0; i < l; i++)
	{
		if (s[i] == -1)
		{
			v.push_back(i);
		}
	}
	return v;
}

int main()
{
	vector<vector<int>> vv;
	vector<int> v;
	int i;
	v.push_back(1); v.push_back(2); vv.push_back(v);
	v[0] = 2; v[1] = 3; vv.push_back(v);
	v[0] = 5; v.pop_back(); vv.push_back(v);
	v[0] = 0; vv.push_back(v);
	v[0] = 5; vv.push_back(v);
	v.pop_back(); vv.push_back(v);
	vv.push_back(v);
	v = eventualSafeNodes(vv);
	for (i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cin >> i;
	return 0;
}