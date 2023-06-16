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
		fgets(input, sizeof(input), fp); // 줄바꿈 문자가 나올 때까지 문자열 읽기
		word = strtok(input, " \n"); // input을 " \n" 기준으로 자르기


		if (strcmp(word, "push") == 0) // stack에 데이터 삽입, full이면 스택 안의 내용을 출력하고 종료
		{
			top++;

			if (top >= MAX_STACK_SIZE) // 스택이 풀인 경우.
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

		else if (strcmp(word, "sprint") == 0) // stack의 내용을 프린트
		{
			for (int i = top; i >= 0; i--)
			{
				printf("%d %s\n", stack[i].id, stack[i].name);
			}
			
		}

		else if (strcmp(word, "quit") == 0) // 프로그램 수행 종료. 잘못된 명령어 
			break;

		else
			printf("Wrong Command! Try Again!\n");
	}


	return 0;
}