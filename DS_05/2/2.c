#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_SIZE 30
#define MAX_QUEUE_SIZE 3


typedef struct
{
	int id; // unique id
	char name[MAX_QUEUE_SIZE]; // last name
}element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;


int main(void)
{
	char* word = NULL;
	char input[80];

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("<< Circular queue operations where MAX_STACK_SIZE is 3 >>\n");

	printf("\n*************************************************\n\n");

	/*
	add id name // queue�� ������ ����, ť�� full�̸� full �޽����� ����ϰ�, ť ���� �����͸� �̵��ؾ� �� ��� ��data shift���޼����� ����ؾ� ��.
	delete // queue�� ������ ����, empty�� �� �����͸� �����ϸ� Queue empty �޽����� ����ϰ� ������.
	qprint // queue�� ������ ����Ʈ
	quit // ���α׷� ���� ����
	�߸��� ��ɾ� // �޽��� ������ ���
	*/
	for (int i = 0; i < 17; i++)
	{
		//char *fgets (char *string, int n, FILE *stream);
		fgets(input, sizeof(input), fp);
		word = strtok(input, " \n");

		if (!strcmp(word, "add"))
		{
			rear++;
			if (rear >= MAX_QUEUE_SIZE)
			{
				printf("queue is full, not added\n");
				for (int i = 0; i <rear; i++)
				{
					printf("%d %s\n", queue[i].id, queue[i].name);
				}
				break;
			}
			sscanf(input + strlen(word) + 1, "%d%s", &(queue + rear)->id, &(queue + rear)->name);
		}

		else if (!strcmp(word, "delete"))
		{
			if (front == rear)
				printf("queue is empty, cannot delete element.\n");
			rear--;
		}

		else if (!strcmp(word, "sprint"))
		{
			for (int i = 0; i <=rear; i++)
			{
				printf("%d %s\n", queue[i].id, queue[i].name);
			}
			printf("\n");
		}

		else if (!strcmp(word, "quit"))
		{
			break;
		}

		else
		{
			printf("wrong command! try again!\n\n");
		}
	}
	fclose(fp);



	return 0;
}

/*
element queueEmpty(queue)
{
	fprintf(stderr, "queue is empty, cannot delete element.\n");
	exit(EXIT_FAILURE);

}

void addq(element item)
{
	if (rear == MAX_QUEUE_SIZE - 1)
		queueFull();
	queue[++rear] = item;
}

element deleteq()
{
	if (front == rear)
		return queueEmpty();
	return queue[++front];
}
*/
