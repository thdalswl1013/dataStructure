#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y, temp) (temp = x, x = y, y = temp)

typedef struct 
{
	int front;
	int rear;
}QueueType;

typedef struct
{
	int key;
}element;

int digit(element a, int d, int i, int r);
void printList(element a[], int n);
void printQueue(element a[], int link[], int first);
void printlnQueue(element a[], int link[], int front[], int rear[]);
int radixSort(element a[], int link[], int d, int r, int n);

int main()
{
	FILE* fp;
	int d, n, temp;
	int i = 1;
	int link[11];
	int first;
	element sortList[11];

	fp=fopen("input.txt", "r");
	fscanf(fp, "%d %d", &d, &n);

	while(!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		sortList[i++].key = temp;
	}

	printf("input data ---\n");

	for (int i = 1; i <= n; i++)
		printf(" %3d ", sortList[i].key);
	printf("\n");


	first = radixSort(sortList, link, d, 10, n);

	printf("result --- \n");
	printQueue(sortList, link, first);
}

int digit(element a, int d, int i, int r)
{
	int num = a.key;
	int index[100] = { 0, };
	int j = -1;

	while (1)
	{
		index[d - (++j)] = (num % r);
		num /= r;

		if (!num)
			break;
	}
	return index[i];
}

void printList(element a[], int n)
{
	for (int i = 1; i <= n; i++)
		printf(" %3d ", a[i].key);
	printf("\n");
}

void printQueue(element a[], int link[], int first)
{
	while (1)
	{
		printf(" %4d", a[first]);
		if (!link[first])
			break;
		first = link[first];
	}
	printf("\n");
}

void printlnQueue(element a[], int link[], int front[], int rear[])
{
	int array[4][10] = { 0, };
	int j = 0;
	int temp = 0;

	for (int i = 0; i < 10; i++) 
	{
		while (1)
		{
			if (front[i] == 0) 
				break;

			temp = a[front[i]].key;
			array[j++][i] = temp;

			if (front[i] == rear[i])
				break;

			front[i] = link[front[i]];
		}
		j = 0;
	}

	printf("Queue의 내용 ---\n");

	for (int i = 0; i < 10; i++)
		printf(" %4d", i);
	printf("\n");

	for (int i = 3; i > -1; i--) 
	{
		for (int j = 0; j < 10; j++)
		{
			if (array[i][j]) 
				printf(" %4d", array[i][j]);
			
			else
				printf("  ");

		}
		printf("\n");
	}
	printf("--------------------------------------------------\n");
}

int radixSort(element a[], int link[], int d, int r, int n)
{
	int front[10], rear[10];
	int i, bin, current, first, last;
	first = 1;
	for (i = 1; i < n; i++) link[i] = i + 1;
	link[n] = 0;

	for (i = d - 1; i >= 0; i--)
	{
		for (bin = 0; bin < r; bin++) 
			front[bin] = 0;

		for (current = first; current; current = link[current])
		{
			bin = digit(a[current], d - 1, i, r);

			if (front[bin] == 0)
				front[bin] = current;
			else
				link[rear[bin]] = current;

			rear[bin] = current;
		}

		for (bin = 0; !front[bin]; bin++);

		first = front[bin]; 
		last = rear[bin];

		for (bin++; bin < r; bin++)
		{
			if (front[bin]) 
			{
				link[last] = front[bin];
				last = rear[bin];
			}
		}
		link[last] = 0;

		printf("step %d 자리 ---\n", d - 1 - i);
		printlnQueue(a, link, front, rear);
		printQueue(a, link, first);
	}
	return first;
}