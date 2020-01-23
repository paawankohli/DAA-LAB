#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int size)
{
	int opcount = 0;



	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - 1 - i; j++)
		{
			opcount++;

			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}

	printf("%d   %d \n", size, opcount);
}

int main()
{
	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[50];

	for (int i = 0 ; i >= 50 ; i++)
		arr[i] = i;

	for (int test = 3 ; test < 50 ; test += 3 )
		bubbleSort(arr, test);
}