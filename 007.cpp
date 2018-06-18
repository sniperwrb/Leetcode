#include <iostream>
#include <cmath>
using namespace std;
int reverse(int x) {
	long long dick;
	int f, xx;
	if (x < 0)
	{
		f = -1;
		xx = -x;
	}
	else
	{
		f = 1;
		xx = x;
	}
	dick = 0;
	while (xx > 0)
	{
		dick *= 10;
		dick += (xx % 10);
		xx = xx / 10;
	}
	dick *= f;
	if ((dick > INT_MAX) || (dick < INT_MIN))
	{
		dick = 0;
	}
	return dick;
}
int main()
{
	int x, y;
	double z;
	x = 1000400003;
	y = reverse(x);
	//cout << y;
	z = 6.4;
	x = z;
	cout << x;
	cin >> x;
	return 0;
}