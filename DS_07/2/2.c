#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPRESSION_SIZE 80

typedef enum
{
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };


precedence getToken(char** symbol, int* n);
void postfix(void);
void printToken(precedence);

precedence stack[MAX_STACK_SIZE];

int top = -1;

void push(precedence item);
void stackFull();
precedence pop();
precedence stackEmpty();

char expression[MAX_EXPRESSION_SIZE];

FILE* fp1;
FILE* fp2;

int main(void)
{
	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w");

	int result;

	fgets(expression, MAX_EXPRESSION_SIZE, fp1);

	printf("<<<<<<<<<< infix to postfix >>>>>>>>>>\n");

	printf("infix expression     : %s\n", expression);
	printf("postfix expression   : ");

	postfix();
}

precedence getToken(char* symbol, int* n)
{
	*symbol = expression[(*n)++];

	switch (*symbol)
	{
	case '(': 
		return lparen;
	case ')':
		return rparen;
	case '+': 
		return plus;
	case '-': 
		return minus;
	case '/': 
		return divide;
	case '*': 
		return times;
	case '%': 
		return mod;
	case '\0': 
		return eos;
	default: 
		return operand;
	}
}

void postfix(void)
{
	char symbol;
	precedence token;
	int n = 0;
	top = 0;
	stack[0] = eos;

	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
		{
			printf("%c", symbol);
			fprintf(fp2, "%c", symbol);
		}

		else if (token == rparen)
		{
			while (stack[top] != lparen)
				printToken(pop());

			pop();
		}

		else
		{
			while (isp[stack[top]] >= icp[token])
				printToken(pop());

			push(token);
		}
	}

	while ((token = pop()) != eos)
	{
		printToken(token);
	}

	printf("\n");
}

void printToken(precedence pre) 
{

	switch (pre) 
	{
	case plus:	printf("%c", '+');
		fprintf(fp2, "%c", '+');
		break;
	case minus:	printf("%c", '-');
		fprintf(fp2, "%c", '-');
		break;
	case divide:
		printf("%c", '/');
		fprintf(fp2, "%c", '/');
		break;
	case times:	printf("%c", '*');
		fprintf(fp2, "%c", '*');
		break;
	case mod:	printf("%c", '%');
		fprintf(fp2, "%c", '%');
		break;
	case eos:
		printf("%c", '\0');
		fprintf(fp2, "%c", '\0');
		break;
	}
}


void push(int item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	int item;
	fprintf(stderr, "Stack is full\n");
	exit(EXIT_FAILURE);
}


int pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

int stackEmpty()
{
	int item;
	item = operand;
	return item;
}

