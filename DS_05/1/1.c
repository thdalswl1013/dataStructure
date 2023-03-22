#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_SIZE 30
#define MAX_STACK_SIZE 5
typedef struct
{
	int id; // unique id
	char name[MAX_NAME_SIZE]; // last name
}element;

int main(void)
{
	element stack[MAX_STACK_SIZE];
	char* word = NULL;
	char input[80];

	int top = -1;


	FILE* fp;
	fp = fopen("input.txt", "r");	

	printf("<< Stack operations where MAX_STACK_SIZE is 5 >>\n");
	printf("The format of the stack operation is as follows!!\n");
	printf("push 1 Jung\npop\n");
	printf("\n*************************************************\n");

	/*
	push id name // stack에 데이터 삽입, full이면 스택 안의 내용을 출력하고 종료
	pop // stack에 데이터 삭제, empty이면 오류 메시지를 출력하고 종료
	sprint // stack의 내용을 프린트
	quit // 프로그램 수행 종료. 잘못된 명령어 // 메시지 오류를 출력
	*/

	while(1)
	{
		//char *fgets (char *string, int n, FILE *stream);
		fgets(input, sizeof(input), fp);
		word = strtok(input, " \n");

		if (!strcmp(word, "push"))
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
			sscanf(input + strlen(word) + 1, "%d%s", &(stack + top)->id, &(stack + top)->name);
		}

		else if (!strcmp(word, "pop"))
		{
			top--;
		}

		else if (!strcmp(word, "sprint"))
		{
			for (int i = top; i >= 0; i--)
			{
				printf("%d %s\n", stack[i].id, stack[i].name);
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