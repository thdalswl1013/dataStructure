#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num[5];

	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]);

	printf("���� ū ���� : ");

	int max = num[0];
	for (int i = 0; i < 5; i++)
	{
		if (max < num[i])
			max = num[i];
	}
	printf("%d", max);

	return 0;
}