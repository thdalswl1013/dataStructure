#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType 
{
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct
{
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;


element pop(StackType* s);
void push(StackType* s, element item);
int is_full(StackType* s);
int is_empty(StackType* s);
void init(StackType* s);

void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
} 
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) 
	{
		fprintf(stderr, "error");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) 
	{
		fprintf(stderr, "error");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

int topo_sort(GraphType* g)
{
	int i, u;
	StackType s;
	GraphNode* node;

	int* in_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++) 
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++)
	{
		node = g->adj_list[i]; 

		while (node != NULL)
		{
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	init(&s);
	for (i = 0; i < g->n; i++)
	{
		if (in_degree[i] == 0)
			push(&s, i);
	}

	while (!is_empty(&s)) 
	{
		int w;
		w = pop(&s);
		printf("%d -> ", w);
		node = g->adj_list[w];

		while (node != NULL) 
		{
			u = node->vertex;
			in_degree[u]--; 
			if (in_degree[u] == 0)
				push(&s, u);
			node = node->link;
		}
	}
	printf("\b\b\b    \n");
	free(in_degree);
	return (i == g->n);	
}

int main(void)
{
	GraphType g;

	FILE* fp;
	int num, src, dest;

	fp = fopen("input.txt", "r");

	graph_init(&g);
	fscanf(fp, "%d", &num);

	g.n = num;

	while (fscanf_s(fp, "%d%d", &src, &dest) != EOF)
		insert_edge(&g, src, dest);

	topo_sort(&g);

	return 0;
}


//stack st
void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "stack full\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "stack empty\n");
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}
