#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node* treePointer;
typedef struct node
{
	int key;
	char name[10];
	int score;
	treePointer link;
};

treePointer tree[100];

void inorder(int n);
void insert(treePointer temp, int i);

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int num;
	fscanf(fp, "%d", &num);

	treePointer temp;

	for (int i = 1; i <= num; i++)
	{
		temp = (treePointer)malloc(sizeof(*temp));
		fscanf(fp, "%d %s %d", &temp->key, &temp->name, &temp->score);
		//printf("%d %s %d\n", temp->key, temp->name, temp->score);
		insert(temp, i);
	}

	int input;
	printf("ã�� �л��� key�� �Է��ϼ���: ");
	scanf("%d", &input);

	for (int i = 1; i <= num * 2; i++)
	{
		if (tree[i]->key == input)
		{
			printf("%d %s %d\n", tree[i]->key, tree[i]->name, tree[i]->score);

			if (tree[2 * i])
				printf("		��   �ڽ�: %d %s %d\n", tree[i * 2]->key, tree[i * 2]->name, tree[i * 2]->score);
			if (tree[2 * i + 1])
				printf("		���� �ڽ�: %d %s %d\n", tree[i * 2 + 1]->key, tree[i * 2 + 1]->name, tree[i * 2 + 1]->score);
			break;
		}
	}

	printf("inorder\n");
	inorder(1);

	printf("levelorder\n");
	for (int i = 1; i <= num * 2; i++)
	{
		if (tree[i])
			printf("%-3d, %d %s %d\n", i, tree[i]->key, tree[i]->name, tree[i]->score);
	}

	return 0;
}

void inorder(int n)
{
	if (tree[n])
	{
		inorder(2 * n);
		printf("%d %s %d\n", tree[n]->key, tree[n]->name, tree[n]->score);
		inorder(2 * n + 1);
	}
}

void insert(treePointer temp, int i)
{
	int parent = 1;
	int child = 2;

	if (i == 1)
	{
		tree[parent] = temp;
		return;
	}


	for (;;)
	{
		if (temp->key > tree[parent]->key)
		{
			if (tree[child + 1]) // rightChild�� �ִٸ�
			{
				parent = child + 1; 
				child = parent * 2;
			}
			else // rightChild�� ���ٸ�
			{
				tree[child + 1] = temp;
				break;
			}
		}
		else
		{
			if (tree[child])
			{
				parent = child;
				child = parent * 2;
			}
			else
			{
				tree[child] = temp;
				break;
			}
		}
	}
}