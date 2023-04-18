#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* make1dArray(int num)
{
	int* arr;
	arr = malloc(sizeof(int)*num);
	
	for (int i = 0; i < num; i++)
		arr[i] = rand() % 100;
	
	return arr;
}


int main(void)
{
	int* ipp;
	int i, num;
	printf("일차원 배열의 수를 입력하세요: ");
	scanf("%d", &num);

	ipp = make1dArray(num);


	for (i = 0; i < num; i++)
	{
		printf("ipp[%2d] = %d ", i, ipp[i]);

		if ((i % 5) == 4)
			printf("\n");
	}

	return 0;
}