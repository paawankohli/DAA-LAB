#include<bits/stdc++.h>
using namespace std;

int ks(int val[], int wt[], int n, int maxW)
{
	if(n == 0 || maxW == 0)
		return 0;

	if(wt[n - 1] > maxW)
		return ks(val, wt, n - 1, maxW);
	else
	{
		int n1 = val[n - 1] +  ks(val, wt, n - 1, maxW - wt[n - 1]);
		int n2 = ks(val, wt, n - 1, maxW);

		return max(n1, n2);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int val[n];
	int wt[n];

	for (int i = 0 ; i < n ; i++)
		cin >> val[i];

	for (int i = 0 ; i < n ; i++)
		cin >> wt[i];

	int maxW;
	cin >> maxW;

	cout << ks(val, wt, n, maxW);
}