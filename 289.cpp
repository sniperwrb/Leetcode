class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int i, j, r, c;
		r = board.size();
		c = board[0].size();
		for (i = 1; i<r; i++)
		{
			for (j = 0; j<c; j++)
			{
				board[i][j] += (board[i - 1][j] % 2) * 2;
				board[i - 1][j] += (board[i][j] % 2) * 2;
			}
		}
		for (i = 0; i<r; i++)
		{
			for (j = 1; j<c; j++)
			{
				board[i][j] += (board[i][j - 1] % 2) * 2;
				board[i][j - 1] += (board[i][j] % 2) * 2;
			}
		}
		for (i = 1; i<r; i++)
		{
			for (j = 1; j<c; j++)
			{
				board[i][j] += (board[i - 1][j - 1] % 2) * 2;
				board[i - 1][j - 1] += (board[i][j] % 2) * 2;
			}
		}
		for (i = 1; i<r; i++)
		{
			for (j = 1; j<c; j++)
			{
				board[i - 1][j] += (board[i][j - 1] % 2) * 2;
				board[i][j - 1] += (board[i - 1][j] % 2) * 2;
			}
		}
		for (i = 0; i<r; i++)
		{
			for (j = 0; j<c; j++)
			{
				board[i][j] = (board[i][j] >= 5) && (board[i][j] <= 7);
			}
		}
		return;
	}
};