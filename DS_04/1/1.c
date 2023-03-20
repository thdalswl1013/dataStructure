#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC(p, s) \
		if(!(p=malloc(s))){ \
		fprintf(stderr, "insufficient memory"); \
		exit(EXIT_FAILURE);	}

int main(void)
{
	int num;
	int arr[20][20];

	printf("원소의 개수를 쓰세요: ");
	scanf("%d", &num);

	printf("Ramdon Genetrated Matrix(20, 20)\n");

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

	srand(time(NULL));

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

	printf("\nsparce matrix\n");
	printf(" 20,   20%3d\n", num);


	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] != 0)
				printf("%3d, %3d %3d\n", i, j, arr[i][j]);
		}
		
	}
	return 0;
}