#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 24
#define FALSE 0
#define TRUE 1

#define MAX_STACK_SIZE 10
#define MAX_NAME_SIZE 20

#define MALLOC(p,s)\
	if (!((p)=malloc(s))){\
	fprintf(stderr,"Insufficient memory");\
	exit(EXIT_FAILURE);\
	}

typedef struct node* nodePointer;
typedef struct node 
{
	int data;
	nodePointer link;
};

typedef int element;
element stack[MAX_STACK_SIZE];
int top;

void printList(nodePointer first);
element pop();
void stackFull();
element stackEmpty();
void push(element);

int main(void)
{
	short int out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	nodePointer x, y;

	int i, j, n;

	FILE* fp;
	fp = fopen("input.txt", "r");
 
	fscanf(fp, "%d", &n);

	printf("/* MAX_SIZE of a set S : %d */ \n", MAX_SIZE);
	printf("current size of S : %d \n", n);

	for (i = 0; i < n; i++)
	{
		out[i] = FALSE;
		seq[i] = NULL;
	}

	printf("S = { ");
	for (i = 0; i < n; i++)
	{
		printf("%d, ", i);
	}
	printf("}\n");

	fscanf(fp, "%d%d", &i, &j);
	printf("input pairs: ");

	while (!feof(fp))
	{
		printf("%dR%d ", i, j);
		MALLOC(x, sizeof(*x));

		x->data = j;
		x->link = seq[i];
		seq[i] = x;
		MALLOC(x, sizeof(*x));
		x->data = i;
		x->link = seq[j];
		seq[j] = x;
		fscanf_s(fp, "%d%d", &i, &j);
	}
	printf("\n");
	printf("\nSymmetric 관계 linked List\n");

	for (int i = 0; i < n; i++)
	{
		printf("%d : Symmetric 관계:\n", i);
		printList(seq[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (out[i] == FALSE)
		{
			printf("\n New Class: %5d", i);
			out[i] = TRUE;
			x = seq[i];
			top = -1;
			for (;;)
			{
				while (x)
				{
					j = x->data;
					if (out[j] == FALSE)
					{
						printf("%5d", j);
						out[j] = TRUE;
						push(j);
						x = x->link;
					}
					else
					{
						x = x->link;
					}
				}
				if (top == -1)
					break;
				x = seq[pop()];
			}
		}
	}

	printf("\n");
	fclose(fp);

	return 0;
}

void printList(nodePointer first)
{

	for (; first; first = first->link)
	{
		printf("(%p %d %p) ", first, first->data, first->link);
	}

	printf("\n");
}

void stackFull()
{
	element item;
	fprintf(stderr, "stack is full, cannot add element\n");

	printf("current stack elements : \n");
	while (top > -1)
	{
		item = pop();
		printf("%d\n", item);
	}

	exit(EXIT_FAILURE);
}
element pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

element stackEmpty()
{
	element item;
	item = -1;  // error key value
	return item;
}

void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}
