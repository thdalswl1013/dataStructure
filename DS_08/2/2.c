#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct listNode
{
	int data;
	struct listNode* link;
} listNode;

struct listNode* first = NULL;
struct listNode* last = NULL;

void insert(struct listNode** first, struct listNode* x, int i);
void delete(struct listNode** first, struct listNode** trail, struct listNode* x);
void printList(struct listNode* first);

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int	input[12];
	for (int i = 0; i < 2; i++)
	{
		fscanf(fp, "%d %d %d %d %d %d", &input[0 + 6 * i], &input[1 + 6 * i], &input[2 + 6 * i], &input[3 + 6 * i], &input[4 + 6 * i], &input[5 + 6 * i]);
		//printf("%d %d %d %d %d %d\n", input[0 + 6 * i], input[1 + 6 * i], input[2 + 6 * i], input[3 + 6 * i], input[4 + 6 * i], input[5 + 6 * i]);
	}

	int temp;
	for (int i = 0; i < 12; i++) // 7 19 20 30 30 30 50 55 77 80 87 90 순으로 정렬
	{
		for (int j = 0; j < 11; j++)
		{
			if (input[j] > input[j + 1])
			{
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}

	printf("The ordered list contains: \n");

	insert(&first, &last, input[0]); // 처음이랑 마지막 연결
	last = first;

	for (int i = 11; i > 0; i--) // 사이사이 삽입
	{
		insert(&first, &last, input[i]);
	}

	printList(first);
	printf("\n");

	printf("\nAfter deleting nodes with odd value \n"); // 성적이 홀수인 노드 삭제 
	printf("\nThe ordered list contains: \n");


	struct listNode* cur;
	struct listNode* ffirst;
	struct listNode* temp2;
	cur = first;
	ffirst = NULL;

	while (cur != NULL)
	{
		if (cur->data % 2 == 1)
		{
			temp2 = cur->link;
			delete(&first, &ffirst, cur);
			cur = temp2;
		}
		else
		{
			if (ffirst == NULL)
			{
				cur = cur->link;
				ffirst = first;
			}
			else
			{
				cur = cur->link;
				ffirst = ffirst->link;
			}

		}
	}

	printList(first);

	return 0;
}

void insert(struct listNode** first, struct listNode** x, int i)
{
	struct listNode* temp;
	temp = (struct listNode*)malloc(sizeof(*temp));
	temp->data = i;

	if (*first) 
	{
		temp->link = (*x)->link;
		(*x)->link = temp;
	}

	else 
	{
		temp->link = NULL;
		*first = temp;
	}
}

void delete(struct listNode** first, struct listNode** trail, struct listNode* x)
{
	if (*trail)
		(*trail)->link = x->link;

	else
		*first = (*first)->link;

	free(x);
}

void printList(struct listNode* first)
{
	int i = 0;

	printf("The list contains: ");

	for (; first; first = first->link)
	{
		if (i % 3 == 0)
			printf("\n");

		printf("(%.10o %4d %.11o) ", first, first->data, first->link);
		i += 1;
	}
}
