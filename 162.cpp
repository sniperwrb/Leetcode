class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int l = nums.size();
		if ((l <= 1) || (nums[l - 1]>nums[l - 2]))
		{
			return (l - 1);
		}
		if (nums[0]>nums[1])
		{
			return 0;
		}
		int p, q, r;
		p = 0; q = l - 1;
		while (q - p>1)
		{
			r = (p + q) / 2;
			if ((nums[r]>nums[r - 1]) && (nums[r]>nums[r + 1]))
			{
				return r;
			}
			if (nums[r]>nums[r - 1])
			{
				p = r;
			}
			else
			{
				q = r;
			}
		}
		return -1;
	}
};