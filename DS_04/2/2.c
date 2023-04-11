#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC(p, s) \
		if(!(p=malloc(s))){ \
		fprintf(stderr, "insufficient memory"); \
		exit(EXIT_FAILURE);	}

#define MAX_TERMS 101
#define MAX_COL 10

typedef struct
{
	int row;
	int col;
	int value;
}matrixstructure;


void fastTranspose(matrixstructure a[], matrixstructure b[])
{
	int rowTerms[MAX_COL];
	int startingPos[MAX_COL];
	startingPos[0] = 1;

	int numCols = a[0].col;
	int numTerms = a[0].value;

	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	int i, j;

	if (numTerms > 0)
	{
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;

		for (i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++;


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

	matrixstructure a[100];
	matrixstructure b[100];

	FILE* fp;
	FILE* fp2;
	fp = fopen("a.txt", "r");
	fp2 = fopen("b.txt", "w");

	fscanf(fp, "%d %d %d\n", &a[0].row, &a[0].col, &a[0].value);

	for (int i = 1; i < 9; i++)
	{
		fscanf(fp, "%d %d %d\n", &a[i].row, &a[i].col, &a[i].value);
	}

	printf("A\n");

	fastTranspose(a, b);

	int x = 1;
	int a_ar=0;

	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			if (i == a[x].row && j == a[x].col)
				a_ar = a[x++].value;
			else
				a_ar = 0;
			printf("%4d", a_ar);
		}
		printf("\n");
	}

	for (int i = 0; i <= a[0].value; i++)
	{
		fprintf(fp2, "%3d %3d %3d\n",b[i].row, b[i].col, b[i].value);
	}


	printf("B\n");
	x = 1;
	int b_ar = 0;

	for (int i = 0; i < b[0].row; i++)
	{
		for (int j = 0; j < b[0].col; j++)
		{
			if (i == b[x].row && j == b[x].col)
				b_ar = b[x++].value;
			else
				b_ar = 0;
			printf("%4d", b_ar);
		}
		printf("\n");
	}

	return 0;
}