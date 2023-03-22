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





	fclose(fp);
	return 0;
}
