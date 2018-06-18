class Solution {
public:
	int numDecodings(string s) {
		int a, b, c, i, l;
		a = 1; b = 1;
		l = s.length();
		for (i = 0; i<l; i++)
		{
			c = 0;
			if (s[i] != '0')
			{
				c += b;
			}
			if ((i>0) && ((s[i - 1] == '1') || ((s[i - 1] == '2') && (s[i] <= '6'))))
			{
				c += a;
			}
			a = b; b = c;
		}
		return c;
	}
};