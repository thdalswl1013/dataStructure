#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int row;
	int col;
	int value;
}matrix_abc;

void fastTranspose(matrix_abc a[], matrix_abc b[])
{
	int rowTerms[100];
	int startingPos[100];
	int i, j;
	int numCols = a[0].col, numTerms = a[0].value;

	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0)
	{
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;

		for (i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++;

		startingPos[0] = 1;

		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

		for (i = 1; i <= numTerms; i++)
		{
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

int main(void)
{
	FILE* fp;
	fp = fopen("a.txt", "r");
	
	FILE* fp2;
	fp2 = fopen("b.txt", "w");

	matrix_abc a[100];
	matrix_abc b[100];
	fscanf(fp, "%d %d %d\n", &a[0].row, &a[0].col, &a[0].value);

	for (int i = 1; i < 9; i++)
	{
		fscanf(fp, "%d %d %d\n", &a[i].row, &a[i].col, &a[i].value);
		printf("%3d %3d %3d\n", a[i].row, a[i].col, a[i].value);
	}printf("\n");

	fastTranspose(a, b);

	for (int i = 1; i < 9; i++)
	{
		printf("%3d %3d %3d\n", b[i].row, b[i].col, b[i].value);
	}printf("\n");


	printf("\n  << A >>\n");

	int x = 1;
	int r = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == a[x].row && j == a[x].col)
				r = a[x++].value;
			else
				r = 0;
			printf("%4d", r);
			
		}
		printf("\n");
	}

	printf(" \n << B >>\n");

	x = 1;
	r = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == b[x].row && j == b[x].col)
				r = b[x++].value;
			else
				r = 0;
			printf("%4d", r);
		}
		printf("\n");
	}

	//fprint

	for (int i = 0; i < 9; i++)
	{
		fprintf(fp2, "%3d %3d %3d\n", b[i].row, b[i].col, b[i].value);
	}



	return 0;
}