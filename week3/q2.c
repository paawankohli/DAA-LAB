#include <stdio.h>
#include <string.h>

int isPresent(char str[], char sub[])
{
	int m = strlen(str);
	int n = strlen(sub);

	printf("m: %d n: %d\n", m, n);
	int opcount = 0, flag;

	for (int i = 0 ; i < m - n + 1 ; i++)
	{
		int j;
		flag = 0;

		for (j = 0 ; j < n ; j++)
		{
			opcount++;

			if (str[i + j] != sub[j])
				break;
		}

		if (j == n)
		{
			flag = 1;
			break;
		}
	}

	printf("opcount: %d \n", opcount);
	return flag;;
}

int main()
{
	char str[1000];
	char sub[1000];

	printf("Enter string: ");
	scanf("%s", str);

	printf("Enter substring: ");
	scanf("%s", sub);

	int b = isPresent(str, sub);

	if (b == 1)
		printf("Found\n");
	else
		printf("Not Found\n");

}