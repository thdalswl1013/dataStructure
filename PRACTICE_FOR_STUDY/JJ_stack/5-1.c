#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 10

typedef struct 
{
	int id; // unique id
	char name[MAX_NAME_SIZE]; // last name
} element;
element stack[MAX_STACK_SIZE];

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");
	
	char *word = NULL;
	char input[80];

	int top = -1;

	while (!feof(fp))
	{
		fgets(input, sizeof(input), fp); // �ٹٲ� ���ڰ� ���� ������ ���ڿ� �б�
		word = strtok(input, " \n"); // input�� " \n" �������� �ڸ���


		if (strcmp(word, "push") == 0) // stack�� ������ ����, full�̸� ���� ���� ������ ����ϰ� ����
		{
			top++;

			if (top >= MAX_STACK_SIZE) // ������ Ǯ�� ���.
			{
				printf("stack is full!\n");
				for (int i = MAX_STACK_SIZE - 1; i >= 0; i--)
				{
					printf("%d %s\n", stack[i].id, stack[i].name);
				}
				break;
			}

			else
			{
				sscanf(input + strlen(word) + 1, "%d %s", &stack[top].id, &stack[top].name);
			}
	
		}

		else if (strcmp(word, "pop") == 0)
		{
			if (top == -1)
			{
				printf("stack is empty.\n");
			}
			else
			{
				//printf("%d %s\n", stack[top].id, stack[top].name);
				top--;
			}
			
		}

		else if (strcmp(word, "sprint") == 0) // stack�� ������ ����Ʈ
		{
			for (int i = top; i >= 0; i--)
			{
				printf("%d %s\n", stack[i].id, stack[i].name);
			}
			
		}

		else if (strcmp(word, "quit") == 0) // ���α׷� ���� ����. �߸��� ��ɾ� 
			break;

		else
			printf("Wrong Command! Try Again!\n");
	}


	return 0;
}