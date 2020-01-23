#include <stdio.h>

void swap(int &x, int &y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}

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

	printf("opcount: %d\n", opcount);
}

int main()
{
	int size;

	printf("Enter size of array: ");
	scanf("%d", &size);

	int arr[size];

	printf("Enter elements of array: ");
	
	for (int i = 0 ; i < size ; i++)
		scanf("%d", &arr[i]);

	bubbleSort(arr, size);

	printf("Sorted array: ");

	for (int i = 0 ; i < size ; i++)
		printf("%d ", arr[i]);

	printf("\n");
}