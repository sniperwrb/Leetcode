class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		//dfs
		vector<int> s, t; //stacks
		vector<vector<int>> v; //result
		int i, k, l;
		l = graph.size();
		s.push_back(0);
		for (i = 0; i<l; i++)
		{
			t.push_back(0);
		}
		k = 0; //size-1
		while (k >= 0)
		{
			if ((s[k] == l - 1) || (t[k] >= graph[s[k]].size()))
			{
				if (s[k] == l - 1)
				{
					v.push_back(s);
				}
				s.pop_back();
				k--;
			}
			else
			{
				s.push_back(graph[s[k]][t[k]]);
				t[k]++;
				t[k + 1] = 0;
				k++;
			}
		}
		return v;
	}
};