#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;

	printf("일차원 배열의 수를 입력하세요: ");
	scanf("%d", &num);

	int* arr = malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 100;
		printf("%4d", arr[i]);
	}

	//오름차순
	printf("\n\n오름차순 정렬 결과\n");

	int temp = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
		printf("%4d", arr[i]);


	//내림차순
	printf("\n\n내림차순 정렬 결과\n");

	temp = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
		printf("%4d", arr[i]);

	printf("\n");
	return 0;
}