#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int row;
	int col;
	int value;
}matrix_element;

int main(void)
{
	FILE* fp;
	fp = fopen("a.txt", "r");

	matrix_element a[9];

	for (int i=0;i<9;i++)
	{
		fscanf(fp, "%4d %4d %4d\n", &a[i].row, &a[i].col, &a[i].value);
		//printf("%4d %4d %4d\n", a[i].row, a[i].col, a[i].value);
	}

	printf("<< A >> \n");
	int arr[6][6];
	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (int i = 1; i < 9; i++)
	{
		arr[a[i].row][a[i].col] = a[i].value;
	}

	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}


	printf("\n<< B >> \n");

	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			printf("%4d", arr[j][i]);
		}
		printf("\n");
	}

	FILE* fp2;
	fp2 = fopen("b.txt", "w");

	fprintf(fp2, "   6    6    8\n");


	for (int i = 0; i < a[0].col; i++)
	{
		for (int j = 0; j < a[0].row; j++)
		{
			if (arr[j][i] != 0)
			{
				//printf("%4d %4d %4d\n", i, j, arr[j][i]);
				fprintf(fp2, "%4d %4d %4d\n", i, j, arr[j][i]);
			}

			
		}
	}
	return 0;
}

