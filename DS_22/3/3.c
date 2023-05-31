#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING_SIZE 10
#define TABLE_SIZE 11

typedef struct element* ePointer;
typedef struct element 
{
	int key;
	char string[MAX_STRING_SIZE];
	ePointer link;
}element;
ePointer hash_table[TABLE_SIZE];

unsigned int stringToInt(char* key) //ori
{
	int number = 0;
	while (*key) 
		number += *key++;

	return number;
}

int makeHash(char* key)
{
	return stringToInt(key) % TABLE_SIZE;
}

void hash_add(char* item)
{
	int key = stringToInt(item);
	int value = makeHash(item);

	ePointer temp;
	ePointer cur;
	cur = hash_table[value];

	temp = malloc(sizeof(*temp));
	strcpy(temp->string, item);
	temp->key = key;
	temp->link = NULL;

	if (!hash_table[value])
		hash_table[value] = temp;

	else 
	{
		while (cur->link != NULL) 
			cur = cur->link;

		cur->link = temp;
	}
}

void searchHash(char* item)
{
	int value = makeHash(item);
	int cnt = 0;

	ePointer temp;
	temp = hash_table[value];

	while (1) 
	{
		cnt++;
		if (!temp)
			printf("it doesn't exist!\n");
		
		else 
		{
			if (stringToInt(item) == temp->key) 
			{
				printf("item %s, key : %d, the number of comparisions : %d\n", item, temp->key, cnt);
				break;
			}
			else
				temp = temp->link;
		}
	}
}

void printHash()
{
	ePointer temp;
	printf("\n\n          item  key\n");

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		temp = hash_table[i];
		printf("ht[%2d] : ", i);
		if (temp != NULL)
		{
			for (; temp; temp = temp->link)
				printf(" (%s %3d) ", temp->string, temp->key);

		}
		printf("\n");
	}
}

int main()
{
	char item[MAX_STRING_SIZE];
	FILE* fp;
	fp=fopen("input.txt", "r");

	printf("input strings : ");
	while (!feof(fp))
	{
		fscanf(fp, "%s", item);
		printf("%s ", item);
		hash_add(item);
	}

	printHash();

	while (1) 
	{
		printf("\ninput \"quit\" to quit\n");
		printf("string to search >> ");
		scanf("%s", item);
		if (strcmp(item, "quit") == 0)
			break;
		else
			searchHash(item);
	}
}