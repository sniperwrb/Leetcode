class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int p, q, m;
		p = 0; q = n - 1; m = 0;
		while (p<q)
		{
			if (height[p]<height[q])
			{
				m = max(m, (q - p)*height[p]);
				p++;
			}
			else
			{
				m = max(m, (q - p)*height[q]);
				q--;
			}
		}
		return m;
	}
};