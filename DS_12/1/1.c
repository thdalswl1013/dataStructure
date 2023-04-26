#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftchild;
	treePointer rightchild;
};
treePointer stack[80];

int top = -1;

void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);
void insert(char ch);
treePointer createTree(treePointer ptr, char ch);
treePointer pop();
void push(treePointer ptr);

int main(void)
{
	treePointer tree = NULL;
	char ch;
	FILE* fp;
	fp=fopen("input.txt", "r");


	while (1) 
	{
		fscanf(fp, "%c", &ch);
		if (feof(fp))
			break;
		insert(ch);
	}

	tree = pop();


	printf("the length of input string should be less than 80\n");
	printf("input string(postfix expression) : AB/C*D*E+\n");
	printf("creating its binary tree\n");

	printf("\nInorder traversal		: ");

	inorder(tree);
	printf("\nPreorder traversal		: ");
	preorder(tree);

	printf("\nPostorder traversal		: ");
	postorder(tree);
	printf("\n");

	return 0;
}


void inorder(treePointer ptr)
{
	if (ptr) 
	{
		inorder(ptr->leftchild);
		printf("%c", ptr->data);
		inorder(ptr->rightchild);
	}
}

void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftchild);
		preorder(ptr->rightchild);
	}
}

void postorder(treePointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftchild);
		postorder(ptr->rightchild);
		printf("%c", ptr->data);
	}
}


void push(treePointer ptr)
{
	stack[++top] = ptr;
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

	else 
	{
		temp = createTree(temp, ch);
		push(temp);
	}
}

