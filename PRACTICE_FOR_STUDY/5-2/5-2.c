#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 3

typedef struct
{
	int id;
	char name[80];
}element;

element queue[MAX_QUEUE_SIZE];

int front = -1;
int rear = -1;

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("<< Circular queue operations where MAX_QUEUE_SIZE is 3 >>\n");
	printf("add 1 Jung\ndelete\n");
	printf("\n*************************************************\n\n");

	char input[80];
	char* word = NULL;

	while (1)
	{
		fgets(input, sizeof(input), fp);
		word = strtok(input, " \n");

		if (strcmp(word, "add") == 0)
		{
			rear++;

			if (rear == MAX_QUEUE_SIZE)
			{
				if (rear - front == 4)
				{
					printf("queue if full, not added\n");
					rear--;
				}

				else
				{
					printf("data shift\n");
					int shift = rear - front - 1;

					if (shift == 2)
					{
						(queue + rear - 3)->id = (queue + rear - 2)->id;
						strcpy((queue + rear - 3)->name, (queue + rear - 2)->name);
						(queue + rear - 2)->id = (queue + rear - 1)->id;
						strcpy((queue + rear - 2)->name, (queue + rear - 1)->name);
						front = -1;
						rear = shift;
					}

					if (shift == 1)
					{

						(queue + rear - 3)->id = (queue + rear - 1)->id;
						strcpy((queue + rear - 3)->name, (queue + rear - 1)->name);
						front = -1;
						front = -1;
						rear = shift;
					}

					sscanf(input+strlen(word)+1, "%d %s", &(queue+rear)->id, &(queue+rear)->name);
				}
			}
			else
			{
				sscanf(input + strlen(word) + 1, "%d%s", &(queue + rear)->id, &(queue + rear)->name);
			}

		}

		else if (strcmp(word, "delete") == 0)
		{
			if (rear == front)
			{
				printf("queue is empty\n");
				break;
			}

			front++;
		}

		else if (strcmp(word, "qprint") == 0)
		{
			for (int i = front + 1; i < rear + 1; i++)
			{
				printf("%d %s\n", queue[i].id, queue[i].name);
			}
		}

		else if (strcmp(word, "quit") == 0) // 프로그램 수행 종료. 잘못된 명령어 
			break;

		else // 메시지 오류를 출력
			printf("wrong command Try it again\n\n");

	}



	fclose(fp);
	return 0;
}