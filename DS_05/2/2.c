#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 20
#define MAX_QUEUE_SIZE 3


typedef struct 
{
	int id;
	char name[MAX_NAME_SIZE];
}element;


int main(void)
{
	element queue[MAX_QUEUE_SIZE];
	char* word = NULL;
	char input[80];

	int rear = -1;
	int front = -1;

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("<< Circular queue operations where MAX_QUEUE_SIZE is 3 >>\n");
	printf("add 1 Jung\ndelete\n");
	printf("\n*************************************************\n\n");

	/*
	add id name // queue에 데이터 삽입, 큐가 full이면 full 메시지를 출력하고, 큐 안의 데이터를 이동해야 할 경우 “data shift”메세지를 출력해야 함. 
	delete // queue에 데이터 삭제, empty일 때 데이터를 삭제하면 Queue empty 메시지를 출력하고 종료함.
	qprint // queue의 내용을 프린트
	quit // 프로그램 수행 종료
	잘못된 명령어 // 메시지 오류를 출력
	*/

	while (1)
	{
		//char *fgets (char *string, int n, FILE *stream);
		fgets(input, sizeof(input), fp);
		word = strtok(input, " \n");

		if (!strcmp(word, "add"))
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
					sscanf(input + strlen(word) + 1, "%d%s", &(queue + rear)->id, &(queue + rear)->name);
				}
			}
			else
			{
				sscanf(input + strlen(word) + 1, "%d%s", &(queue + rear)->id, &(queue + rear)->name);
			}
		}

		else if (!strcmp(word, "delete"))
		{
			if (rear == front)
			{
				printf("queue empty, cannot delete element.\n");
				break;
			}
			front++;
		}

		else if (!strcmp(word, "qprint"))
		{
			for (int i = front + 1; i < rear + 1; i++)
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