#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int l = s.length();
	if (l <= 1)
	{
		return l;
	}
	int i, j, m, p, b, a;
	m = 0; p = 0; a = 127;
	vector<int> v(a, -1);
	for (i = 0; i<l; i++)
	{
		if (v[s[i]] < 0)
		{
			v[s[i]] = i;
			if (i - p + 1>m)
			{
				m = i - p + 1;
			}
		}
		else // have duplicates
		{
			p = v[s[i]] + 1;
			for (j = 0; j<a; j++)
			{
				if (v[j]<p)
				{
					v[j] = -1;
				}
			}
			v[s[i]] = i;
		}
	}
	return m;
}

int main()
{
	string s = "abcabccdecde";
	int a = lengthOfLongestSubstring(s);
	cout << a;
	cin >> a;
	return 0;
}