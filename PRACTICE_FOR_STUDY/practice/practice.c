// stack

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 10

typedef struct
{
	int id;
	char name[MAX_NAME_SIZE];
}element;

element stack[MAX_STACK_SIZE];

int top = -1;

int main(void)
{
	FILE* fp;
	fp = fopen("a.txt", "r");
	
	char input[80];
	char* word = NULL;

	while (1)
	{
		fgets(input, sizeof(input), fp);
		word = strtok(input, " \n");


		if (strcmp(word, "push") == 0)
		{
			if (top == MAX_STACK_SIZE - 1)
			{
				printf("Stack full!\n");

				for (int i = top - 1; i >= 0; i--)
					printf("%d %s", stack[i].id, stack[i].name);

				break;

			}
			else
			{
				top++;
				sscanf(input + strlen(word) + 1, "%d %s", &stack[top].id, &stack[top].name);
			}
		}

		else if (strcmp(word, "pop") == 0)
		{
			if (top == -1)
				printf("stack is empty\n");

			top--;
		}

		else if (strcmp(word, "sprint") == 0)
		{
			for (int i = top - 1; i >= 0; i--)
				printf("%d %s", stack[i].id, stack[i].name);

		}

		else if (strcmp(word, "quit") == 0)
			break;

		else
			printf("Wrong Command! Try again!\n");
	}

	fclose(fp);
	return 0;
}