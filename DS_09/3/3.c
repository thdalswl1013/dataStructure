#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}


typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;
listPointer first = NULL;

void printList(listPointer first);
void insert(listPointer* first, int data);
void delete(listPointer* first, listPointer trail, listPointer x);

int main(void)
{
	int data;
	listPointer x, trail, cur, ffirst;

	FILE* f;
	fopen_s(&f, "input.txt", "r");

	if (f == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(f, "%d", &data);

	x = NULL;

	while (!feof(f))
	{
		insert(&first, data);
		fscanf_s(f, "%d", &data);
	}

	printList(first->link);

	if (first)
		cur = first->link;
	else
	{
		printf("include no data\n");
		exit(0);
	}

	ffirst = trail = first;

	while (cur != NULL)
	{
		if (cur->data % 2) {
			x = cur;
			cur = cur->link;

			delete(&first, trail, x);

			if (ffirst != first) {
				break;
			}
		}
		else
		{
			trail = cur;
			cur = cur->link;
		}
		if (trail == first)
			break;
	}

	printf("\nAfter deleting nodes with odd value \n\n");
	printList(first->link);

	fclose(f);

	return 0;
}

void printList(listPointer first)
{
	int count;
	listPointer temp;
	temp = first;

	printf("The Circularly Linked List contains: \n");

	for (count = 1; first; count++)
	{
		printf("(%p, %4d, %p )%s", first, first->data, first->link, count % 3 ? "" : "\n");
		first = first->link;
		if (temp == first)
			break;
	}
	printf("\n");
}

void insert(listPointer* first, int data)
{
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;

	if (!(*first))
	{
		*first = temp;
		temp->link = temp;
	}

	else
	{
		temp->link = (*first)->link;
		(*first)->link = temp;
		*first = temp;
	}
}

void delete(listPointer* first, listPointer trail, listPointer x)
{
	if (*first == x)
		*first = trail;
	trail->link = x->link;
	free(x);
}
