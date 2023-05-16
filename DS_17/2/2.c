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

typedef struct queue* queuePointer;
typedef struct queue
{
	int vertex;
	queuePointer link;
};
queuePointer front, rear;

void addq(int v);
int deleteq();
void insertEdge(graphType* g, int u, int v);
void bfs(graphType* g, int v);

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
		fscanf_s(fp, "%d %d", &u, &v);
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

	printf("\n<<<<<<<<<< Breadth First Search >>>>>>>>>>\n");
	for (int i = 0; i < vertex; i++)
	{
		printf("bfs<%d> :", i);
		bfs(g, i);
		printf("\n");

		for (int j = 0; j < vertex; j++) 
			visited[j] = FALSE;
	}
}


void addq(int v)
{
	queuePointer temp;
	temp = malloc(sizeof(*temp));
	temp->vertex = v;
	temp->link = NULL;

	if (front)
		rear->link = temp;
	else
		front = temp;
	rear = temp;
}

int deleteq()
{
	int v;
	v = front->vertex;
	front = front->link;
	return v;
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

void bfs(graphType* g, int v)
{
	graphPointer w;
	front = rear = NULL; //큐 초기화
	printf("%3d", v);
	visited[v] = TRUE;
	addq(v);
	while (front)
	{
		v = deleteq();
		for (w = g->head[v]; w; w = w->link)
		{
			if (!visited[w->vertex])
			{
				printf("%3d", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
}
