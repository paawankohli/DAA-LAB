#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("output.txt", "w", stdout);

	int dp[45];
	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2 ; i < 45 ; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	for(int i = 1 ; i < 45 ; i++)
		cout << dp[i - 1] << " " << dp[i] << endl;
}