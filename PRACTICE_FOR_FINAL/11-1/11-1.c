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
treePointer root;

void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("(%p : %p %c %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("(%p : %p %c %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
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
		printf("(%p : %p %c %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
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

	root = pNodeA;


	printf("Creating a binary tree\n");
	printf("Three binary tree traversals\n");

	printf("\nInorder traversal\n");
	inorder(root);

	printf("\nPreorder traversal\n");
	preorder(root);

	printf("\nPostorder traversal\n");
	postorder(root);

	return 0;
}

