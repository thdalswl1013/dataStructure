#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num1[10], num2[10];

	FILE* fp1;
	fp1 = fopen("input1.txt", "r");

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp1, "%d", &num1[i]);
		printf("%3d, ", num1[i]);
	}
	printf("\n");



	FILE* fp2;
	fp2 = fopen("input2.txt", "r");

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp2, "%d", &num2[i]);
		printf("%3d, ", num2[i]);
	}
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%3d, ", num1[i] + num2[i]);
	}

	return 0;
}