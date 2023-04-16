#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef struct
{
	int id;
	char name[20];
}element;
element stack[MAX_STACK_SIZE];

int top = -1;

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	char* word = NULL;
	char input[80];
	char* nword;


	printf("<< Stack operations where MAX_STACK_SIZE is 5 >>\n");

	while (!feof(fp))
	{
		fgets(input, sizeof(input), fp);
		word = strtok_s(input, " \n", &nword);

		if (strcmp(word, "push")==0)
		{
			top++;

			if (top == MAX_STACK_SIZE)
			{
				printf("Stack is full\n");

				for (int i = MAX_STACK_SIZE-1; i >= 0; i--)
					printf("%d %s\n", stack[i].id, stack[i].name);
			}

			sscanf(input + strlen(word) + 1, "%d %s", &stack[top].id, &stack[top].name);
			
		}

		else if (strcmp(word, "pop") == 0)
		{
			top--;
		}

		else if (strcmp(word, "sprint") == 0)
		{
			for (int i = top; i >= 0; i--)
			{
				printf("%d %s\n", stack[i].id, stack[i].name);
			}
		}

		else if (strcmp(word, "quit") == 0)
		{
			break;
		}

		else
			printf("Error!\n");
	}


	return 0;
}