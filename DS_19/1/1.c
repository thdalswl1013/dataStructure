#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTCIES 7
#define INF 	999	 

int weight[MAX_VERTCIES][MAX_VERTCIES]; //input.txt
int distance[MAX_VERTCIES]; 
int found[MAX_VERTCIES]; 
int path[MAX_VERTCIES];

void shortest_path(int v, int cost[][MAX_VERTCIES], int distance[], int n, int found[]);
int choose(int distance[], int n, int found[]);
void print_path(int start, int end);

void main()
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int numOfVertex, numOfEdge;
	fscanf(fp, "%d %d", &numOfVertex, &numOfEdge);

	int i, row, col, val;
	int start;

	for (row = 0; row < numOfVertex; row++)
		for (col = 0; col < numOfVertex; col++)
		{
			if (row == col)
				weight[row][col] = 0;
			else 
				weight[row][col] = INF;
		}


	for (i = 0; i < numOfEdge; i++)
	{
		fscanf(fp, "%d%d%d", &row, &col, &val);
		weight[row][col] = val;
		weight[col][row] = val;
	}

	start = 0; 
	shortest_path(start, weight, distance, numOfVertex, found);

	printf("\n");
	for (i = 0; i < numOfVertex; i++) 
	{
		if (i != start)
		{
			printf("distance[%d-%d]=%-2d   :", start, i, distance[i]);
			print_path(start, i);
			printf("\n");
		}
	}
}




void shortest_path(int v, int cost[][MAX_VERTCIES],	int distance[], int n, int found[]) //13
{
	int i, u, w;
	int j;

	for (i = 0; i < n; i++) 
	{
		found[i] = FALSE;
		distance[i] = cost[v][i];
		path[i] = v; // add
	}

	found[v] = TRUE;  
	distance[v] = 0;

	printf("%d : ", v);
	for (j = 0; j < n; j++)
		printf("%5d", distance[j]);
	printf("\n");

	for (i = 0; i < n - 2; i++)
	{
		u = choose(distance, n, found);
		found[u] = TRUE;

		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w])
				{
					distance[w] = distance[u] + cost[u][w];
					path[w] = u; // add
				}
		printf("%d : ", u);

		for (j = 0; j < n; j++)
			printf("%5d", distance[j]);
		printf("\n");

	}
}
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
void print_path(int start, int end)
{
	int top = -1;
	struct edges 
	{
		int from;
		int to;

	} stack[MAX_VERTCIES];

	while (path[end] != start) 
	{
		stack[top++].from = path[end];
		stack[top].to = end;
		end = path[end];
	}

	stack[top++].from = path[end];
	stack[top].to = end;

	while (top >= 0)
		printf(" <%d->%d> ", stack[top].from, stack[top--].to);

}
