class Solution {
public:
	void sortColors(vector<int>& nums) {
		int a, b, i, l;
		l = nums.size();
		a = 0; b = 0;
		for (i = 0; i<l; i++)
		{
			if (nums[i] == 0)
			{
				a++;
				b++;
			}
			if (nums[i] == 1)
			{
				b++;
			}
		}
		for (i = 0; i<a; i++)
		{
			nums[i] = 0;
		}
		for (i = a; i<b; i++)
		{
			nums[i] = 1;
		}
		for (i = b; i<l; i++)
		{
			nums[i] = 2;
		}
		return;
	}
};