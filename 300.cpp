class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		vector<int> v;
		int i, j, l, p, q, r, t;
		l = 1;
		v.push_back(nums[0]);
		for (i = 1; i<n; i++)
		{
			p = -1;
			r = l;
			while (r - p>1)
			{
				q = (p + r) / 2;
				if (v[q]<nums[i])
				{
					p = q;
				}
				else
				{
					r = q;
				}
			}
			q = p + 1;
			if (q >= l)
			{
				v.push_back(nums[i]);
				l++;
			}
			else
			{
				v[q] = nums[i];
			}
		}
		return l;
	}
};