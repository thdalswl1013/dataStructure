
//fastTranspose를 이용하여 전치행렬 구현하기 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_COL 10

typedef struct
{
	int row;
	int col;
	int value;
}matrix_element;

void fastTranspose(matrix_element a[], matrix_element b[])
{
	int rowTerms[MAX_COL];
	int startingPos[MAX_COL];
	startingPos[0] = 1;

	// 제일 첫 줄
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	//두번째 줄부터
	if (a[0].value > 0)
	{

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
		for (int i = 1; i < a[0].col; i++)
		{
			startingPos[i] = startingPos[i - 1] + rowTerms[i-1];
		}

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

int main(void)
{
	FILE* fp;
	fp = fopen("a.txt", "r");

	matrix_element a[9];
	matrix_element b[9];

	for (int i=0;i<9;i++)
	{
		fscanf(fp, "%4d %4d %4d\n", &a[i].row, &a[i].col, &a[i].value);
		//printf("%4d %4d %4d\n", a[i].row, a[i].col, a[i].value);
	}

	printf("<< A >> \n");
	int arr_A[6][6];
	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			arr_A[i][j] = 0;
		}
	}

	for (int i = 1; i < 9; i++)
	{
		arr_A[a[i].row][a[i].col] = a[i].value;
	}

	for (int i = 0; i < a[0].row; i++)
	{
		for (int j = 0; j < a[0].col; j++)
		{
			printf("%4d", arr_A[i][j]);
		}
		printf("\n");
	}

	FILE* fp2;
	fp2 = fopen("b.txt", "w");

	printf("\n<< B >> \n");

	fastTranspose(a, b);

	for (int k = 0; k < 9; k++)
	{
		fprintf(fp2, "%d %d %d \n", b[k].row, b[k].col, b[k].value); // fprintf할 때는 & 사용하지 말 것
		//printf("%d %d %d \n", b[k].row, b[k].col, b[k].value);
	}

	int	arr_B[6][6];
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			arr_B[i][j] = 0;
		}
	}

	for (int i = 1; i < 9; i++)
	{
		arr_B[b[i].row][b[i].col] = b[i].value;
	}

	for (int i = 0; i < b[0].row; i++)
	{
		for (int j = 0; j < b[0].col; j++)
		{
			printf("%4d", arr_B[i][j]);
		}
		printf("\n");
	}
	return 0;
}

