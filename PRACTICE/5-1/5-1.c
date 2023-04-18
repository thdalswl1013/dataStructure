#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef struct
{
	int id;
	char name[10];
}element;
element stack[MAX_STACK_SIZE];

int top = -1;

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	// 파일 불러오기 & 환형큐
	char* word = NULL;
	char input[80];

	while (1)
	{
		fgets(input, sizeof(input), fp);
		word = strtok(input, " \n");

		if (!strcmp(word, "push"))
		{
			top++;
			if (top >= MAX_STACK_SIZE)
			{
				printf("stack is full.\n");
	
				for (int i = top-1 ; i>=0 ; i--)
					printf("%d %s\n", stack[i].id, stack[i].name);
				break;

			}

			sscanf(input + strlen(word) + 1, "%d %s", &stack[top].id, &stack[top].name);

		}

		else if (!strcmp(word, "pop"))
		{
			top--;
		}


		else if (!strcmp(word, "sprint"))
		{
			for (int i = top; i >= 0; i--)
				printf("%d %s\n", stack[i].id, stack[i].name);
		}

		else if (!strcmp(word, "quit"))
		{
			break;
		}
		else
		{
			printf("메세지 오류\n");
		}

	}
	return 0;
}