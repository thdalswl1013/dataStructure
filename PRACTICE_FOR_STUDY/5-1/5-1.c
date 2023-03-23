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
		fgets(input, sizeof(input), fp); // 줄바꿈 문자가 나올 때까지 문자열 읽기
		word = strtok(input, " \n"); // input을 " \n" 기준으로 자르기

		
		if (strcmp(word, "push") == 0) // stack에 데이터 삽입, full이면 스택 안의 내용을 출력하고 종료
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
			-> scanf와 달리 젤 앞 매개변수에 우리가 입력한 문자열 추가
			*/ 
			sscanf(input+strlen(word)+1, "%d %s", &(stack+top)->id, (stack+top)->name);
		}

		else if (strcmp(word, "pop") == 0) // stack에 데이터 삭제, empty이면 오류 메시지를 출력하고 종료
		{
			top--;
		}

		else if (strcmp(word, "sprint") == 0) // stack의 내용을 프린트
		{
			for (int i = top; i >= 0; i--)
				printf("%d %s\n", stack[i].id, stack[i].name); // 숫자, 이름
		}
		
		else if (strcmp(word, "quit") == 0) // 프로그램 수행 종료. 잘못된 명령어 
			break;

		else // 메시지 오류를 출력
			printf("wrong command Try it again\n\n");

	}




	fclose(fp);
	return 0;
}
