class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int i, l, p;
		vector<int> res;
		p = 1;
		l = nums.size();
		for (i = 0; i<l; i++)
		{
			res.push_back(p);
			p *= nums[i];
		}
		p = 1;
		for (i = l - 1; i >= 0; i--)
		{
			res[i] *= p;
			p *= nums[i];
		}
		return res;
	}
};