class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		int n, l, f, t, i;
		n = nums.size();
		l = n * 2 + 1;
		t = 1;
		while (t == 1)
		{
			f = rand()*(RAND_MAX + 1) + rand(); // filler
			t = 0;
			for (i = 0; i<n; i++)
			{
				if (nums[i] == f)
				{
					t = 1;
				}
			}
		}
		vector<int> v(l, f);
		vector<int> c(l, 0); // count
		for (i = 0; i<n; i++)
		{
			t = (nums[i] % l + l) % l;
			while ((v[t] != f) && (v[t] != nums[i]))
			{
				t = (t + 1) % l;
			}
			if (v[t] == nums[i])
			{
				c[t]++;
			}
			else
			{
				v[t] = nums[i];
				c[t] = 1;
			}
		}
		vector<int> c1(c);
		sort(c1.begin(), c1.end());
		t = c1[l - k];
		vector<int> x;
		for (i = 0; i<l; i++)
		{
			if (c[i] >= t)
			{
				x.push_back(v[i]);
			}
		}
		return x;
	}
};