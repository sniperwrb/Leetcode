#include <iostream>
#include <string>
using namespace std;
string convert(string s, int numRows) {
	string x;
	x = s;
	int h, i, l, p, f;
	l = s.length();
	p = -1;
	if (numRows == 1)
	{
		return s;
	}
	for (i = 0; i < l; i += (2 * numRows - 2))
	{
		p++;
		x[p] = s[i];
	}
	for (h = 1; h < (numRows - 1); h++)
	{
		f = 1;
		for (i = h; i < l;)
		{
			p++;
			x[p] = s[i];
			i = i + numRows - 1;
			i = i + (numRows - 1 - h * 2) * f;
			f = f * (-1);
		}
	}
	for (i = numRows - 1; i < l; i += (2 * numRows - 2))
	{
		p++;
		x[p] = s[i];
	}
	return x;
}
int main()
{
	string s;
	int n;
	s = "AB";
	n = 2;
	string t;
	t = convert(s, n);
	cout << t;
	cin >> n;
}