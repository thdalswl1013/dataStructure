#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 2002

void main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;


	FILE* fp;
	fopen_s(&fp, "output.txt", "w");
	printf("     n    repetitions      time\n");
	fprintf(fp, "     n    repetitions      time\n");

	for (n = 0; n <= 2000; n += step)
	{
		long repetitions = 0;
		clock_t start = clock();

		do
		{
			repetitions++;

			for (i = 0; i < n; i++)
				a[i] = n - i;
			sort(a, n);

		} while (clock() - start < 1000);

		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

		duration /= repetitions;

		printf("%6d   %9d      %f\n", n, repetitions, duration);
		fprintf(fp, "%6d   %9d      %f\n", n, repetitions, duration);

		if (n == 100)
			step = 100;
	}
}