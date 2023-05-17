#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_VERTICES 100 

typedef struct 
{
	int key; 
	int u; 
	int v; 
} element;
#define MAX_ELEMENT 100

typedef struct 
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;
HeapType h;

int parent[MAX_VERTICES];


void init(HeapType h)
{
	h.heap_size = 0;
}

void insert_min_heap(element e)
{
	int i;
	i = ++(h.heap_size);
	while ((i != 1) && (e.key < h.heap[i / 2].key))
	{
		h.heap[i] = h.heap[i / 2];
		i /= 2;
	}
	h.heap[i] = e;
}

void insert_heap_edge(int u, int v, int weight)
{
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	insert_min_heap(e);
}

element delete_min_heap()
{
	int parent, child;
	element item, temp;
	item = h.heap[1];
	temp = h.heap[(h.heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h.heap_size) 
	{
		if ((child < h.heap_size) && (h.heap[child].key > h.heap[child + 1].key)) child++;
		if (temp.key <= h.heap[child].key) break;
		h.heap[parent] = h.heap[child];
		parent = child;
		child *= 2;
	}
	h.heap[parent] = temp;
	return item;
}

int simpleFind(int i)
{
	for (; parent[i] >= 0; i = parent[i])
		;
	return i;
}

void kruskal(int n)
{
	int min_value = 0;
	int edge_accepted = 0;  
	int uset, vset; 
	element e; 
	init(h);

	for (int i = 0; i < n; i++) 
		parent[i] = -1;

	while (edge_accepted < (n - 1)) 
	{
		e = delete_min_heap();
		uset = simpleFind(e.u);
		vset = simpleFind(e.v);

		if (uset != vset) 
		{ 
			if (e.u < e.v) 
				printf("(%d, %d) %d\n", e.u, e.v, e.key);
			else 
				printf("(%d, %d) %d\n", e.v, e.u, e.key);
	
			min_value += e.key;
			edge_accepted++;
			parent[uset] = vset;
		}
	}
	printf("\n");
	printf("최소비용: %d\n", min_value);
}

int main(void)
{
	FILE* fp;
	int edge = 0, vertex = 0;
	int e_u, e_v, weight = 0;
	int findvertex[100] = { 0, };
	fp=fopen("input.txt", "r");
	fscanf(fp, "%d", &edge);

	while (!feof(fp)) 
	{
		fscanf(fp, "%d %d %d", &e_u, &e_v, &weight);
		for (int i = 0; i < 100; i++) 
		{
			if (findvertex[e_u] != 1) findvertex[e_u]++;
			if (findvertex[e_v] != 1) findvertex[e_v]++;
		}
		insert_heap_edge(e_u, e_v, weight);
	}

	for (int i = 0; i < 100; i++)
		if (findvertex[i] == 1)
			vertex++;

	kruskal(vertex);
}
