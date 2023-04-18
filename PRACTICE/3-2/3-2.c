#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** make2dArray(int rows, int cols)
{
	int** arr;
	arr = malloc(sizeof(int) * rows);

	for (int i = 0; i < rows; i++)
	{
		arr[i] = malloc(sizeof(int) * cols);
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
	
	return arr;

}


int main(void)
{
	int**ipp;
	int i, j, rows, cols;
	printf("일차원 배열의 수를 입력하세요: ");
	scanf("%d %d", &rows, &cols);

	ipp = make2dArray(rows, cols);


	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("ipp[%d][%d] = %d ", i, j, ipp[i][j]);

			if (j % 5 == 4)
				printf("\n");
		}

	}

	return 0;
}