#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftChild;
	treePointer rightChild;
};

void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("(%p : %p  %c  %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("(%p : %p  %c  %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
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
		printf("(%p : %p  %c  %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
	}
}

treePointer createNode(char data);

int main(void)
{
	treePointer pNodeA, pNodeB, pNodeC, pNodeD, pNodeE;
	treePointer root = NULL;

	pNodeA = createNode('A');
	pNodeB = createNode('B');
	pNodeC = createNode('C');
	pNodeD = createNode('D');
	pNodeE = createNode('E');

	pNodeB->leftChild = pNodeD;
	pNodeB->rightChild = pNodeE;

	pNodeA->leftChild = pNodeB;
	pNodeA->rightChild = pNodeC;

	root=pNodeA;

	printf("creating a binary tree\n\n");
	printf("three binary tree traversals\n");

	printf("inorder traversal		:\n");
	inorder(root);
	printf("\n");

	printf("preorder traversal		:\n");
	preorder(root);
	printf("\n");

	printf("postorder traversal		:\n");
	postorder(root);
	printf("\n");


	return 0;
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
