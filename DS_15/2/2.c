#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RUN 8
#define RUN_NUM 10

int winnerTree[RUN * 2] = { 0, };
int sorted[RUN * RUN_NUM] = { 0, };
int arr[RUN][RUN_NUM] = { 0, };
int indexarr[RUN] = { 0, };


int findwinner();
int init_winnerTree();
void sort_winnerTree(int i, int index);
void levelorder();

int main()
{
	FILE* fp;
	fp=fopen("input.txt", "r");

	printf("<<<<<<<< run data >>>>>>>>\n\n");

	for (int i = 0; i < RUN; i++) 
	{
		printf("%d-th run: \n", (i + 1));
		for (int j = 0; j < RUN_NUM; j++) 
		{
			fscanf(fp, "%d", &arr[i][j]);
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}

	init_winnerTree();
	int index = 0;

	for (int i = 0; i < RUN * RUN_NUM; i++)
	{
		sort_winnerTree(i, index);
		if (i == 0)
		{
			printf("\nLevel-order traversal for initial min-winner tree\n");
			levelorder();

			printf("\nsorting with min-winner tree...");
			printf("\n\nsorted result");
		}

		if (i % 8 == 0)
			printf("\n");
		printf("%4d", sorted[i]);
	}

	printf("\n");
	return 0;
}


int findwinner()
{
	int left, right;

	for (int i = RUN / 2; i >= 1;) 
	{
		left = winnerTree[i * 2];
		right = winnerTree[i * 2 + 1];

		winnerTree[i] = (left > right) ? right : left;

		if (++i % 4 == 0)
			i /= 4;
		else if (i == 2)
			break;
	}

	winnerTree[0] = winnerTree[1];

	for (int i = 0; i < RUN; i++)
	{
		if (winnerTree[0] == winnerTree[RUN + i])
			return RUN + i;
	}
}

int init_winnerTree()
{
	for (int i = 0; i < RUN; i++) 
	{
		indexarr[i] = 0;
		winnerTree[i + RUN] = arr[i][0];
	}
}


void levelorder()
{
	for (int i = 1; i < RUN * 2; i++) 
		printf("%3d", winnerTree[i]);
	printf("\n");
}

void sort_winnerTree(int i, int index)
{
	index = findwinner();
	sorted[i] = winnerTree[index];
	winnerTree[index] = arr[index - RUN][++indexarr[index - RUN]];

	if (indexarr[index - RUN] == RUN_NUM)
		winnerTree[index] = 9999;
}
