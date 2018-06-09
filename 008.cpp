#include <iostream>
#include <string>
using namespace std;
int myAtoi(string str) {
	long long dick;
	int l, i, f, c, q;
	dick = 0;
	f = 1;
	l = str.length();
	i = 0;
	c = 32;
	q = 0;
	while ((i < l) && (c == 32))
	{
		c = str[i];
		i++;
	}
	if ((i < l) && ((c == 43) || (c == 45)))
	{
		f = 44 - c;
		c = str[i];
		i++;
	}
	while ((q < 10) && (i < l) && (c >= 48) && (c <= 57))
	{
		dick *= 10;
		dick += (c - 48);
		c = str[i];
		i++;
		q++;
	}
	if ((c >= 48) && (c <= 57))
	{
		dick *= 10;
		dick += (c - 48);
	}
	dick *= f;
	if (dick > INT_MAX)
	{
		dick = INT_MAX;
	}
	if (dick < INT_MIN)
	{
		dick = INT_MIN;
	}
	return dick;
}
int main()
{
	string s;
	int x;
	s = "1922337203";
	x = myAtoi(s);
	cout << x;
	cin >> x;
	return 0;
}