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
int randNum[8]; // 1~(b-1) 범위의 난수를 한 번씩 생성해야 함

int makeHash(int key)
{
	return key % 8;
}

int HashAdd(element item, element* ht)
{
	int cnt = 1;
	int i, value;
	value = i = makeHash(item.key);

	while (ht[i].empty == 1)
		i = makeHash(value + randNum[cnt++]);

	item.empty = 1;
	ht[i] = item;

	return 1;
}
int main(void)
{
	element hashTable;
	element item;

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("Key sequence from file: ");

	int input[8];
	int size = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d", &input[size]);
		printf("%d ", input[size++]);
	}

	int seed;
	printf("\ninput seed >> ");
	scanf("%d", &seed);

	srand(seed); // 매 탐색마다 동일한 seed를 사용해야 함

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

	for (int i = 0; i < 8; i++)
	{
		item.key = input[i];
		HashAdd(item, hash_table);
	}
	printf("             key\n");

	for (int i = 0; i < 8; i++)
	{
		if (hash_table[i].empty == 0)
			printf("ht[%2d] :\n", i);
		else
			printf("ht[%2d] : %5d\n", i, hash_table[i].key);
	}
	return 0;
}