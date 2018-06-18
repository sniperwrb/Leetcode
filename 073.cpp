class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int i, j, r, c, b, f;
		r = matrix.size();
		c = matrix[0].size();
		f = 1;
		while (f == 1)
		{
			b = rand()*(RAND_MAX + 1) + rand();
			f = 0;
			for (i = 0; i<r; i++)
			{
				for (j = 0; j<c; j++)
				{
					if (matrix[i][j] == b)
					{
						f = 1;
					}
				}
			}
		}
		for (i = 0; i<r; i++)
		{
			f = 0;
			for (j = 0; j<c; j++)
			{
				if (matrix[i][j] == 0)
				{
					f = 1;
				}
			}
			if (f == 1)
			{
				for (j = 0; j<c; j++)
				{
					if (matrix[i][j] != 0)
					{
						matrix[i][j] = b;
					}
				}
			}
		}
		for (i = 0; i<c; i++)
		{
			f = 0;
			for (j = 0; j<r; j++)
			{
				if (matrix[j][i] == 0)
				{
					f = 1;
				}
			}
			if (f == 1)
			{
				for (j = 0; j<r; j++)
				{
					if (matrix[j][i] != 0)
					{
						matrix[j][i] = b;
					}
				}
			}
		}
		for (i = 0; i<r; i++)
		{
			for (j = 0; j<c; j++)
			{
				if (matrix[i][j] == b)
				{
					matrix[i][j] = 0;
				}
			}
		}
		return;
	}
};