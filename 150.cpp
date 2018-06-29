#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int evalRPN(vector<string>& tokens) {
	int l, i, lv;
	vector<int> x;
	l = tokens.size();
	lv = 0;
	for (i = 0; i<l; i++)
	{
		if (tokens[i][0] == '+')
		{
			x[lv - 2] += x[lv - 1];
			x.pop_back();
			lv--;
		}
		else if ((tokens[i][0] == '-')&&(tokens[i].length()==1))
		{
			x[lv - 2] -= x[lv - 1];
			x.pop_back();
			lv--;
		}
		else if (tokens[i][0] == '*')
		{
			x[lv - 2] *= x[lv - 1];
			x.pop_back();
			lv--;
		}
		else if (tokens[i][0] == '/')
		{
			x[lv - 2] /= x[lv - 1];
			x.pop_back();
			lv--;
		}
		else
		{
			x.push_back(stoi(tokens[i]));
			lv++;
		}
	}
	return x[0];
}

int main()
{
	vector<string> a = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	int b;
	b = evalRPN(a);
	cout << b;
	cin >> b;
	return 0;
}