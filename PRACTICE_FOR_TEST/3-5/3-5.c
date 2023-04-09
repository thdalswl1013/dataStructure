#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TERMS 100

typedef struct
{
	float coef; // 계수
	int expon; // 차수(지수)
}term;
term terms[MAX_TERMS];

void terms_print(char AX[], term* terms, int start, int item)
{






}

void padd(int a_item, int b_item)
{






}

int main(void)
{
	int a_item, b_item;

	printf("<< D(x) = A(x) + B(x) >>\n");
	printf("Input the number of items of A(x): ");
	scanf("%d", &a_item);
	printf("Input the number of items of B(x): ");
	scanf("%d", &b_item);
	
	printf("\nInput in descending order\n");

	int i = 0, j = 0;

	printf("coefficient and exponent of A(x)=10x^5+8x^3+7(10 5, 8 3, 7 0): ");

	for (i = 0; i < a_item ; i++) //2
	{
		if (i == a_item - 1)
			scanf("%f %d", &terms[i].coef, &terms[i].expon);
		
		else 
			scanf("%f %d, ", &terms[i].coef, &terms[i].expon);
	}

	printf("coefficient and exponent of A(x)=10x^5+8x^2+3(10 5, 8 2, 3 0): ");

	for (i = 0; i < b_item; i++) //3
	{
		if (i == b_item - 1)
			scanf("%f %d", &terms[i].coef, &terms[i].expon);
		else
			scanf("%f %d, ", &terms[i].coef, &terms[i].expon);
	}

	return 0;
}