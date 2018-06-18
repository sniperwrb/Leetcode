class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> v;
		int r, c, x1, x2, y1, y2, i, k;
		r = matrix.size();
		if (r == 0)
		{
			return v;
		}
		c = matrix[0].size();
		if (c == 0)
		{
			return v;
		}
		x1 = 0;
		x2 = c - 1;
		y1 = 0;
		y2 = r - 1;
		k = 0;
		while ((x2 >= x1) && (y2 >= y1))
		{
			if (k % 4 == 0) // top left -> right
			{
				for (i = x1; i <= x2; i++)
				{
					v.push_back(matrix[y1][i]);
				}
				y1++;
			}
			else if (k % 4 == 1) // right top -> bot
			{
				for (i = y1; i <= y2; i++)
				{
					v.push_back(matrix[i][x2]);
				}
				x2--;
			}
			else if (k % 4 == 2) // bot right -> left
			{
				for (i = x2; i >= x1; i--)
				{
					v.push_back(matrix[y2][i]);
				}
				y2--;
			}
			else if (k % 4 == 3) // left bot -> top
			{
				for (i = y2; i >= y1; i--)
				{
					v.push_back(matrix[i][x1]);
				}
				x1++;
			}
			k++;
		}
		return v;
	}
};