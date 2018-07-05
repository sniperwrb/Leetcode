class Solution {
public:
	double myPow(double x, int n) {
		long long nn;
		if ((x == 0) && (n <= 0))
		{
			return 0;
		}
		if (n == 0)
		{
			return 1;
		}
		nn = n;
		if (nn<0)
		{
			nn = -nn;
			x = 1 / x;
		}
		//dec to bin
		vector<int> b;
		vector<double> d;
		int l = 0;
		while (nn>0)
		{
			b.push_back(nn % 2);
			d.push_back(x);
			nn /= 2;
			x *= x;
			l++;
		}
		double y = 1;
		int i;
		for (i = 0; i<l; i++)
		{
			if (b[i]>0)
			{
				y *= d[i];
			}
		}
		return y;
	}
};