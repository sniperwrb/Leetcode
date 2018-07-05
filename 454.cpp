class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int l = A.size();
		int n = 2 * l*l + 1;
		int i, j, p, x;
		int m = -INT_MAX;
		vector<int> h(n, m); // hashlist
		vector<int> s(n, 0); // count
		int res = 0;
		for (i = 0; i<l; i++)
		{
			for (j = 0; j<l; j++)
			{
				x = A[i] + B[j];
				p = abs(x) % n;
				while ((h[p] != m) && (h[p] != x))
				{
					p = (p + 1) % n;
				}
				h[p] = x;
				s[p]++;
			}
		}
		for (i = 0; i<l; i++)
		{
			for (j = 0; j<l; j++)
			{
				x = -(C[i] + D[j]);
				p = abs(x) % n;
				while ((h[p] != m) && (h[p] != x))
				{
					p = (p + 1) % n;
				}
				if (h[p] == x)
				{
					res += s[p];
				}
			}
		}
		return res;
	}
};