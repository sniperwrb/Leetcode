class Solution {
public:
	int calculate(string s) {
		int i, l, n, x, y, o;
		l = s.length();
		n = 0; //the current number
		x = 0; //the sum
		y = 1; //the product
		o = 1; //the operator, 1=+,2=-,3=*,4=/
		for (i = 0; i<l; i++)
		{
			if ((s[i] >= '0') && (s[i] <= '9'))
			{
				n *= 10;
				n += (s[i] - '0');
			}
			else if ((s[i] == '+') || (s[i] == '-'))
			{
				if (o == 1)
				{
					x += n;
				}
				else if (o == 2)
				{
					x -= n;
				}
				else if (o == 3)
				{
					y *= n;
					x += y;
					y = 1;
				}
				else if (o == 4)
				{
					y /= n;
					x += y;
					y = 1;
				}
				n = 0;
				if (s[i] == '+')
				{
					o = 1;
				}
				else
				{
					o = 2;
				}
			}
			else if ((s[i] == '*') || (s[i] == '/'))
			{
				if (o == 1)
				{
					y = n;
				}
				else if (o == 2)
				{
					y = -n;
				}
				else if (o == 3)
				{
					y *= n;
				}
				else if (o == 4)
				{
					y /= n;
				}
				n = 0;
				if (s[i] == '*')
				{
					o = 3;
				}
				else
				{
					o = 4;
				}
			}
		}
		if (o == 1)
		{
			x += n;
		}
		else if (o == 2)
		{
			x -= n;
		}
		else if (o == 3)
		{
			y *= n;
			x += y;
		}
		else if (o == 4)
		{
			y /= n;
			x += y;
			y = 1;
		}
		return x;
	}
};