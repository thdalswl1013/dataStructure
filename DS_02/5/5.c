#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "insertionSort.h"
#define MAX_SIZE 2001

void main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration1, duration2, duration3;

	FILE* fp;
	fopen_s(&fp, "output.txt", "w");

	printf("     n size     역정렬     순정렬    랜덤\n");
	fprintf(fp, "     n size     역정렬     순정렬		랜덤\n");

	for (n = 0; n <= 2000; n += step)
	{
		long repetitions1 = 0;
		clock_t start = clock();

		do
		{
			repetitions1++;

			for (i = 0; i < n; i++)
				a[i] = n - i;
			sort(a, n);
		} while (clock() - start < 1000);

		duration1 = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration1 /= repetitions1;

		long repetitions2 = 0;
		start = clock();

		do
		{
			repetitions2++;

			for (i = 0; i < n; i++)
				a[i] = i;
			sort(a, n);
		} while (clock() - start < 1000);

		duration2 = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration2 /= repetitions2;

		long repetitions3 = 0;
		start = clock();

		do
		{
			repetitions3++;

			for (i = 0; i < n; i++)
				a[i] = rand() % 9;
			sort(a, n);
		} while (clock() - start < 1000);

		duration3 = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration3 /= repetitions3;

		printf("%9d    %f    %f    %f\n", n, duration1, duration2, duration3);
		fprintf(fp, "%9d    %f    %f    %f\n", n, duration1, duration2, duration3);

		if (n == 100)
			step = 100;
	}

}

