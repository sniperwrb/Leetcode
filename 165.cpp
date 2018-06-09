#include <iostream>
//#include <vector>
#include <string>
//#include <algorithm>
using namespace std;
int compareVersion(string version1, string version2) {
	int l1, l2, p1, p2, q1, q2, a1, a2;
	string s1, s2;
	l1 = version1.length();
	l2 = version2.length();
	p1 = 0;
	p2 = 0;
	q1 = version1.find('.');
	q2 = version2.find('.');
	if (q1 == -1)
	{
		q1 = l1;
	}
	if (q2 == -1)
	{
		q2 = l2;
	}
	s1 = version1.substr(p1, q1 - p1);
	s2 = version2.substr(p2, q2 - p2);
	a1 = s1.length() > 0 ? stoi(s1) : 0;
	a2 = s2.length() > 0 ? stoi(s2) : 0;
	while ((q1 < l1) || (q2 < l2))
	{
		if (a1 < a2)
		{
			return -1;
		}
		if (a1 > a2)
		{
			return 1;
		}
		p1 = q1 == l1 ? l1 : q1 + 1;
		p2 = q2 == l2 ? l2 : q2 + 1;
		q1 = version1.find('.', p1);
		q2 = version2.find('.', p2);
		if (q1 == -1)
		{
			q1 = l1;
		}
		if (q2 == -1)
		{
			q2 = l2;
		}
		s1 = p1 >= l1 ? "" : version1.substr(p1, q1 - p1);
		s2 = p2 >= l2 ? "" : version2.substr(p2, q2 - p2);
		a1 = s1.length() > 0 ? stoi(s1) : 0;
		a2 = s2.length() > 0 ? stoi(s2) : 0;
	}
	if (a1 < a2)
	{
		return -1;
	}
	if (a1 > a2)
	{
		return 1;
	}
	if (a1 == a2)
	{
		return 0;
	}
}
int main()
{
	string s="1";
	string t="0";
	int a;
	a = compareVersion(s, t);
	cout << a;
	cin >> a;
	return 0;
}