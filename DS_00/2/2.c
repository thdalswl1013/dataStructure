#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fp1;
	fp1 = fopen("input1.txt", "r");

	FILE* fp2;
	fp2 = fopen("input2.txt", "r");


	/*1st*/
	int input1;
	int data1[10] = { 0 };

	int i = 0;
	while (!feof(fp1))
	{
		fscanf_s(fp1, "%d", &data1[i++]);
		//printf("%d, ", input1);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%4d, ", data1[i]);
	}
	printf("\n");

	/*2nd*/

	int input2;
	int data2[10] = { 0 };

	i = 0;
	while (!feof(fp2))
	{
		fscanf_s(fp2, "%d", &data2[i++]);
		//printf("%d, ", input2);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%4d, ", data2[i]);
	}

	fclose(fp1);
	fclose(fp2);

	printf("\n");


	int	data3[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		data3[i] = data1[i] + data2[i];
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%4d, ", data3[i]);
	}


	return 0;
}