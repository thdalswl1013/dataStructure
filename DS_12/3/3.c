#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftchild;
	treePointer rightchild;
};
treePointer stack[80];
int top = -1;
int cnt = 0;

void iterPostorder(treePointer node);
void iterPreorder(treePointer node);
void insert(char ch);
treePointer createTree(treePointer ptr, char ch);
void push(treePointer ptr);
treePointer pop();

int main()
{
	treePointer tree = NULL;
	char ch;
	FILE* fp;
	fp = fopen("input.txt", "r");


	while (1)
	{
		fscanf(fp, "%c", &ch);
		if (feof(fp))
			break;
		insert(ch);
	}

	tree = pop();


	printf("the length of input string should be less than 80\n");
	printf("input string (postfix expresstion) : AB/C*D*E+\n");
	printf("creating its binary tree\n");

	
	printf("\niterative preorder traversal		: ");
	iterPreorder(tree);
	printf("\niterative postorder traversal		: ");
	iterPostorder(tree);
	printf("\n");
}

void push(treePointer ptr)
{
	stack[++top] = ptr;
	cnt++;
}

treePointer pop()
{
	treePointer temp = NULL;

	if (top >= 0)
		temp = stack[top--];
	return temp;
}

treePointer createTree(treePointer ptr, char ch)
{
	treePointer temp;
	temp = malloc(sizeof(*temp));
	temp->data = ch;
	temp->leftchild = NULL;
	temp->rightchild = NULL;

	return temp;
}

void insert(char ch)
{
	treePointer temp = NULL;

	if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%') {
		temp = createTree(temp, ch);
		temp->rightchild = pop();
		temp->leftchild = pop();
		push(temp);
	}
	else {
		temp = createTree(temp, ch);
		push(temp);
	}
}

void iterPreorder(treePointer node)
{
	cnt = 0;
	top = -1;
	push(node);

	while (top >= 0)
	{
		node = pop();
		if (node->rightchild)
			push(node->rightchild);

		if (node->leftchild)
			push(node->leftchild);

		printf("%c", node->data);
	}
}

void iterPostorder(treePointer node)
{
	cnt = 0;
	top = -1;
	push(node);
	for (; node; node = node->leftchild)
	{
		if (node->rightchild)
			push(node->rightchild);

		if (node->leftchild)
			push(node->leftchild);
	}

	while (1) 
	{
		if (top == -1)
			break;

		printf("%c", stack[top--]->data);
	}
}
