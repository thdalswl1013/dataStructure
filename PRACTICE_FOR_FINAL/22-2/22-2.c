// Random Probing

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct element
{
	int key;
	int empty;
}element;
element hash_table[11];


int main(void)
{
	element hashTable;

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("Key sequence from file: ");
	while (!feof(fp))
	{
		fscanf(fp, "%d", &hashTable.key);
		printf("%d ", hashTable.key);
	}

	int seed;
	printf("\ninput seed >> ");
	scanf("%d", &seed);

	srand(seed); // 매 탐색마다 동일한 seed를 사용해야 함

	int randNum[8]; // 1~(b-1) 범위의 난수를 한 번씩 생성해야 함
	for (int i = 0; i < 8; i++)
	{
		randNum[i] = rand() % 7 + 1;

		for (int j = 1; j < i; j++)
		{
			if (randNum[i] == randNum[j])
				i--;
		}
	}

	for (int i = 1; i < 8; i++)
		printf("randNum[%d] : %d\n", i, randNum[i]);
	printf("\n\n");

	return 0;
}