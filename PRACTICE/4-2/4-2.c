#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int row;
	int col;
	int value;
}matrixA;

void fastTranspose(matrixA a[], matrixA b[]);


int main(void)
{
	matrixA a[10];
	matrixA b[10];

	FILE* fp;
	fp = fopen("a.txt", "r");

	FILE* fp2;
	fp2 = fopen("b.txt", "w");
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d\n", &a[i].row, &a[i].col, &a[i].value);
		printf("%4d %4d %4d\n", a[i].row, a[i].col, a[i].value);
		i++;
	}

	int ax = 0;
	printf("\nA\n");

	int x = 1;
	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			if (a[x].row == i && a[x].col == j)
			{
				ax = a[x].value;
				x++;
			}
			else
			{
				ax = 0;
			}
			printf("%4d ", ax);
		}

		printf("\n");
	}

	fastTranspose(a, b);
	
	printf("\nB\n");
	int bx = 0;
	x = 1;
	for (int i = 0; i < b[0].row; i++)
	{
		for (int j = 0; j < b[0].col; j++)
		{
			if (b[x].row == i && b[x].col == j)
			{
				bx = b[x].value;
				x++;
			}
			else
			{
				bx = 0;
			}
			printf("%4d ", bx);
		}

		printf("\n");
	}



	for (int i = 0; i <= b[0].value; i++)
		fprintf(fp2, "%4d %4d %4d\n", b[i].row, b[i].col, b[i].value);

	return 0;
}


// 희소행렬 전치 행렬
void fastTranspose(matrixA a[], matrixA b[])
{
	int rowTerms[10];
	int startingPos[10];
	startingPos[0] = 1;

	// 제일 첫 줄
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	//두번째 줄부터
	if (a[0].value > 0)
	{
		for (int i = 0; i < a[0].col; i++)
			rowTerms[i] = 0;

		for (int i = 1; i <= a[0].value; i++)
			rowTerms[a[i].col]++;

		for (int i = 1; i < a[0].col; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

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
}
