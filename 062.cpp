class Solution {
public:
	int uniquePaths(int m, int n) {
		if ((m == 1) || (n == 1))
		{
			return 1;
		}
		if (n == 2)
		{
			return m;
		}
		if (m == 2)
		{
			return n;
		}
		vector<int> v(m, 1);
		int i, j;
		for (i = 2; i <= n; i++)
		{
			for (j = 1; j<m; j++)
			{
				v[j] = v[j - 1] + v[j];
			}
		}
		return(v[m - 1]);
	}
};