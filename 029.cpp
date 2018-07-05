class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0)
		{
			return 0;
		}
		if (dividend == -2147483648)
		{
			if (divisor == -1)
			{
				return 2147483647;
			}
			else if (divisor == 1)
			{
				return -2147483648;
			}
			else if (divisor == 2)
			{
				return -1073741824;
			}
			else if (divisor == dividend)
			{
				return 1;
			}
		}
		if (divisor == -2147483648)
		{
			return 0;
		}
		int f = 1;
		if ((dividend<0) ^ (divisor<0))
		{
			f = -1;
		}
		if (dividend == -2147483648)
		{
			dividend = -1073741824;
			f = divisor<0 ? 2 : -2;
		}
		double a = log(abs(dividend)) - log(abs(divisor));
		int b = (exp(a)*f);
		return b;
	}
};