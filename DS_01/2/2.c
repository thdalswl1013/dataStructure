#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 2001

void main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;

	FILE* fp;
	fopen_s(&fp, "output.txt", "w");
	printf("      n        time\n");
	fprintf(fp, "      n        time\n");

	for (n = 0; n <= 2000; n += step)
	{
		for (i = 0; i < n; i++)
			a[i] = n - i;

		start = clock();
		sort(a, n);
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		printf("%6d   %f\n", n, duration);
		fprintf(fp, "%6d       %f\n", n, duration);

		if (n == 100)
			step = 100;
	}

	fclose(fp);
}