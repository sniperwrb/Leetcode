class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int i, j, n, t;
		n = matrix.size();
		for (i = 0; i<n; i++)
		{
			for (j = i; j<n - 1 - i; j++)
			{
				t = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = t;
			}
		}
		return;
	}
};