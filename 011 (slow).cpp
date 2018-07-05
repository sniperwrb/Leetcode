class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		// find the highest one and its position
		int i, p;
		int mh = 0;
		for (i = 0; i<n; i++)
		{
			if (height[i]>mh)
			{
				mh = height[i];
				p = i;
			}
		}
		if (mh <= 0)
		{
			return 0;
		}
		//find the largest bin with it
		int ms = 0;
		for (i = 0; i<n; i++)
		{
			if (height[i] * abs(p - i)>ms)
			{
				ms = height[i] * abs(p - i);
			}
		}
		// decide the minimum height and minimum width for searching
		int j;
		int mh_global = ms / (n - 1);
		int mw_global = ms / mh;
		int mw;
		for (i = 0; i<n - 1 - mw_global; i++)
		{
			mw = ms / max(height[i], 1);
			for (j = i + mw; j<n; j++)
			{
				if (min(height[i], height[j])*(j - i)>ms)
				{
					ms = min(height[i], height[j])*(j - i);
					mh_global = ms / (n - 1 - i);
					mw_global = ms / mh;
				}
			}
		}
		return ms;
	}
};