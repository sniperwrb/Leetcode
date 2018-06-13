#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	int i, l, q, dc;
	l = graph.size();
	vector<int> s(l, 0); //safety. 0=unknown, 1=safe, -1=visited, -2=dangerous
	vector<int> st, p, v; //st is stack
	//p is the point in the child list: visit graph[st[k]][p[k]] next
	i = 0;
	while (i < l)
	{
		if (s[i] != 0)
		{
			i++;
		}
		else
		{
			st.clear();
			p.clear();
			q = 0; //the end point of stack
			dc = 0; //the chain is dangerous
			st.push_back(i);
			p.push_back(0);
			while ((q >= 0) && (dc == 0))
			{
				// check the safety
				if (p[q] >= graph[st[q]].size())
				{
					s[st[q]] = 1;
					st.pop_back();
					p.pop_back();
					q--;
				}
				else if (s[graph[st[q]][p[q]]]>0)
				{
					p[q]++;
				}
				else if (s[graph[st[q]][p[q]]] == 0)
				{
					st.push_back(graph[st[q]][p[q]]);
					p.push_back(0);
					q++;
					s[st[q]] = -1;
				}
				else
				{
					dc = -1;
				}
			}
			if (dc != 0)
			{
				while (q >= 0)
				{
					s[st[q]] = -2;
					q--;
				}
				st.clear();
				p.clear();
			}
		}
	}
	for (i = 0; i < l; i++)
	{
		if (s[i] == 1)
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