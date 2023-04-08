#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int plus(int num1, int num2)
{
	return num1 + num2;
}

int multi(int num1, int num2)
{
	return num1 * num2;
}

int main(void)
{
	int num1, num2;
	printf("두개의 정수 입력: ");
	scanf("%d %d", &num1, &num2);
	printf("두 수의 덧셈 결과: %d\n", plus(num1, num2));
	printf("두 수의 곱셈 결과: %d\n", multi(num1, num2));

	return 0;
}
