class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size();
		if (r == 0)
		{
			return false;
		}
		int c = matrix[0].size();
		if (c == 0)
		{
			return false;
		}
		int i, o, p, q;
		for (i = 0; i<r; i++)
		{
			if (target>matrix[i][c - 1])
			{
				continue;
			}
			if (target<matrix[i][0])
			{
				return false;
			}
			if ((target == matrix[i][0]) || (target == matrix[i][c - 1]))
			{
				return true;
			}
			o = 0; q = c - 1;
			while (q - o>1)
			{
				p = (o + q) / 2;
				if (target == matrix[i][p])
				{
					return true;
				}
				if (target>matrix[i][p])
				{
					o = p;
				}
				else
				{
					q = p;
				}
			}
		}
		return false;
	}
};