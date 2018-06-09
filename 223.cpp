#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int I, J, K, L;
	I = 0; J = 0; K = 0; L = 0;
	if ((B <= F) && (F <= D))
	{
		J = F;
	}
	if ((F <= B) && (B <= H))
	{
		J = B;
	}
	if ((F <= D) && (D <= H))
	{
		L = D;
	}
	if ((B <= H) && (H <= D))
	{
		L = H;
	}
	if ((A <= E) && (E <= C))
	{
		I = E;
	}
	if ((E <= A) && (A <= G))
	{
		I = A;
	}
	if ((E <= C) && (C <= G))
	{
		K = C;
	}
	if ((A <= G) && (G <= C))
	{
		K = G;
	}
	return ((C - A)*(D - B) - (K - I)*(L - J) + (G - E)*(H - F));
}
int main()
{
	//int b[] = { 1,2 };
	//vector<int> a(b, b + sizeof(b) / sizeof(int));
	//string a = "LeEtCoDe";
	int a[] = { -3,0,3,4,0,-1,9,2 };
	int c;
	c = computeArea(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
	cout << c;
	cin >> c;
	return 0;
}