#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listNode* listPointer; // nodePtr �ڱ� �ڽ��� ����Ű�� pointer �� ���� �������ش�.
struct listNode
{
	int data;
	listPointer link;
}listNode;

listPointer first = NULL;
listPointer x;

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

void ndelete(listPointer* first, listPointer x, listPointer trace) //trace: ���� ������� �� �ٷ� ���� ��, x: ���� ������� ��
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

	printf("1st\n");
	int num;
	while (!feof(fp))
	{
		fscanf(fp, "%d ", &num); //��ü�� ������� ���
		insert(&first, x, num);
	}

	int cnt = 0;
	for (listPointer trav = first; trav; trav = trav->link)
	{
		printf("[%p  %2d  %p]  \n", trav, trav->data, trav->link); //���� trav�� ��ũ��, ���� trav�� �����Ͱ�, ���� trav�� ��ũ ��
		/*
		cnt+=1;
		if (cnt % 2 == 0)
			printf("\n");
		*/
	}

	//Ȧ�� �����
	printf("\n\n");
	printf("2nd\n");

	listPointer trace = NULL;
	for (listPointer trav = first; trav; trav->link)
	{
		if (trav->data % 2==1)
		{
			if(trav==first)
				ndelete(&first, trav, trace);
		}

		trace = trav;
	}

	for (listPointer trav = first; trav; trav = trav->link)
	{
		printf("[%p  %2d  %p]  \n", trav, trav->data, trav->link);
	}


	return 0;
}
