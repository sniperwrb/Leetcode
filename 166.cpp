class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long a = numerator;
		long long b = denominator;
		string s = "";
		if (((a<0) && (b>0)) || ((a>0) && (b<0)))
		{
			s += "-";
		}
		a = abs(a); b = abs(b);
		long long c = a / b;
		s += to_string(c);
		a -= (b*c);
		if (a == 0)
		{
			return s;
		}
		s += ".";
		vector<long long> n; //numerators
		n.push_back(a);
		int l = 1; // length of small number
		vector<int> d; // digits
		int f = 0; // 0=not yet, 1=ended, 2=looped
		int i, j;
		while (f == 0)
		{
			a *= 10;
			c = a / b;
			d.push_back(c);
			a -= (b*c);
			if (a == 0)
			{
				f = 1;
				for (j = 0; j < l; j++)
				{
					s += char(d[j] + 48);
				}
				return s;
			}
			for (i = 0; i < l; i++)
			{
				if (a == n[i])
				{
					f = 2;
					for (j = 0; j < i; j++)
					{
						s += char(d[j] + 48);
					}
					s += "(";
					for (j = i; j < l; j++)
					{
						s += char(d[j] + 48);
					}
					s += ")";
					return s;
				}
			}
			n.push_back(a);
			l++;
		}
		return s;
	}
};