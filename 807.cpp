int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	int r, c, i, j, m, s;
	vector<int> sky_ew, sky_sn;
	r = grid.size();
	c = grid[0].size();
	for (i = 0; i<r; i++)
	{
		m = 0;
		for (j = 0; j<c; j++)
		{
			if (grid[i][j]>m)
			{
				m = grid[i][j];
			}
		}
		sky_ew.push_back(m);
	}
	for (i = 0; i<c; i++)
	{
		m = 0;
		for (j = 0; j<r; j++)
		{
			if (grid[j][i]>m)
			{
				m = grid[j][i];
			}
		}
		sky_sn.push_back(m);
	}
	s = 0;
	for (i = 0; i<r; i++)
	{
		for (j = 0; j<c; j++)
		{
			s = s + min(sky_ew[i], sky_sn[j]) - grid[i][j];
		}
	}
	return s;
}