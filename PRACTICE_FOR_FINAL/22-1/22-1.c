// Linear Probing - 해시테이블 출력까지만 

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
element ht[11];

unsigned int stringToint(char* key);
int HashAdd(element item, element* ht);

int main(void)
{
	element item;

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("input strings: ");
	while (!feof(fp))
	{
		fscanf(fp, "%s", &item.item);		
		HashAdd(item, ht);
		printf("%s  ", item.item);
	}
	printf("\n\n");


	printf("             item      key\n");
	for (int i = 0; i < 11; i++)
	{
		if (ht[i].empty == 0)
			printf("ht[%2d] : %8s\n", i, ht[i].item);
		else
			printf("ht[%2d] : %8s %8d\n", i, ht[i].item, ht[i].key);
	}


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