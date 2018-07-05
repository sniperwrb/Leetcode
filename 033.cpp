class Solution {
public:
	int search(vector<int>& nums, int target) {
		// find the rotated point
		int l = nums.size();
		if (l == 0)
		{
			return -1;
		}
		if (l == 1)
		{
			return (target == nums[0] ? 0 : -1);
		}
		int p, q, r;
		p = 0; r = l - 1;
		while (r - p>1)
		{
			q = (p + r) / 2;
			if (nums[q]>nums[p]) // right
			{
				p = q;
			}
			else
			{
				r = q;
			}
		}
		// record r: it is the new zero
		int z = r;
		p = 0; r = l - 1;
		if (target == nums[(p + z) % l])
		{
			return (p + z) % l;
		}
		if (target == nums[(r + z) % l])
		{
			return (r + z) % l;
		}
		while (r - p>1)
		{
			q = (p + r) / 2;
			if (target == nums[(q + z) % l])
			{
				return (q + z) % l;
			}
			if (target>nums[(q + z) % l])
			{
				p = q;
			}
			else
			{
				r = q;
			}
		}
		return -1;
	}
};