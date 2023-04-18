#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef struct
{
	int id;
	char name[10];
}element;
element queue[MAX_QUEUE_SIZE];

int rear, front;

int isFull()
{
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}


int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	char* word = NULL;
	char input[80];

	while (1)
	{
		fgets(input, sizeof(input), fp);
		word = strtok(input, " \n");

		if (!strcmp(word, "add"))
		{
			if (isFull())
				printf("queue full\n");

			else
			{
				rear++;
				rear = rear % MAX_QUEUE_SIZE;
				sscanf(input + strlen(word) + 1, "%d%s", &(queue + rear)->id, (queue + rear)->name);
			}
		}

		else if (!strcmp(word, "delete"))
		{
			if (rear == front)
			{
				printf("queue is empty\n");
				break;
			}
			front = (front + 1) % MAX_QUEUE_SIZE;
		}

		else if (!strcmp(word, "qprint"))
		{
			for (int i = front; i != rear; )
			{
				i = (i + 1) % MAX_QUEUE_SIZE;
				printf("%d, %s\n", queue[i].id, queue[i].name);
			}
		}

		else if (!strcmp(word, "quit"))
		{
			break;
		}

		else
		{
			printf("wrong command! try again!\n");
		}
	}

	fclose(fp);
	return 0;
}