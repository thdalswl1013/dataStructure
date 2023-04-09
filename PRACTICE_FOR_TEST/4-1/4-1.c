#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	int arr[20][20];

	printf("원소의 개수를 입력하세요: ");
	scanf("%d", &num);
	
	printf("\nRandom generated Matrix(20, 20)\n");

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arr[i][j] = 0;
		}
	}


	for (int i = 0; i < num; i++)
	{
		int row = rand() % 20;
		int col = rand() % 20;

		if (arr[row][col] == 0)
			arr[row][col] = rand() % 100;
		else
			i--;
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			printf(" %2d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("Sparce matrix\n");
	printf("  20,   20,   %d\n", num);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] != 0)
			{
				printf("  %2d,   %2d,  %2d\n", i, j, arr[i][j]);
			}
		}
	}

	return 0;
}
