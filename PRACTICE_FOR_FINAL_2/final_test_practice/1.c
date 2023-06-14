#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int key;
	char item[10];
	int empty;
}element;
element ht[11];

int hasing(char input[]);
int Hashadd(element temp, element* ht);

int main(void)
{
	element temp;

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("input string:");

	while (!feof(fp))
	{
		fscanf(fp, "%s", &temp.item);
		Hashadd(temp, ht);
		printf(" %s", temp.item);
	}
	printf("\n");
	for (int i = 0; i < 11; i++)
	{
		if (ht[i].empty == 0)
			printf("ht[%d]:\n", i);
		else
			printf("ht[%d]: %s %d\n", i, ht[i].item, ht[i].key);
	}

	return 0;
}

int hasing(char input[])
{
	int num = 0;
	while (*input)
	{
		num += *input;
		input++;
	}
	return num;
}

int Hashadd(element temp, element* ht)
{
	int i, value;
	i = value = hasing(temp.item) % 11;
	
	while (ht[i].empty == 1)
		i = (i + 1) % 11;

	temp.key = hasing(temp.item);
	temp.empty = 1;
	
	ht[i] = temp;
	
	
	return 1;
}