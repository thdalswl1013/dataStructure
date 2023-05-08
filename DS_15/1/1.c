#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* winnerTree;
int* sorted;
int key, seed;
int winner;

int findwinner(int k);
void inorder(int i, int k);

int main()
{

	printf("<<<<< sorting with winner tree >>>>>\n\n");
	printf("the number of keys(4, 8, 16 or 32 as a power of 2) >> ");
	scanf("%d", &key);

	winnerTree = calloc(key * 2, sizeof(int));
	sorted = calloc(key, sizeof(int));

	printf("value of seed >> ");
	scanf("%d", &seed);

	for (int i = 0; i < key; i++)
	{
		winnerTree[i + key] = rand() % 500 + 1;
		printf("%5d", winnerTree[i + key]);
	}

	printf("\n\n");
	printf("initialization of min-winner tree\n\n");
	winner = findwinner(key);

	printf("inorder traversal for min-winner tree\n");
	inorder(1, key);

	sorted[0] = winnerTree[winner];
	winnerTree[winner] = 9999;

	for (int i = 1; i < key; i++) 
	{
		winner = findwinner(key);
		sorted[i] = winnerTree[winner];
		winnerTree[winner] = 9999;

		if (i == 1) 
		{
			printf("\nWinner Tree inorder traversal after find 2 winner\n");
			inorder(1, key);
		}
	}

	printf("\n\n");
	printf("Sorting with min-winner tree...\n\n");
	printf("sorted result\n");
	
	for (int i = 0; i < key; i++) 
		printf("%5d", sorted[i]);

	return 0;
}


int findwinner(int k)
{
	int left, right;

	for (int i = k / 2; i >= 1;) 
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

	for (int i = 0; i < k; i++) 
	{
		if (winnerTree[0] == winnerTree[k + i])
			return k + i;
	}
}

void inorder(int i, int k)
{
	if (i < k * 2)
	{
		inorder(i * 2, k);
		printf("%5d", winnerTree[i]);
		inorder(i * 2 + 1, k);
	}
}
