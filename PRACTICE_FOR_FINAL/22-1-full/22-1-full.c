// Linear Probing - 해시테이블 출력 & search까지

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct element
{
	int key;
	char item[10];
	int empty;
}element;
element hash_table[11];

unsigned int stringToint(char* key);
int HashAdd(element item, element* ht);
int HashSearch(element item, element* ht);

int main(void)
{
	element item;

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("input strings: ");
	while (!feof(fp))
	{
		fscanf(fp, "%s", &item.item);
		HashAdd(item, hash_table);
		printf("%s  ", item.item);
	}
	printf("\n\n");


	printf("             item      key\n");
	for (int i = 0; i < 11; i++)
	{
		if (hash_table[i].empty == 0)
			printf("ht[%2d] : %8s\n", i, hash_table[i].item);
		else
			printf("ht[%2d] : %8s %8d\n", i, hash_table[i].item, hash_table[i].key);
	}

	char InputToSearch[10];
	printf("String to Search >>");
	scanf("%s", &InputToSearch);

	strcpy(item.item, InputToSearch);
	HashSearch(item, hash_table);


	return 0;
}

unsigned int stringToint(char* key)
{
	int number = 0;
	while (*key)
		number += *key++;

	return number;
}

int HashAdd(element item, element* ht)
{
	int i, value;
	value = i = stringToint(item.item) % 11;

	while (ht[i].empty == 1)
	{
		i = (i + 1) % 11;
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
	value = i = stringToint(item.item) % 11;

	while (!(ht[i].empty == -1))
	{
		cnt++;

		if (strcmp(item.item, ht[i].item) == 0)
		{
			printf("item : %s, key : %d, the number of comparisions : %d\n", ht[i].item, ht[i].key, cnt);
			return 1;
		}

		i = (i + 1) % 11;

		if (i == value)
		{
			printf("doesn't exist!\n");
			return 1;
		}
	}

	printf("doesn't exist!\n");
	return 1;
}
