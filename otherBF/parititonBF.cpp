#include<bits/stdc++.h>
using namespace std;

bool setExists(int arr[], int n, int target)
{
	if(target == 0 && n >= 0)
		return true;

	if(n == 0)
		return false;

	if(target < 0)
		return false;

	bool b1 = setExists(arr, n - 1, target - arr[n - 1]);
	bool b2 = setExists(arr, n - 1, target);

	return (b1 || b2);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int arr[n];
	int sum = 0;

	for(int i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
		sum = sum + arr[i];
	}

	if (sum % 2 == 1)
		cout << "false";
	else
		if( setExists(arr, n, sum/2) )
			cout << "true";
		else
			cout << "false";
}