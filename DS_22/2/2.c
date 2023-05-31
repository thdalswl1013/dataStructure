#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 8

typedef struct 
{
	int key;
	int empty;
}element;

element hash_table[TABLE_SIZE];
int randNum[TABLE_SIZE];

void printRandnum(int seed)
{
	printf("\n");

	for (int i = 1; i < TABLE_SIZE; i++)
	{
		randNum[i] = rand() % (TABLE_SIZE - 1) + 1;
		for (int j = 1; j < i; j++)
		{
			if (randNum[i] == randNum[j])
				i--;
		}
	}

	for (int i = 1; i < TABLE_SIZE; i++)
		printf("randNum[%d] : %d\n", i, randNum[i]);
}

int makeHash(int key)
{
	return key % TABLE_SIZE;
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

void HashTablePrint()
{
	printf("           key\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hash_table[i].empty == 0)
			printf("ht[%2d] :\n", i);
		else
			printf("ht[%2d] : %5d\n", i, hash_table[i].key);
	}
}

int HashSearch(element item, element* ht)
{
	int i, value;
	int cnt = 0;
	value = i = makeHash(item.key);

	while (!(ht[i].empty == -1))
	{
		cnt++;

		if (ht[i].key == item.key)
		{
			printf("key : %d, the number of comparisions : %d\n", ht[i].key, cnt);
			return 1;
		}

		i = makeHash(value + randNum[cnt]);

		if (i == value)
		{
			printf("it doesn't exist!\n");
			return 1;
		}
	}

	printf("it doesn't exist!\n");
	return 1;
}

int main()
{
	int seed;
	int size = 0;
	int input[TABLE_SIZE];
	element item;
	int search;

	FILE* fp;
	fp=fopen("input.txt", "r");

	printf("key sequence from file :");
	while (!feof(fp)) 
	{
		fscanf(fp, "%d", &input[size]);
		printf("%5d", input[size++]);
	}

	printf("\ninput seed >> ");
	scanf("%d", &seed);

	srand(seed);

	printRandnum(seed);
	printf("\n\n");

	for (int i = 0; i < size; i++)
	{
		item.key = input[i];
		HashAdd(item, hash_table);
	}

	HashTablePrint();

	while (1) 
	{
		printf("\ninput 0 to quit\n");
		printf("key to search >> ");
		scanf("%d", &search);

		if (search == 0)
			break;

		item.key = search;
		HashSearch(item, hash_table);
	}
}