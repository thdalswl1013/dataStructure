#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef struct
{
	int id;
	char name[MAX_STACK_SIZE];
}element;

element stack[MAX_STACK_SIZE];

int top = -1;

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("<< stack operations where MAX_STACK_SIZE is 5 >>\n");
	printf("the format of the stack operation is as follows!!\n");
	printf("push 1 Jung\n");
	printf("pop\n\n");
	printf("*************************************************\n");

	char* word = NULL;
	char input[80];

	while(1)
	{
		fgets(input, sizeof(input), fp); // �ٹٲ� ���ڰ� ���� ������ ���ڿ� �б�
		word = strtok(input, " \n"); // input�� " \n" �������� �ڸ���

		
		if (strcmp(word, "push") == 0) // stack�� ������ ����, full�̸� ���� ���� ������ ����ϰ� ����
		{
			top++;

			if (top >= MAX_STACK_SIZE)
			{
				printf("stack is full, cannot add element\n");
				printf("current stack element : \n");

				for (int i = top - 1; i >= 0; i--)
				{
					printf("%d %s\n", stack[i].id, stack[i].name);
				}
				break;
			}

			/*
			sscanf(string, "%s %d %d %d", msg, &number1, &number2, &number3);
			-> scanf�� �޸� �� �� �Ű������� �츮�� �Է��� ���ڿ� �߰�
			*/ 
			sscanf(input+strlen(word)+1, "%d %s", &(stack+top)->id, (stack+top)->name);
		}

		else if (strcmp(word, "pop") == 0) // stack�� ������ ����, empty�̸� ���� �޽����� ����ϰ� ����
		{
			top--;
		}

		else if (strcmp(word, "sprint") == 0) // stack�� ������ ����Ʈ
		{
			for (int i = top; i >= 0; i--)
				printf("%d %s\n", stack[i].id, stack[i].name); // ����, �̸�
		}
		
		else if (strcmp(word, "quit") == 0) // ���α׷� ���� ����. �߸��� ��ɾ� 
			break;

		else // �޽��� ������ ���
			printf("wrong command Try it again\n\n");

	}




	fclose(fp);
	return 0;
}
