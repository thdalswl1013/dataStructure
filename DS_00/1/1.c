#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}


int main(void)
{
	int num1, num2;

	printf("�� ���� ���� �Է� ");
	scanf("%d %d", &num1, &num2);

	printf("�� ���� ���� ��� : ");
	printf("%d\n", sum(num1, num2));

	printf("�� ���� ���� ��� : ");
	printf("%d\n", mul(num1, num2));

	return 0;
}

