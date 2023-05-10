#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10 

typedef struct node* graphPointer;
typedef struct node 
{
	int num1;
	int num2;
	graphPointer num1link, num2link;
}node;

graphPointer* g;
graphPointer edges;
graphPointer temp;

int vertex, edge;
int from, to;

int main()
{
	FILE* fp;
	fp=fopen("input.txt", "r");

	if (fp) 
	{
		fscanf(fp, "%d %d", &vertex, &edge);
		g = calloc(vertex, sizeof(graphPointer));
		edges = calloc(edge, sizeof(node));

		for (int i = 0; i < edge; i++)
		{
			fscanf(fp, "%d %d", &from, &to);
			edges[i].num1 = from;
			edges[i].num2 = to;

			for (int j = 0; j < vertex; j++)
			{
				if (j == from && !g[j])
					g[j] = &edges[i];
				if (j == to && !g[j])
					g[j] = &edges[i];

			}
			for (int j = 0; j < i; j++)
			{
				if (edges[j].num1 == from && !edges[j].num1link)
					edges[j].num1link = &edges[i];
				if (edges[j].num2 == from && !edges[j].num2link)
					edges[j].num2link = &edges[i];
				if (edges[j].num1 == to && !edges[j].num1link)
					edges[j].num1link = &edges[i];
				if (edges[j].num2 == to && !edges[j].num2link)
					edges[j].num2link = &edges[i];
			}
		}
	}


	printf("<<<<< edges incident to each vertex >>>>>\n\n");

	printf("간선의 정점 출력 순서 - 입력데이터 순서대로\n");
	for (int i = 0; i < vertex; i++)
	{
		printf("edges incident to vertex %d : ", i);

		for (temp = g[i]; temp;)
		{
			printf("(%d, %d) ", temp->num1, temp->num2);

			if (i == temp->num1)
				temp = temp->num1link;
			else
				temp = temp->num2link;

		}
		printf("\n");
	}
	printf("\n");

	printf("간선의 정점 출력 순서 - 헤더노드 정점이 먼저 오게\n");
	for (int i = 0; i < vertex; i++)
	{
		printf("edges incident to vertex %d : ", i);

		for (temp = g[i]; temp;)
		{
			int x;
			if (i == temp->num1)
				x = temp->num2;
			else
				x = temp->num1;

			printf("(%d, %d) ", i, x);

			if (i == temp->num1)
				temp = temp->num1link;
			else
				temp = temp->num2link;
		}
		printf("\n");
	}
	printf("\n");
}