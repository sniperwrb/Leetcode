#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
	vector<int> v; //0=unvisited, 1=class 1, 2=class 2
	vector<int> q; //queue of what we should visit
	int i, j, l, l1, p, pq, lq, w, x;
	l = graph.size();
	if (l == 1)
	{
		return true;
	}
	for (i = 0; i<l; i++)
	{
		v.push_back(0);
	}
	p = 0;
	pq = 0;
	lq = 0;
	while (p<l)
	{
		while (pq<lq) //clearing the wish list
		{
			x = q[pq];
			l1 = graph[x].size();
			for (j = 0; j<l1; j++)
			{
				w = graph[x][j];
				if (v[w] == 0)
				{
					v[w] = 3 - v[x];
					q.push_back(w);
					lq++;
				}
				else if (v[w] == v[x])
				{
					return false;
				}
			}
			pq++;
		}
		//new subgraph
		while ((graph[p].size() == 0) || (v[p]>0))
		{ //lone or visited vertex
			p++;
			if (p >= l)
			{
				return true;
			}
		}
		v[p] = 1;
		//fulfilling the wish list
		l1 = graph[p].size();
		for (j = 0; j<l1; j++)
		{
			w = graph[p][j];
			if (v[w] == 0)
			{
				v[w] = 3 - v[p];
				q.push_back(w);
				lq++;
			}
			else if (v[w] == v[p])
			{
				return false;
			}
		}
	}
}

int main()
{
	vector<vector<int>> vv;
	vector<int> v1;
	int i;
	v1.push_back(1); v1.push_back(3); vv.push_back(v1); v1.clear();
	v1.push_back(0); v1.push_back(2); vv.push_back(v1); v1.clear();
	v1.push_back(3); v1.push_back(1); vv.push_back(v1); v1.clear();
	v1.push_back(0); v1.push_back(2); vv.push_back(v1); v1.clear();
	bool b;
	b = isBipartite(vv);
	cout << b;
	cin >> i;
	return 0;
}