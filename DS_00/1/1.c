#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int num1, int num2)
{
	return num1 + num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}


int main(void)
{
	int num1, num2;

	printf("�� ���� ���� �Է� ");
	scanf("%d %d", &num1, &num2);

	printf("�� ���� ���� ��� : ");
	printf("%d\n", add(num1, num2));

	printf("�� ���� ���� ��� : ");
	printf("%d\n", mul(num1, num2));

	return 0;
}

