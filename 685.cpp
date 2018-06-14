#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
	// two parents only: delete the last parental edge
	// two parents and circle: delete the parental edge on the circle
	// circle only: delete the last edge on the circle
	int x, y, t, i, l = edges.size();
	vector<int> p(l + 1, 0); //parent
	vector<int> v(2, 0); // v[0] is v[1]'s second parent
	for (i = 0; i<l; i++)
	{
		if (p[edges[i][1]] == 0)
		{
			p[edges[i][1]] = edges[i][0];
		}
		else
		{
			v[1] = edges[i][1];
			v[0] = edges[i][0];
		}
	}
	if (v[0]>0) //dual parent existing
	{
		// try to find circle
		t = p[v[1]];
		while ((t>0) && (t != v[1]))
		{
			t = p[t];
		}
		if (t == v[1]) //"p[x]->x" is on the circle
		{
			v[0] = p[v[1]];
			return v;
		}
		// no circle, "v[0]->v[1]" or "p[v[1]]->v[1]"
		i = l - 1;
		while (edges[i][1] != v[1])
		{
			i--;
		}
		return edges[i];
	}
	// no dual parent, find the circle
	vector<int> s(l + 1, 0); // X is visited on turn s[X]
	s[0] = -1;
	y = 1; t = 1; //turn
	while (y <= l)
	{
		x = y;
		s[x] = t;
		while (s[p[x]] == 0)
		{
			x = p[x];
			s[x] = t;
		}
		if (s[p[x]] == t) //"x->...->p[x]->x" is the circle
		{
			unordered_set<int> u;
			u.insert(x);
			y = p[x];
			while (y != x)
			{
				u.insert(y);
				y = p[y];
			}
			i = l - 1;
			while (u.count(edges[i][1]) == 0)
			{
				i--;
			}
			return edges[i];
		}
		while ((y <= l) && (s[y] != 0))
		{
			y++;
		}
		t++;
	}
	return edges[l - 1];
}

int main()
{
	int i, n = 6;
	vector<vector<int>> vv;
	vector<int> v;
	v.push_back(1); v.push_back(2); vv.push_back(v);
	v[0] = 2; v[1] = 3; vv.push_back(v);
	v[0] = 1; v[1] = 3; vv.push_back(v);
	v[0] = 4; v[1] = 1; vv.push_back(v);
	v[0] = 1; v[1] = 5; vv.push_back(v);
	v[0] = 6; v[1] = 1; vv.push_back(v);
	v = findRedundantDirectedConnection(vv);
	/*vector<pair<int, int>> vp;
	pair<int, int> p;
	bool b;
	p.first = 0; p.second = 1; vp.push_back(p);
	p.first = 1; p.second = 2; vp.push_back(p);
	b = canFinish(n, vp);
	cout << b;*/
	for (i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cin >> i;
	return 0;
}