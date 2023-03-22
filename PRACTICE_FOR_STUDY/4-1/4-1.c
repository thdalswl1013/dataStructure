#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	int arr[20][20];

	printf("원소의 개수를 쓰시오 : ");
	scanf("%d", &num);

	printf("Random Generated Matrix(20,20)\n");

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arr[i][j] = 0;
		}
	}
	
	srand(time(NULL));

	for (int i = 0; i < num; i++)
	{
		int row = rand() % 20;
		int col = rand() % 20;


		if (arr[row][col] == 0)
			arr[row][col] = rand() % 100;
		else
			i--;
	}

	printf("\n");

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("sparce matrix\n");

	printf(" 20, 20, %2d\n", num);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] != 0)
			{
				printf("%3d,%3d,%3d\n", i, j, arr[i][j]);
			}
		}
	}

	return 0;
}