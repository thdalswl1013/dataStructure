#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftChild, rightChild;
};
treePointer tree[100];

void preorder(treePointer ptr);
void inorder(treePointer ptr);
void postorder(treePointer ptr);


int main(void)
{
	printf("creating a complete binary tree\n");

	FILE* fp;
	fp = fopen("input.txt", "r");
	
	char queue[100]; int i = 1;
	while (!feof(fp))
	{
		char input;
		fscanf(fp, "%c", &input);
		queue[i] = input;
		i++;
	}

	/*
	for (int i = 1; i < 10; i++)
		printf("%c ", queue[i]);
	*/

	printf("\nThree binary tree traversals");
	printf("\nInorder traversal	: ");

	printf("\nPreorder traversal	: ");
	
	printf("\nPostorder traversal	: ");

	printf("\n");

	return 0;
}


void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("%c ", ptr->data);
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c ", ptr->data);
	}
}