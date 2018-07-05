class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = nums.size();
		vector<int> v(2, -1);
		if (l == 0)
		{
			return v;
		}
		if (l == 1)
		{
			if (target == nums[0])
			{
				v[0] = 0; v[1] = 0;
			}
			return v;
		}
		if ((target<nums[0]) || (target>nums[l - 1]))
		{
			return v;
		}
		int p, q, r;
		// search for left range
		if (target == nums[0])
		{
			v[0] = 0;
		}
		else
		{
			p = 0; r = l - 1;
			while (r - p>1)
			{
				q = (p + r) / 2;
				if (target>nums[q])
				{
					p = q;
				}
				else // <=
				{
					r = q;
				}
			}
			if (nums[r] == target)
			{
				v[0] = r;
			}
		}
		// search for right range
		if (target == nums[l - 1])
		{
			v[1] = l - 1;
		}
		else
		{
			p = 0; r = l - 1;
			while (r - p>1)
			{
				q = (p + r) / 2;
				if (target >= nums[q])
				{
					p = q;
				}
				else // <
				{
					r = q;
				}
			}
			if (nums[p] == target)
			{
				v[1] = p;
			}
		}
		return v;
	}
};