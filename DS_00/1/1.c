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

	printf("두 개의 정수 입력 ");
	scanf("%d %d", &num1, &num2);

	printf("두 수의 덧셈 결과 : ");
	printf("%d\n", add(num1, num2));

	printf("두 수의 곱셈 결과 : ");
	printf("%d\n", mul(num1, num2));

	return 0;
}

