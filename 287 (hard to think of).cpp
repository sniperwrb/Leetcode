class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int p, q;
		p = nums[0]; q = nums[p];
		while (p != q)
		{
			p = nums[p];
			q = nums[nums[q]];
		}
		q = 0;
		while (q != p)
		{
			q = nums[q];
			p = nums[p];
		}
		return p;
	}
};