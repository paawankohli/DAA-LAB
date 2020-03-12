int knapsack(int* w, int* v, int n, int B)
{
	int i, temp;
	int maxVal = 0, maxSequence = 0;
	int totalWeight, totalValue;
	int opcount = 0;
	int index = 0;

	for (i = 0 ; i < pow(2, n) ; i++)
	{
		temp = i;
		totalWeight = totalValue = 0;

		index = 0;

		while (temp)
		{
			if (temp & 0x1)
			{
				totalWeight = totalWeight + w[index];
				totalValue = totalValue + v[index];
			}

			index++;
			temp = temp >> 1;
		}

		if (totalWeight <= B && totalValue > maxVal)
		{
			maxVal = totalValue;
			maxSequence = i;
		}
	}

	return maxSequence;

}

int main()
{
	// inputs

	knaps = Knapsack();

	i = 0;

	while (knaps)
	{
		if (knaps & 0x1)
			printf("item %d\n, value: %d", i + 1, v[i]);

		i++;
		knaps = knaps >> 1;
	}
}