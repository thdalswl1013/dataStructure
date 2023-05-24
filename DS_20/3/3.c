#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct element 
{
	int key;
} element;
element a[100];

void mergePass(element initList[], element mergedList[], int n, int s);
void mergeSort(element a[], int n);
void merge(element initList[], element mergedList[], int i, int m, int n);

void printList(element a[], int num);

int main()
{
	FILE* fp;
	fp=fopen("input.txt", "r");

	printf("<<<<< Input List >>>>>\n");

	int keyNum;
	fscanf(fp, "%d", &keyNum);

	for (int i = 1; i <= keyNum; i++)
		fscanf(fp, "%d", &a[i].key);

	printList(a, keyNum);

	printf("\n<<<<< executing iterative merge sort >>>>>\n");
	mergeSort(a, keyNum);

	printf("<<<<< Sorted List >>>>>\n");
	printList(a, keyNum);
	printf("\n");


	return 0;
}

void mergePass(element initList[], element mergedList[], int n, int s)
{
	int i, j;
	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
	if (i + s - 1 < n)
		merge(initList, mergedList, i, i + s - 1, n);
	else
		for (j = i; j <= n; j++)
			mergedList[j] = initList[j];
}

void mergeSort(element a[], int n)
{
	int s = 1;
	int i;
	element extra[MAX];
	while (s < n)
	{
		mergePass(a, extra, n, s);
		printf("segment size : %d\n", s);
		printf("%12s : ", "a");	printList(a, n);
		printf("%12s : ", "temp"); printList(extra, n);
		printf("\n");
		s *= 2;
		mergePass(extra, a, n, s);
		printf("segment size : %d\n", s);
		printf("%12s : ", "temp");	printList(extra, n);
		printf("%12s : ", "a"); printList(a, n);
		printf("\n");
		s *= 2;
	}
}

void merge(element initList[], element mergedList[], int i, int m, int n)
{
	int j, k, t;
	j = m + 1;
	k = i;
	while (i <= m && j <= n)
	{
		if (initList[i].key <= initList[j].key)
			mergedList[k++] = initList[i++];
		else
			mergedList[k++] = initList[j++];
	}
	if (i > m)
	{
		for (t = j; t <= n; t++)
			mergedList[t] = initList[t];
	}
	else
	{
		for (t = i; t <= m; t++)
			mergedList[k + t - i] = initList[t];
	}
}

void printList(element a[], int num)
{
	for (int i = 1; i <= num; i++)
		printf("%3d", a[i].key);
	printf("\n");
}
