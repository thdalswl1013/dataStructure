#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 15
#define MAX_QUEUE_SIZE 3

typedef struct
{
	int id;
	char name[MAX_NAME_SIZE];
}element;

element queue[MAX_QUEUE_SIZE];

int rear = -1;
int front = -1;
int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	char* word = NULL;
	//char* nword;
	char input[80];

	while (!feof(fp))
	{
		fgets(input, sizeof(input), fp);
		word = strtok(input, " \n");

		if (strcmp(word, "add") == 0)
		{
			rear++;

			sscanf(input + strlen(word) + 1, "%d%s", &queue[rear].id, &queue[rear].name);
		}

		else if (strcmp(word, "delete") == 0)
		{
			if (rear == front)
			{
				printf("Queue Empty\n");
				break;
			}
			front++;
		}

		else if (strcmp(word, "qprint") == 0)
		{
			for (int i = front + 1; i <= rear; i++)
				printf("%d %s\n", queue[i].id, queue[i].name);
			printf("\n");

		}

		else if (strcmp(word, "quit") == 0)
		{
			break;
		}

		else
		{
			printf("Error!\n");
		}
	}





	return 0;
}