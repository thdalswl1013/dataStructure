#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num[5];

	printf("숫자를 입력하세요 : ");
	scanf("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]);

	printf("가장 큰 수는 : ");

	int max = num[0];
	for (int i = 0; i < 5; i++)
	{
		if (max < num[i])
			max = num[i];
	}
	printf("%d", max);

	return 0;
}