class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> vs;
		int l = digits.size();
		if (l == 0)
		{
			return vs;
		}
		vector<int> v(l + 1, 0);
		string s(l, 32);
		int i;
		for (i = 0; i<l; i++)
		{
			s[i] = digits[i] * 3 - 53 + (digits[i] >= 56);
			if ((digits[i] <= 49) || (digits[i] >= 58))
			{
				return vs;
			}
		}
		while (v[l] == 0)
		{
			vs.push_back(s);
			v[0]++;
			s[0] = s[0] + 1;
			i = 0;
			while (v[i] >= 3 + ((digits[i] == 55) || (digits[i] == 57)))
			{
				v[i] = 0;
				s[i] = digits[i] * 3 - 53 + (digits[i] >= 56);
				i++;
				v[i]++;
				s[i] = s[i] + 1;
			}
		}
		return vs;
	}
};