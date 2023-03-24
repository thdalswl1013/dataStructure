#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int row;
	int col;
	int value;
}matrix_n;

matrix_n a[9];


int main(void)
{
	FILE* fp;
	fp = fopen("a.txt", "r");

	fscanf(fp, "%d %d %d\n", &a[0].row, &a[0].col, &a[0].value); // 6 6 8

	for (int i = 1; i < 9; i++) // row col value 값들
		fscanf(fp, "%d %d %d\n", &a[i].row, &a[i].col, &a[i].value);







	printf("A\n");
	
	int arr[6][6];
	int x = 1;


	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			if (i == a[x].row && j == a[x].col)
				arr[i][j] = a[x++].value;
			else	
				arr[i][j] = 0;

			printf("%3d", arr[i][j]);

		}
		printf("\n");
	}



	return 0;
}



/* 4-1
int main(void)
{
	int num;
	printf("원소의 개수를 입력하세요: ");
	scanf("%d", &num);

	printf("Random Generated Matrix\n");

	int arr[20][20];
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arr[i][j] = 0;
			//printf("%3d", arr[i][j]);
		}
		//printf("\n");
	}

	int row;
	int col;

	for (int i = 0; i < num; i++)
	{
		row = rand() % 20;
		col = rand() % 20;

		if (arr[row][col] == 0)
			arr[row][col] = rand() % 100;

		else
			i--;
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}


	printf("\n");
	printf("Sparse matrix\n");
	printf(" 20  20 %3d\n", num);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] != 0)
				printf("%3d %3d %3d\n", i, j, arr[i][j]);
		}
	}

	return 0;
}
*/
