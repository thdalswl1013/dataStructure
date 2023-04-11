/*
	배열로 만들어서 계수가 0인 값도 생각하는 방식
	ex) 2x^100 + 1			 -> 배열: 2  0  0  0  0  0  0  0 ... 0  0  0  0  0  1
	ex) x^4+ 10x^3 + 3x^2 +1 -> 배열: 1 10  3  0  1
*/ 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DEGREE 101

typedef struct
{
	int degree; // 차수
	float coef[MAX_DEGREE]; // 계수
}polynomial;


void poly_print(char ax[], polynomial a)
{
	printf("%s = ", ax);

	for (int i = 0; i<=a.degree; i++)
	{
		if (i==a.degree)
			printf("%.f", a.coef[i]);
		else
			printf("%.fx^%d + ", a.coef[i], a.degree-i);
	}
	printf("\n");
}

polynomial padd(polynomial a, polynomial b)
{











}

int main(void)
{
	printf("<< C(x) = A(x) + B(x) >>\n");

	polynomial a, b;
	polynomial c;

	printf("Input the degree of items of A(x): ");
	scanf("%d", &a.degree);

	printf("Input the coefficients A(x): ");
	for (int i=0;i<=a.degree;i++)
		scanf("%f", &a.coef[i]);


	printf("Input the degree of items of B(x): ");
	scanf("%d", &b.degree);

	printf("Input the coefficients B(x): ");
	for (int i = 0; i <= b.degree; i++)
		scanf("%f", &b.coef[i]);

	poly_print("A(x)", a);
	poly_print("B(x)", b);

	c = padd(a, b);
	poly_print("C(x)", c);

	return 0;
}
