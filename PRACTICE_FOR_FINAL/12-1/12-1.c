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

void push(treePointer ptr); 
treePointer pop();


int main(void)
{
	treePointer tree = NULL;
	char input;
	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("the length of input string should be less than 80\n");
	printf("input string(postfix expression) : ");

	while (EOF!= fscanf(fp, "%c", &input))
	{
		printf("%c", input);
		treePointer temp = NULL;
		temp = malloc(sizeof(*temp));
		temp->data = input;
		temp->leftchild = NULL;
		temp->rightchild = NULL;


		if (input == '+' || input == '-' || input == '/' || input == '*' || input == '%')
		{
			temp->rightchild = pop();
			temp->leftchild = pop();
			push(temp);
		}

		else
		{
			push(temp);
		}
	}

	tree = pop();



	printf("\ncreating its binary tree\n");

	printf("\nInorder traversal	: ");
	inorder(tree);

	printf("\nPreorder traversal	: ");
	preorder(tree);

	printf("\nPostorder traversal	: ");
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