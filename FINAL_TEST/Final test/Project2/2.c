#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node
{
	int data;
	nodePointer link;
};

nodePointer graph[8]; 
int found[8];
void insert(int x, int y);
void bfs(int v);

int main(void)
{
	FILE* f;
	fopen_s(&f, "input.txt", "r");
	int x, y,e ,v;

	fscanf(f, "%d %d", &v, &e);
	while (!feof(f))
	{
		fscanf(f, " %d %d", &x, &y);
		insert(x, y);
		insert(y, x);
	}

	printf("<<<<<<<<<< Adjacency List>>>>>>>>>>>>\n");
	for (int i = 0; i < v; i++)
	{
		printf("\ngraph[%d] :  ",i);
		for (nodePointer ptr = graph[i]; ptr; ptr = ptr->link)
		{
			printf("%3d", ptr->data);
		}
	}
	printf("\n<<<<<<<<<< Connected Component >>>>>>>>>>>>");
	int count = 1;
	for (int i = 0; i < v; i++)
	{
		if (!found[i])
		{
			printf("\nconnected %d : ", count++);
			bfs(i);
		}
	}
}

void insert(int x, int y)
{
	nodePointer temp;
	temp = (nodePointer)malloc(sizeof(*temp));
	temp->data = y;
	if (graph[x])
	{
		temp->link = graph[x];
		graph[x] = temp;
	}
	else
	{
		temp->link = NULL;
		graph[x] = temp;
	}
}

void bfs(int v)
{
	found[v] = 1;
	printf("%3d", v);
	for (nodePointer ptr = graph[v]; ptr; ptr = ptr->link)
	{
		if (!found[ptr->data])
			bfs(ptr->data);
	}


}