#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nodePointer;
typedef struct node
{
	char item[10];   
	int key;
	nodePointer link;
};

nodePointer ht[9];
void insert(nodePointer temp);
int hasing(char input[]);

int main(void)
{
	FILE* f;
	fopen_s(&f, "input.txt", "r");
	char input[10];
	nodePointer temp;
	while (!feof(f))
	{
		temp = (nodePointer)malloc(sizeof(*temp));
		fscanf(f, " %s", temp->item);
		temp->key = hasing(temp->item);
		insert(temp);
	}
	printf("<<<<<<<< Hasing Table>>>>>>>>>>>>\n");

	printf("              item   key");
	for (int i = 0; i < 9; i++)
	{
		printf("\nht[ %d] : ", i);
		for (nodePointer ptr = ht[i]; ptr; ptr = ptr->link)
			printf(" (%s %d) ", ptr->item, ptr->key);
	}

	while (strcmp(input, "Q"))
	{
		printf("\ninput \"Q\" to quit\nstring to search >>");
		scanf("%s", input);
		if (!strcmp(input, "Q")) break;
		int count = 1;

		for (nodePointer ptr = ht[(hasing(input) % 9)]; ; ptr = ptr->link)
		{
			if (!strcmp(ptr->item, input))
				break;
			else
				count++;
		}
		printf("\nitem: %s, key: %d, the number of compare: %d\n", input, hasing(input), count);
	}

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

void insert(nodePointer temp)
{
	nodePointer ptr;
	int k = (temp->key) % 9;
	if (ht[k])
	{
		temp->link = NULL;
		for (ptr = ht[k]; ptr->link; ptr = ptr->link);
		ptr->link = temp;
	}
	else
	{
		temp->link = NULL;
		ht[k] = temp;
	}
}