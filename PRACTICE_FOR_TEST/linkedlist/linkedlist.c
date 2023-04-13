#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode
{
	int data;
	listPointer link;
};

listPointer first = NULL;
listPointer x;

void find(listPointer first, listPointer* x, int data); //x가 다음에 들어올 값이 어디에 들어가야하는지 알려주는 역할
void insert(listPointer* first, listPointer x, int data);
void ndelete(listPointer* first, listPointer x, listPointer trace); //trace: 내가 지우려는 값(x)의 바로 앞의 값



int main(void)
{






	return 0;
}

void find(listPointer first, listPointer* x, int data)
{
	listPointer trav;
	trav = first;

	if (first = NULL)
		*x = NULL;
	else
	{
		for (; trav; trav = trav->link)
		{
			if (data > trav->data)
				*x = trav;
			else
			{
				if (trav == first)
					*x = NULL;

				break;
			}
		}
	}

}

void insert(listPointer* first, listPointer x, int data)
{
	listPointer temp;
	temp = malloc(sizeof(*temp));
	temp->data = data;

	if (x == NULL)
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

void deleteNode(listPointer* first, listPointer x, listPointer trace)
{
	if (trace == NULL)
		*first = (*first)->link;
	else
		trace->link = x->link;

	free(x);
}