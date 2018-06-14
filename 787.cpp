int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
	vector<int> p(n, 1000001);
	vector<int> q;
	vector<vector<int>> g(n, p);
	int h, i, j, l, m;
	l = flights.size();
	for (i = 0; i<l; i++)
	{
		g[flights[i][0]][flights[i][1]] = flights[i][2];
	}
	for (i = 0; i<n; i++)
	{
		g[i][i] = 0;
	}
	p = g[src];
	for (h = 0; h<K; h++)
	{
		q = p;
		for (i = 0; i<n; i++)
		{
			m = q[0] + g[0][i];
			for (j = 1; j<n; j++)
			{
				if (q[j] + g[j][i]<m)
				{
					m = q[j] + g[j][i];
				}
			}
			p[i] = m;
		}
	}
	return(p[dst]<1000000 ? p[dst] : -1);
}