#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200

typedef struct 
{
	int key;
}element;
element heap[MAX_ELEMENTS];

int n = 0;

void push(element item, int* n);
element pop(int* n);

int main()
{
	FILE* fp;
	int num = 0;
	element temp;

	fp=fopen("input.txt", "r");
	printf("***** insertion into a min heap *****\n");

	while (!feof(fp))
	{
		fscanf(fp, "%d", &num);
		temp.key = num;

		push(temp, &n);

		for (int i = 1; i <= n; i++)
			printf("%3d", heap[i].key);
		printf("\n");
	}

	printf("***** deletion into a min heap *****");
	while (n != 0) 
	{
		temp = pop(&n);

		printf("\ndelete data = %d\n", temp.key);

		for (int i = 1; i <= n; i++) 
			printf("%3d", heap[i].key);

	}
}

void push(element item, int* n)
{
	int i;
	if ((*n) == MAX_ELEMENTS - 1)
	{
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	i = ++(*n);

	while ((i != 1) && (item.key < heap[i / 2].key))
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

element pop(int* n)
{
	int parent, child;
	element item, temp;
	if (!(*n))
	{
		fprintf(stderr, "The heap is empty\n");
		exit(1);
	}

	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n)
	{
		if ((child < *n) && (heap[child].key > heap[child + 1].key))
			child++;
		if (temp.key <= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
