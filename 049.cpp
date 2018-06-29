class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<int>> v;
		vector<vector<string>> x;
		vector<int> h(26, 0);
		vector<string> vs;
		int i, j, ls, l, lv, k;
		l = strs.size();
		lv = 0;
		for (i = 0; i<l; i++)
		{
			for (j = 0; j<26; j++)
			{
				h[j] = 0;
			}
			ls = strs[i].size();
			for (j = 0; j<ls; j++)
			{
				h[strs[i][j] - 'a']++;
			}
			k = 0;
			while ((k<lv) && (h != v[k]))
			{
				k++;
			}
			if (k >= lv)
			{
				v.push_back(h);
				x.push_back(vs);
				lv++;
			}
			x[k].push_back(strs[i]);
		}
		return x;
	}
};