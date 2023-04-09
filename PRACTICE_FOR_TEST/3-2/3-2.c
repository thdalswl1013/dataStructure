#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int** ipp;
	int row, col;

	printf("이차원 배열을 입력하세요: ");
	scanf("%d %d", &row, &col);

	ipp = malloc(sizeof(int) * row);

	for (int i = 0; i < row; i++)
	{
		ipp[i] = malloc(sizeof(int) * col);
		for (int j = 0; j < col; j++)
		{
			ipp[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("ipp[%d][%d] = %2d  ", i, j, ipp[i][j]);

			if (j == 4)
				printf("\n");
		}
	}


	return 0;
}