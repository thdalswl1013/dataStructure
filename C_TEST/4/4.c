#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	
	printf("일차원 배열의 수를 입력하세요: ");

	int num;
	scanf_s("%s", &num);

	int* arr;
	arr = (int*)malloc(sizeof(int) * num); //동적할당

	if (arr = NULL)
	{
		fprintf(stderr, "메모리가 부족하여 할당할 수 없습니다\n");
		exit(1);
	}

	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < num; i++)
	{
		printf("%4d\n", arr[i]);
	}


	return 0;
}