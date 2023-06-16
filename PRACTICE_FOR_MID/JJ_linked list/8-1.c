#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode* listPointer;
struct listNode
{
	int data;
	listPointer link;
} listNode;
listPointer first = NULL;
listPointer x;
// 자리를 지정해주는 함수 
void find(listPointer first, listPointer *x, int data) //x가 다음에 들어올 값이 어디에 들어가야하는지 알려주는 역할
{
	listPointer trav;
	trav = first;

	if (first == NULL)
	{
		*x = NULL;
	}

	else
	{
		for (; trav; trav = trav->link)
		{
			if (data > trav->data)
			{
				*x = trav;
			}
			else
			{
				if (trav == first)
				{
					*x = NULL;
				}
				break;

			}
		}
	}
}

void insert(listPointer *first, listPointer x, int data)
{
	listPointer temp;
	temp = malloc(sizeof(*temp));
	temp->data = data;

	if (x== NULL)
	{
		temp->link = *first;
		*first = temp;
	}

	else
	{
		temp->link = x->link;
		x->link = temp;
	}
}


void ndelete(listPointer* first, listPointer x, listPointer trace) //trace: 내가 지우려는 값(x)의 바로 앞의 값
{
	if (trace == NULL)
	{
		*first = (*first)->link;
	}
	else
	{
		trace->link = x->link;
	}
	free(x);
}

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");
	/*
	int arr[12];
	for (int i = 0; i < 2; i++)
	{
		fscanf(fp, "%d %d %d %d %d %d", &arr[0 + 6 * i], &arr[1 + 6 * i], &arr[2 + 6 * i], &arr[3 + 6 * i], &arr[4 + 6 * i], &arr[5 + 6 * i]);
		printf("%d %d %d %d %d %d\n", arr[0 + 6 * i], arr[1 + 6 * i], arr[2 + 6 * i], arr[3 + 6 * i], arr[4 + 6 * i], arr[5 + 6 * i]);
	}
	*/
	int data;



	while (!feof(fp))
	{
		fscanf(fp, "%d", &data);
		find(first, &x, data);
		insert(&first, x, data);
		
	}
	

	printf("The ordered list containts: \n");

	for (listPointer trav = first; trav; trav = trav->link)
	{
		printf("(%10p, %4d, %10p) \n", trav, trav->data, trav->link);
	}
	listPointer trace = NULL;

	for (listPointer trav = first; trav;trav = trav->link)
	{
		if (trav->data % 2)
		{
			if (trav == first)
			{
				ndelete(&first, trav, trace);

			}
		}
		trace = trav;
	}
	printf("-----------------------------------\n");
	for (listPointer trav = first; trav; trav = trav->link)
	{
		printf("(%10p, %4d, %10p) \n", trav, trav->data, trav->link);
	}
	
	return 0;
}

