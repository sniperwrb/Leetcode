#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

vector<string> generateParenthesis(int n) {
	vector<string> vs;
	string s = "";
	vector<int> v;
	int i;
	for (i = 1; i <= n; i++)
	{
		v.push_back(i);
		s += "(";
	}
	for (i = 1; i <= n; i++)
	{
		s += ")";
	}
	bool f = (n>0);
	while (f)
	{
		vs.push_back(s);
		i = n - 1;
		s[v[i]-1] = ')';
		v[i]++;
		while ((i>0) && (v[i] > 2 * i + 1))
		{
			i--;
			s[v[i]-1] = ')';
			v[i]++;
		}
		s[v[i]-1] = '(';
		if (i <= 0)
		{
			f = false;
			return vs;
		}
		for (i++; i<n; i++)
		{
			v[i] = v[i - 1] + 1;
			s[v[i]-1] = '(';
		}
	}
	return vs;
}

int main()
{
	int a;
	cin >> a;
	vector<string> vs;
	vs = generateParenthesis(a);
	cout << vs.size();
	cin >> a;
	return 0;
}