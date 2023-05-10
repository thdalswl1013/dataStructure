#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTEX 10

typedef struct node* graphPointer;
typedef struct node 
{
	int vertex;
	graphPointer link;
}node;

typedef struct graphType 
{
	int vertex_n;
	graphPointer adjHead[MAX_VERTEX];
}graphType;

void insertEdge(graphType* g, int u, int v);

int main()
{
	graphType* g;
	g = malloc(sizeof(graphType));
	for (int i = 0; i < MAX_VERTEX; i++)
		g->adjHead[i] = NULL;

	char type;
	int vertex, edge;
	int u, v;

	FILE* fp;
	fp=fopen("input.txt", "r");

	fscanf(fp, "%c %d %d", &type, &vertex, &edge);
	g->vertex_n = vertex;

	if (type == 'u') 
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d %d", &u, &v);
			insertEdge(g, u, v);
			insertEdge(g, v, u);
		}
	}
	else {
		while (!feof(fp)) 
		{
			fscanf(fp, "%d %d", &u, &v);
			insertEdge(g, u, v);
		}
	}

	printf("<<<<<<< Adjacency List >>>>>>>\n");
	graphPointer cur;
	for (int i = 0; i < g->vertex_n; i++)
	{
		printf("adjList[%d] : ", i);
		cur = g->adjHead[i];

		while (cur) 
		{
			printf("%d  ", cur->vertex);
			cur = cur->link;
		}
		printf("\n");
	}

}


void insertEdge(graphType* g, int u, int v)
{
	graphPointer node;
	node = malloc(sizeof(graphPointer));
	node->vertex = v;
	node->link = g->adjHead[u];
	g->adjHead[u] = node;
}
