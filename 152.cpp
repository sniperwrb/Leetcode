class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int maxp, maxc, minc, i, n, t;
		n = nums.size();
		if (n == 1)
		{
			return nums[0];
		}
		maxp = -INT_MAX; maxc = 0; minc = 0;
		for (i = 0; i<n; i++)
		{
			if (nums[i]>0)
			{
				maxc = max(maxc, 1)*nums[i];
				minc *= nums[i];
			}
			else if (nums[i]<0)
			{
				t = minc;
				minc = max(maxc, 1)*nums[i];
				maxc = t * nums[i];
			}
			else
			{
				maxc = 0;
				minc = 0;
			}
			maxp = max(maxp, maxc);
		}
		return maxp;
	}
};