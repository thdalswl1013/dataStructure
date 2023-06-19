#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	printf("숫자를 입력하세요 : ");

	/*
	int num1, num2, num3, num4, num5;
	scanf("%d %d% %d %d %d", &num1, &num2, &num3, &num4, &num5);
	*/

	int num[5];
	scanf("%d %d %d %d %d", &num[0], & num[1], &num[2], &num[3], &num[4]);

	int max=num[0];

	for (int i = 0; i < 5; i++)
	{
		if (num[i] > max)
			max = num[i];
	}

	printf("가장 큰 수는 : %d", max);

	return 0;
}