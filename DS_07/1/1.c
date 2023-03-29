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

int top = -1;

int stack[MAX_STACK_SIZE];
char expression[MAX_EXPRESSION_SIZE];

int eval(void);
precedence getToken(char* symbol, int* n);
void push(int item);
void stackFull();
int pop();
int stackEmpty();

FILE* fp1;
FILE* fp2;

int main(void)
{
	fp1=fopen("input.txt", "r");
	fp2=fopen("output.txt", "w");

	int result;

	fgets(expression, MAX_EXPRESSION_SIZE, fp1);
	fgets(expression, MAX_EXPRESSION_SIZE, fp2);

	printf("postfix expression : %s\n", expression);
	printf("the evaluation value : %d\n", eval());

	fprintf(fp2, "postfix expression : %s\n", expression);
	fprintf(fp2, "the evaluation value : %d\n", eval());

	return 0;
}



int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0; 

	top = -1;
	token = getToken(&symbol, &n);

	while (token != eos)
	{
		if (token == operand)
			push(symbol - '0');  

		else 
		{
			op2 = pop(); 
			op1 = pop();
			switch (token) 
			{
			case plus:
				push(op1 + op2);
				break;
			case minus:
				push(op1 - op2);
				break;
			case times:
				push(op1 * op2);
				break;
			case divide:
				push(op1 / op2);
				break;
			case mod:
				push(op1 % op2);
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
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
	item = -1;
	return item;
}

