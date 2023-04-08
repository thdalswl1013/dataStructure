#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp1;
	fp1 = fopen("input1.txt", "r");

	int arr1[10];
	for (int i = 0; i < 2; i++)
	{
		fscanf(fp1, "%d %d %d %d %d", &arr1[0+5*i], &arr1[1 + 5 * i], &arr1[2 + 5 * i], &arr1[3 + 5 * i], &arr1[4 + 5 * i]);
		printf("%5d %5d %5d %5d %5d ", arr1[0 + 5 * i],arr1[1 + 5 * i], arr1[2 + 5 * i], arr1[3 + 5 * i], arr1[4 + 5 * i]);
	}
	printf("\n");

	FILE* fp2;
	fp2 = fopen("input2.txt", "r");

	int arr2[10];
	for (int i = 0; i < 2; i++)
	{
		fscanf(fp2, "%d %d %d %d %d", &arr2[0 + 5 * i], &arr2[1 + 5 * i], &arr2[2 + 5 * i], &arr2[3 + 5 * i], &arr2[4 + 5 * i]);
		printf("%5d %5d %5d %5d %5d ", arr2[0 + 5 * i], arr2[1 + 5 * i], arr2[2 + 5 * i], arr2[3 + 5 * i], arr2[4 + 5 * i]);
	}
	printf("\n");

	for (int i = 0; i < 2; i++)
	{
		printf("%5d %5d %5d %5d %5d ", arr1[0 + 5 * i] + arr2[0 + 5 * i], arr1[1 + 5 * i] + arr2[1 + 5 * i], arr1[2 + 5 * i] + arr2[2 + 5 * i], arr1[3 + 5 * i] + arr2[3 + 5 * i], arr1[4 + 5 * i] + arr2[4 + 5 * i]);
	}

	return 0;
}