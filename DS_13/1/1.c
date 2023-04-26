//5-3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef enum //13
{ 
	not, and, or , false, true, eos, operand
} logical;

typedef struct node* treePointer;
typedef struct node
{
	treePointer leftChild;
	treePointer rightChild;
	char data;
	int value;
}node;

treePointer root = NULL;
treePointer stack[MAX_STACK_SIZE];


int top = -1;
char expression[81];
int arr[8][3] = { 0 };
int i;

treePointer stackEmpty();
treePointer pop();
void stackFull();
void push(treePointer item);
treePointer createBinTree(void);


void postorderEval(treePointer node) //14
{
	if (node)
	{
		postorderEval(node->leftChild);
		postorderEval(node->rightChild);

		switch (node->data)
		{
		case '&':
			node->value = node->leftChild->value && node->rightChild->value;
			break;
		case '|':
			node->value = node->leftChild->value || node->rightChild->value;
			break;
		case '~':
			node->value = !(node->rightChild->value);
			break;
		case 'a':
			node->value = arr[i][0];
			break;
		case 'b':
			node->value = arr[i][1];
			break;
		case 'c':
			node->value = arr[i][2];
			break;
		default:
			break;
		}
	}
}


int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int cnt = 8;
	int row, col = 0;

	for (row = 0; row < 8; row++)
	{
		arr[row][col] = (row >> 2) & 1;
		arr[row][col + 1] = (row >> 1) & 1;
		arr[row][col + 2] = (row) & 1;
		col = 0;
	}

	fgets(expression, 80, fp);
	printf("input string(postfix): ab~&a~c&|c~|\n");

	root = createBinTree();

	printf("find true condition \n");
	for (i = 0; i < 8; i++) 
	{
		postorderEval(root);
		if (root->value)
			printf("a=%d, b=%d, c=%d\n", arr[i][0], arr[i][1], arr[i][2]);
	}

	return 0;
}

treePointer stackEmpty()
{
	treePointer item;
	item = NULL;
	return item;
}

treePointer pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

void stackFull()
{
	exit(EXIT_FAILURE);
}

void push(treePointer item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

treePointer createBinTree(void)
{
	treePointer pNode;
	logical token;
	char symbol;

	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);

	while (token != eos)
	{
		if (token == operand)
		{
			pNode = malloc(sizeof(*pNode));
			pNode->data = symbol;
			pNode->leftChild = NULL;
			pNode->rightChild = NULL;

			push(pNode);
		}

		else
		{
			if (token == not )
			{
				pNode = malloc(sizeof(*pNode));
				pNode->data = symbol;
				pNode->rightChild = pop();
				pNode->leftChild = NULL;
			}

			else
			{
				pNode = malloc(sizeof(*pNode));
				pNode->data = symbol;
				pNode->rightChild = pop();
				pNode->leftChild = pop();
			}
			push(pNode);
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

logical getToken(char* symbol, int* n)
{
	*symbol = expression[(*n)++];

	switch (*symbol)
	{
	case '&': 
		return and;
	case '|': 
		return or ;
	case '~': 
		return not;
	case '\0':
		return eos;
	default: 
		return operand;
	}
}
