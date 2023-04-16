#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int row;
	int col;
	int value;
}sMatrix;
sMatrix a[9];
sMatrix b[9];

void fastTranspose(sMatrix a[], sMatrix b[])
{
	int rowTerms[100];
	int startingPos[100];

	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	//rowTerms 계산
	for (int i = 0; i < a[0].col; i++)
	{
		rowTerms[i] = 0;
	}

	for (int i = 1; i <= a[0].value; i++)
	{
		rowTerms[a[i].col]++;
	}

	// startingPos 계산
	startingPos[0] = 1;
	for (int i = 1; i < a[0].col; i++)
	{
		startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
	}

	/*
	printf("   rowTerms: ");
	for (int i = 0; i < a[0].col; i++)
	{
		printf("%3d", rowTerms[i]);
	}

	printf("\nstartingPos: ");
	for (int i = 0; i < a[0].col; i++)
	{
		printf("%3d", startingPos[i]);
	}
	*/

	// a(i,j) -> b(j,i)
	int j;
	for (int i = 1; i <= a[0].value; i++)
	{
		j = startingPos[a[i].col]++;
		b[j].row = a[i].col;
		b[j].col = a[i].row;
		b[j].value = a[i].value;
	}
}



int main(void)
{

	FILE* fp;
	fp = fopen("a.txt", "r");

	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d\n", &a[i].row, &a[i].col, &a[i].value);
		//printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
		i++;
	}
	
	printf("A\n");

	int arr[6][6];

	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (int i = 1; i < a[0].value; i++)
	{
		arr[a[i].row][a[i].col] = a[i].value;
	}


	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			printf("%4d ", arr[i][j]);
		}
		printf("\n");
	}


	printf("\n");
	printf("B\n");
	int arr2[6][6];

	fastTranspose(a, b);

	for (int i = 0; i < b[0].row; i++)
	{
		for (int j = 0; j < b[0].col; j++)
		{
			arr2[i][j] = 0;
		}
	}

	for (int i = 1; i < b[0].value; i++)
	{
		arr2[b[i].row][b[i].col] = b[i].value;
	}


	for (int i = 0; i < b[0].row; i++)
	{
		for (int j = 0; j < b[0].col; j++)
		{
			printf("%4d ", arr2[i][j]);
		}
		printf("\n");
	}

	return 0;
}