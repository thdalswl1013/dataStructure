#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7
#define INF 1000L

int weight[MAX_VERTICES][MAX_VERTICES] = { 0, };
int selected[MAX_VERTICES];
int dist[MAX_VERTICES];

int get_min_vertex(int n) //22
{
	int v, i;
	for (i = 0; i < n; i++) 
	{
		if (!selected[i])
		{
			v = i;
			break;
		}
	}
	for (i = v+1; i < n; i++)
	{
		if (!selected[i] && (dist[i] < dist[v])) 
			v = i;
	}

	return v;
}

void insert(int e_u, int e_v, int weight1) 
{
	weight[e_u][e_v] = weight1;
	weight[e_v][e_u] = weight1;
}

void prim(int s, int n) //23
{
	int i, u, v;

	for (u = 0; u < n; u++) 
	{
		dist[u] = INF;
		selected[u] = FALSE;
	}

	int tempvertex;
	int alldistance = 0;
	int distance;
	tempvertex = get_min_vertex(n);

	dist[s] = 0;

	for (i = 0; i < n; i++) 
	{
		u = get_min_vertex(n);
		selected[u] = TRUE;

		if (dist[u] == INF) 
			return;
		distance = dist[u];

		for (int i = 0; i < n; i++) 
			if (distance == weight[u][i]) 
				tempvertex = i;
		alldistance += distance;

		for (v = 0; v < n; v++)
			if (weight[u][v] != INF)
				if (!selected[v] && weight[u][v] < dist[v])
					dist[v] = weight[u][v];

		printf("선택 vertex : %d, distance : ", u);
		for (int j = 0; j < n; j++) 
		{
			if (dist[j] != INF)
				printf("%4d", dist[j]);
			else
				printf(" INF");
		}

		if (i != 0)
		{
			printf(" 선택 edge : (%d, %d)", tempvertex, u);
			printf(" distance : %d\n",distance);
		}

		else 
			printf("\n");
	}
	printf("최소 비용 : %d\n", alldistance);
}

int main(void)
{
	FILE* fp;
	fp=fopen("input.txt", "r");

	int edge = 0;
	int e_u, e_v;
	int weight1 = 0;
	int vertex = 0;
	int findvertex[100] = { 0, };

	fp=fopen("input.txt", "r");
	fscanf(fp, "%d", &edge);

	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d", &e_u, &e_v, &weight1);
		for (int i = 0; i < 100; i++)
		{
			if (findvertex[e_u] != 1) findvertex[e_u]++;
			if (findvertex[e_v] != 1) findvertex[e_v]++;
		}
		insert(e_u, e_v, weight1);
	}

	for (int i = 0; i < 100; i++)
		if (findvertex[i] == 1)
			vertex++;

	for (int i = 0; i < vertex; i++) 
	{
		for (int j = 0; j < vertex; j++)
		{
			if (i == j) 
				weight[i][j] == 0;

			else if ((i != j) && (weight[i][j] == 0)) 
				weight[i][j] = INF;
		}
	}
	prim(0, vertex);
}