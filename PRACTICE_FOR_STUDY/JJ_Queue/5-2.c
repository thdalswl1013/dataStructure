#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 10

typedef struct 
{
	int id; // unique id
	char name[MAX_NAME_SIZE]; //last name
} element;

element queue[MAX_QUEUE_SIZE];


int front = -1; // 삭제 연산
int rear = -1; // 삽입 연산 

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

		/***********************************/
		if (strcmp(word, "add") == 0)
		{
			// queue에 데이터 삽입, 큐가 full이면 full 메시지를 출력하고, 
			// 큐 안의 데이터를 이동해야 할 경우 “data shift”메세지를 출력해야 함.

			if ((rear == MAX_QUEUE_SIZE - 1) && (front == -1)) // queue full
			{
				printf("Queue full\n");

			}

			else if ((rear == MAX_QUEUE_SIZE - 1) && (front > -1)) // queue data shift
			{
				printf("data shift\n");

				int num = rear - (front + 1);
				int temp = front + 1;

				for (int i = 0; i < num + 1; i++)
				{
					queue[i] = queue[temp++];
				}
				front = -1;
				rear = num;
				rear++;
				sscanf(input + strlen(word) + 1, "%d %s\n", &(queue + rear)->id, &(queue + rear)->name);

			}
			else
			{
				rear++;
				sscanf(input + strlen(word) + 1, "%d %s\n", &(queue+rear)->id, &(queue+rear)->name);

			}
			
		}
		/***********************************/

		else if (strcmp(word, "delete") == 0)
		{
			if (front == rear)
			{
				printf("Queue empty\n");
				break;
			}

			front++;

		}



		else if (strcmp(word, "qprint") == 0)
		{
			for (int i = front+1; i < rear + 1; i++)
			{
				printf("%d %s\n", queue[i].id, queue[i].name);
			}
			printf("\n");

		}



		else if (strcmp(word, "quit") == 0)
		{
			break;
		}


		else
		{
			printf("Wrong Command! Try again!\n");
			printf("\n");
		}


	}
	
	fclose(fp);

	return 0;
}