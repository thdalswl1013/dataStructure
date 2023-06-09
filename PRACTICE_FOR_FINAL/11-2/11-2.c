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

void preorder(treePointer ptr);
void inorder(treePointer ptr);
void postorder(treePointer ptr);


int main(void)
{
	printf("creating a complete binary tree\n");

	FILE* fp;
	fp = fopen("input.txt", "r");
	
	char queue[100]; 
	int i = 1;

	while (!feof(fp))
	{
		char input;
		fscanf(fp, "%c", &input);
		queue[i] = input;
		i++;
	}

	/*
	for (int i = 1; i < 10; i++) // 현재 i는 11이되어있음(1 + input 길이 + 1)
		printf("%c ", queue[i]);
	*/


	treePointer tree[100];
	int num = i - 2; //i를 9로 만들어 -> input 제일 끝 값을 가리키도록 
	for (int k = 1; k <= num; k++)
	{
		tree[k] = (treePointer)malloc(sizeof(*(tree[k])));
		tree[k]->data = queue[k];
	}

	for (int k = 1; k <= num;)
	{
		if (k > 1)
		{
			int parent = k / 2;
			tree[parent]->leftChild = tree[k];
			tree[parent]->rightChild = tree[k + 1];
			k = k + 2;
		}

		else
			k = 2; // 계산 없이 걍 k=2로 만들어줘
	}

	for (int k = (num / 2) + 1; k <= num; k++) //k=5,6,7,8,9 -> leaf 노드들
	{
		tree[k]->leftChild = NULL;
		tree[k]->rightChild = NULL;
	}

	printf("\nThree binary tree traversals");
	printf("\nInorder traversal	: ");
	inorder(tree[1]);
	printf("\nPreorder traversal	: ");
	preorder(tree[1]);
	printf("\nPostorder traversal	: ");
	postorder(tree[1]);
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