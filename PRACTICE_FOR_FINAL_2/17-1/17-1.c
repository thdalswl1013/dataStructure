#define _CRT_SECURE_NO_WARNINGS   //안돌아가..
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node
{
	int data;
	nodePointer link;
};
nodePointer graph[10];

void insert(int u, int v);

int found[10];
void bfs(int i);
int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");


	int vertex, edge;
	fscanf(fp, "%d %d", &vertex, &edge); // u, 4, 6

	int u, v;
	while (!feof(fp))
	{
		fscanf(fp, "%d %d", &u, &v);
		insert(u, v);
		insert(v, u);
	}

	printf("adjacency list\n");

	for (int i = 0; i < vertex; i++) // 
	{
		printf("\nadjList[%d]: ", i);

		for (nodePointer ptr = graph[i]; ptr; ptr = ptr->link)
			printf("%3d", ptr->data);
	}

	
	int cnt = 1;

	for (int i = 0; i < vertex; i++)
	{
		if (!found[i])
		{
			printf("\nconnected %d: ", cnt++);
			bfs(i);
		}
	}

	return 0;
}

void insert(int u, int v) //
{
	nodePointer temp;
	temp = (nodePointer)malloc(sizeof(*temp));
	temp->data = v;

	if (graph[u])
	{
		temp->link = graph[u];
		graph[u] = temp;
	}

	else
	{
		temp->link = NULL;
		graph[u] = temp;
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