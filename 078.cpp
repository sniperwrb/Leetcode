class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int l = nums.size();
		vector<vector<int>> x;
		vector<int> v;
		vector<int> d;
		int i;
		for (i = 0; i <= l; i++)
		{
			d.push_back(0);
		}
		while (d[l] == 0)
		{
			v.clear();
			for (i = 0; i<l; i++)
			{
				if (d[i] == 1)
				{
					v.push_back(nums[i]);
				}
			}
			x.push_back(v);
			d[0]++;
			i = 0;
			while (d[i] >= 2)
			{
				d[i] -= 2;
				i++;
				d[i]++;
			}
		}
		return x;
	}
};