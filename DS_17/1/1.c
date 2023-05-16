#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTEX 30
#define FALSE 0
#define TRUE 1
short int visited[MAX_VERTEX];

typedef struct node* graphPointer;
typedef struct node 
{
	int vertex;
	graphPointer link;
}node;

typedef struct graphType 
{
	int n;
	graphPointer head[MAX_VERTEX];
}graphType;


void insertEdge(graphType* g, int u, int v);
void dfs(graphType* g, int v);

int main()
{
	graphType* g;
	g = malloc(sizeof(graphType));
	for (int i = 0; i < MAX_VERTEX; i++) 
		g->head[i] = NULL;

	FILE* fp;
	fp=fopen("input.txt", "r");
	int vertex, edge;
	int u, v;

	fscanf(fp, "%d %d", &vertex, &edge);
	g->n = vertex;

	while (!feof(fp)) 
	{
		fscanf(fp, "%d %d", &u, &v);
		insertEdge(g, u, v);
		insertEdge(g, v, u);
	}

	printf("<<<<<<<<<< Adjacency List >>>>>>>>>>\n");
	graphPointer cur;
	for (int i = 0; i < g->n; i++)
	{
		printf("graph[%d] :", i);
		cur = g->head[i];
		while (cur)
		{
			printf("%3d", cur->vertex);
			cur = cur->link;
		}
		printf("\n");
	}

	printf("\n<<<<<<<<<< Depth First Search >>>>>>>>>>\n");
	for (int i = 0; i < vertex; i++)
	{
		printf("dfs<%d> :", i);
		dfs(g, i);
		printf("\n");

		for (int j = 0; j < vertex; j++) 
			visited[j] = FALSE;
	}
}

void insertEdge(graphType* g, int u, int v)
{
	graphPointer node;
	node = malloc(sizeof(graphPointer));
	if (g->head[u])
	{
		node->vertex = v;
		node->link = g->head[u];
		g->head[u] = node;
	}
	else
	{
		node->vertex = v;
		node->link = NULL;
		g->head[u] = node;
	}
}

void dfs(graphType* g, int v)
{
	graphPointer w;
	visited[v] = TRUE;
	printf("%3d", v);
	for (w = g->head[v]; w; w = w->link)
	{
		if (!visited[w->vertex])
			dfs(g, w->vertex);
	}
}
