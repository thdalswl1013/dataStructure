#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y)=(temp))
#define MAX 100

typedef struct element
{
	int key;
}element;
element a[MAX];

int adjust(element a[], int root, int n);
void heapSort(element a[], int n);

int main()
{
	int num, i;
	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("<<<<< Input List >>>>>\n");
	fscanf(fp, "%d", &num);

	for (i = 1; i <= num; i++)
		fscanf(fp, "%d", &a[i].key);

	for (int i = 1; i <= num; i++)
		printf("%d ", a[i].key);
	printf("\n");

	printf("\n<<<<< executing heap sort >>>>>\n");
	heapSort(a, num);

	printf("\n<<<<< Sorted List >>>>>\n");

	for (int i = 1; i <= num; i++)
		printf("%d ", a[i].key);
	printf("\n");

	return 0;
}

int adjust(element a[], int root, int n)
{
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;

	while (child <= n)
	{
		if ((child < n) && (a[child].key < a[child + 1].key))
			child++;
		if (rootkey > a[child].key)
			break;
		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void heapSort(element a[], int n)
{
	int i, j;
	element temp;
	for (i = n / 2; i > 0; i--)
		adjust(a, i, n);
	printf("after initialization of max heap...\n");

	for (int i = 1; i <= n; i++)
		printf("%d ", a[i].key);
	printf("\n");


	printf("\n");
	for (i = n - 1; i > 0; i--)
	{
		SWAP(a[1], a[i + 1], temp);

		adjust(a, 1, i);
		printf("\nstep %2d: ", n - i);
		printf("Ãâ·Â %2d : ", a[i + 1].key);

		for (j = 1; j <= i; j++)
			printf("%4d", a[j].key);
	}
}



