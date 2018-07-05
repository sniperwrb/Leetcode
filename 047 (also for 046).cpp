class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> x;
		int l = nums.size();
		if (l <= 0)
		{
			return x;
		}
		vector<int> k = nums; // the array
		sort(k.begin(), k.end());
		x.push_back(k);
		if (l <= 1)
		{
			return x;
		}
		vector<int> d(l, 1); // direction of each array element
		int i, j, t, td; // temp direction
		int m, p; //value and position of min mobile slot
		p = 0;
		while ((p<l) && (k[p] >= k[p + 1]))
		{
			p++;
		}
		while (p<l)
		{
			// move
			td = d[p];
			m = k[p]; k[p] = k[p + td]; k[p + td] = m;
			t = d[p]; d[p] = d[p + td]; d[p + td] = t;
			p += td;
			// post-processing
			if (td>0)
			{
				for (i = p + 2; i<l; i++)
				{
					if (k[i] == m)
					{
						// be the same value and on its way, pulled
						t = k[i];
						for (j = i; j>p + 1; j--)
						{
							k[j] = k[j - 1];
						}
						k[p + 1] = t;
						t = d[i];
						for (j = i; j>p + 1; j--)
						{
							d[j] = d[j - 1];
						}
						d[p + 1] = t;
					}
				}
			}
			else
			{
				for (i = p - 2; i >= 0; i--)
				{
					if (k[i] == m)
					{
						// be the same value and on its way, pulled
						t = k[i];
						for (j = i; j<p - 1; j++)
						{
							k[j] = k[j + 1];
						}
						k[p - 1] = t;
						t = d[i];
						for (j = i; j<p - 1; j++)
						{
							d[j] = d[j + 1];
						}
						d[p - 1] = t;
					}
				}
			}
			x.push_back(k);
			for (i = 0; i<l; i++)
			{
				if (k[i]<m) // be smaller, inverted
				{
					d[i] = -d[i];
				}
			}
			// find the min mobile slot
			m = INT_MAX;
			p = l;
			for (i = 0; i<l; i++)
			{
				if (d[i]>0) // facing right
				{
					if ((i<l - 1) && (k[i]<k[i + 1]) && (k[i] <= m))
					{
						m = k[i];
						p = i;
					}
				}
				else // facing left, strict
				{
					if ((i>0) && (k[i]<k[i - 1]) && (k[i]<m))
					{
						m = k[i];
						p = i;
					}
				}
			}
		}
		return x;
	}
};