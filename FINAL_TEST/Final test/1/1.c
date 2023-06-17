#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct element* nodePointer;
typedef struct element
{
	int key;
	int score;
	char name[100];
	nodePointer link;
}element;

nodePointer tree[100];
nodePointer stack[100];
int top = -1;
void insert(nodePointer temp, int i);
void inorder(int n);
int main(void)
{
	FILE* f;
	fopen_s(&f, "input.txt", "r");

	int n, key, score;
	fscanf(f, "%d", &n);

	nodePointer temp;

	for (int i = 1; i <= n; i++)
	{
		temp = (nodePointer)malloc(sizeof(*temp));
		fscanf(f, " %d %s %d", &key, temp->name, &score);
		temp->key = key; temp->score = score;
		insert(temp, i);
	}

	printf("찾을 학생의 key를 입력하세요 : ");
	scanf("%d", &key);
	for (int i = 1; i <= n * 2;)
	{
		if (tree[i]->key == key)
		{
			printf("%d %s %d\n", tree[i]->key, tree[i]->name, tree[i]->score);
			if(tree[i*2])
				printf("	왼  쪽 자식 : %d %s %d\n", tree[i * 2]->key, tree[i * 2]->name, tree[i * 2]->score);
			if(tree[i*2+1])
				printf("	오른쪽 자식 : %d %s %d\n", tree[i * 2 + 1]->key, tree[i * 2+1]->name, tree[i * 2+1]->score);
			break;
		}
		if (tree[i]->key > key)
		{
			i = i * 2;
		}
		else
		{
			i = i * 2 + 1;
		}
		
	}
	printf("\ninorder search tree: \n");
	inorder(1);
	printf("\nlevel order search tree: \n");
	for (int i = 1; i <= n * 2; i++)
	{
		if (tree[i])
			printf("%d %s %d\n", tree[i]->key, tree[i]->name, tree[i]->score);
	}
}

void inorder(int n)
{
	if (tree[n])
	{
		inorder(n * 2);
		printf("%d %s %d\n", tree[n]->key, tree[n]->name, tree[n]->score);
		inorder(n * 2 + 1);
	}
}
void insert(nodePointer temp, int i)
{
	int parent = 1;
	int child = 2;

	if (i == 1)
	{
		tree[parent] = temp;
		return;
	}
		

	for(;;)
	{
		if (temp->key > tree[parent]->key)
		{
			if (tree[child + 1])
			{
				parent = child + 1;
				child = parent * 2;
			}
			else
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