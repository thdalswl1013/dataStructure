#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct node* treePointer;
typedef struct node 
{
	int key;
	treePointer left, right;
};

int stack[MAX_SIZE];

treePointer search(treePointer root, int k);
treePointer createnode(int k);
treePointer insert(treePointer node, int k);
void inorder(treePointer root);

int main()
{
	treePointer root = NULL;
	int n;
	int seed;
	int num, searchnum;

	printf("random number generation (1 ~ 500)\n");

	printf("the number of nodes in BST (less than and equal to 50) : ");
	scanf("%d", &n);

	printf("%s", "seed : ");
	scanf("%u", &seed);

	printf("\ncreating a BST from random numbers\n");
	printf("generating number : ");

	srand(seed);

	for (int i = 0; i < n; i++)
	{
		num = rand() % 500 + 1;
		for (int j = 0; j < i; j++) 
		{
			if (stack[i] == stack[j]) 
			{
				i--;
				break;
			}
		}
		printf("%4d", num);
		stack[i] = num;
	}

	for (int i = 0; i < n; i++) 
	{
		root = insert(root, stack[i]);
	}

	printf("\nthe key to search : ");
	scanf("%d", &searchnum);

	printf("the search process : ");
	search(root, searchnum);
	printf("\nthe element is in BST\n");

	printf("\ninorder traversal of the BST shows the sorted sequence\n");
	inorder(root);

	return 0;
}

treePointer search(treePointer root, int k)
{
	if (!root)
		return NULL;
	if (k == root->key) 
	{
		printf("%d => ", root->key);
		return root;
	}
	if (k < root->key) 
	{
		printf("%d => ", root->key);
		return search(root->left, k);
	}
	else 
	{
		printf("%d => ", root->key);
		search(root->right, k);
	}
}

treePointer createnode(int k)
{
	treePointer temp = malloc(sizeof(*temp));
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

treePointer insert(treePointer node, int k)
{
	if (node == NULL)
		return createnode(k);
	if (k < node->key)
		node->left = insert(node->left, k);
	else if (k > node->key)
		node->right = insert(node->right, k);

	return node;
}

void inorder(treePointer root)
{
	if (root) 
	{
		inorder(root->left);
		printf("%3d", root->key);
		inorder(root->right);
	}
}