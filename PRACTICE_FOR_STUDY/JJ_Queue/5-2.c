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

			if (rear == MAX_QUEUE_SIZE-1)
				printf("Queue full\n");

			else
			{
				rear++;
				sscanf(input + sizeof(word) + 1, "%d %s\n", &queue[rear].id, &queue[rear].name);

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
			for (int i = front; i < rear + 1; i++)
			{
				printf("%d %s", queue[i].id, queue[i].name);
			}

		}



		else if (strcmp(word, "quit") == 0)
		{
			break;
		}


		else
		{
			printf("Wrong Command! Try again!\n");
		}


	}
	
	fclose(fp);

	return 0;
}