#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	int count;
	int *ipp;

	printf("일차원 배열의 수를 입력하세요: ");
	scanf("%d", &count);

	ipp = malloc(sizeof(int) * count);

	for (int i = 0; i < 10; i++)
	{
		ipp[i] = rand() % 100;

		printf("ipp[%d] = %2d ", i, ipp[i]);

		if (i % 5 == 4)
			printf("\n");
	}


	return 0;
}