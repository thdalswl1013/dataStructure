#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftChild;
	treePointer rightChild;
};
treePointer tree[100];

char queue[100];

void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);
treePointer createNode(char data);

int main(void)
{
	printf("Creating a complete binary tree\n");
	printf("three binary tree traversals\n");

	FILE* fp;
	fp = fopen("input.txt", "r");

	int i = 1;

	while (!feof(fp))
	{
		char data;
		fscanf(fp, "%c", &data);
		queue[i] = data;
		i++;
	}

	int num = i - 2;
	for (int k = 1; k <= num; k++)
	{
		tree[k] = (treePointer)malloc(sizeof(*(tree[k])));
		tree[k]->data = queue[k];
	}

	for (int k = 1; k <= num;)
	{
		if (k > 1)
		{
			int par = k / 2;
			tree[par]->leftChild = tree[k];
			tree[par]->rightChild = tree[k + 1];
			k = k + 2;
		}
		else
			k = 2;
	}

	for (int i = (num / 2) + 1; i <= num; i++)
	{
		tree[i]->rightChild = NULL;
		tree[i]->leftChild = NULL;
	}


	inorder(tree[1]); printf("\n");
	preorder(tree[1]); printf("\n");
	postorder(tree[1]); printf("\n");

	return 0;
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
void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
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

treePointer createNode(char data)
{
	treePointer pNode;

	pNode = malloc(sizeof(*pNode));
	pNode->data = data;
	pNode->leftChild = NULL;
	pNode->rightChild = NULL;

	return pNode;
}
