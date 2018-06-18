class Solution {
public:
	string longestPalindrome(string s) {
		int i, j, l, p, q, pb, qb;
		pb = 0; qb = 0;
		l = s.length();
		if (l <= 1)
		{
			return s;
		}
		for (i = 1; i<l - 1; i++) //odd
		{
			p = i; q = i;
			while ((p>0) && (q<l - 1) && (s[p - 1] == s[q + 1]))
			{
				p--; q++;
			}
			if (q - p>qb - pb)
			{
				qb = q; pb = p;
			}
		}
		for (i = 1; i<l; i++) //even
		{
			p = i; q = i - 1;
			while ((p>0) && (q<l - 1) && (s[p - 1] == s[q + 1]))
			{
				p--; q++;
			}
			if (q - p>qb - pb)
			{
				qb = q; pb = p;
			}
		}
		return s.substr(pb, qb - pb + 1);
	}
};