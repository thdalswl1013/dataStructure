#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	printf("원소의 개수를 쓰세요: ");
	scanf("%d", &num);

	int i, j;

	int arr[20][20];
	printf("Random genereated matrix(20, 20)\n");
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			arr[i][j] = 0;
		}
	}

	int row, col;
	for (int k = 0; k < num; k++)
	{
		row = rand() % 20;
		col = rand() % 20;

		if (arr[row][col] == 0)
			arr[row][col] = rand() % 100;
		else
			k--;
	}

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}


	printf("\nSparsse matrix\n");
	printf("20, 20, %2d\n", num);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] != 0)
				printf("%2d, %2d, %2d\n", i, j, arr[i][j]);
		}
	}
	return 0;
}