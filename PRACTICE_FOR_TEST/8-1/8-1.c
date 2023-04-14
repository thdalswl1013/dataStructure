#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listNode* listPointer; // nodePtr 자기 자신을 가리키는 pointer 를 먼저 선언해준다.
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

void ndelete(listPointer* first, listPointer x, listPointer trace) //trace: 내가 지우려는 애 바로 앞의 값, x: 내가 지우려는 값
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
		fscanf(fp, "%d ", &num); //전체를 순서대로 출력
		insert(&first, x, num);
	}

	int cnt = 0;
	for (listPointer trav = first; trav; trav = trav->link)
	{
		printf("[%p  %2d  %p]  \n", trav, trav->data, trav->link); //현재 trav의 링크값, 현재 trav의 데이터값, 다음 trav의 링크 값
		/*
		cnt+=1;
		if (cnt % 2 == 0)
			printf("\n");
		*/
	}

	//홀수 지우기
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
