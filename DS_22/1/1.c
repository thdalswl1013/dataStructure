#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 10
#define TABLE_SIZE 11

typedef struct element 
{
	int key;
	char item[MAX_STRING_SIZE];
	int empty;
}element;

element hash_table[TABLE_SIZE];

unsigned int stringToint(char* key)
{
	int number = 0;
	while (*key)
		number += *key++;

	return number;
}

int makeHash(char* key)
{
	return stringToint(key) % TABLE_SIZE;
}

int HashAdd(element item, element* ht)
{
	int i, value;
	value = i = makeHash(item.item);

	while (ht[i].empty == 1) 
	{
		i = (i + 1) % TABLE_SIZE; 
	}

	item.key = stringToint(item.item);
	item.empty = 1;
	ht[i] = item;

	return 1;
}

int HashSearch(element item, element* ht)
{
	int i, value;
	int cnt = 0;
	value = i = makeHash(item.item);

	while (!(ht[i].empty == -1))
	{
		cnt++;

		if (strcmp(item.item, ht[i].item) == 0)
		{
			printf("item : %s, key : %d, the number of comparisions : %d\n", ht[i].item, ht[i].key, cnt);
			return 1;
		}

		i = (i + 1) % TABLE_SIZE;

		if (i == value)
		{
			printf("it doesn't exist!\n");
			return 1;
		}
	}

	printf("it doesn't exist!\n");
	return 1;
}

void HashTablePrint()
{
	printf("             item      key\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hash_table[i].empty == 0)
			printf("ht[%2d] : %8s\n", i, hash_table[i].item);
		else
			printf("ht[%2d] : %8s %8d\n", i, hash_table[i].item, hash_table[i].key);
	}
}

int main()
{
	element item;
	char search[MAX_STRING_SIZE];

	FILE* fp;
	fp=fopen("input.txt", "r");

	printf(" input strings : ");

	while (!feof(fp))
	{
		fscanf(fp, "%s", &item.item);
		HashAdd(item, hash_table);
		printf("%s ", item.item);
	}
	printf("\n\n");

	HashTablePrint();

	printf("\nstring to search >> ");
	scanf("%s", &search);
	strcpy(item.item, search);

	HashSearch(item, hash_table);
}