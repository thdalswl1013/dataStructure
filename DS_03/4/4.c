#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MALLOC(p, s) \
		if(!(p = malloc(s))) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); }
#define MAX_DEGREE 101

typedef struct
{
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial padd(polynomial a, polynomial b) // 두 함수 +
{
	polynomial c;
	int num = 0;
	int i = 0;
	int min = 0;

	if (a.degree < b.degree)
	{
		num = b.degree - a.degree; 
		min = a.degree; // min: 작은 차수 
		c.degree = b.degree; // c.degree: 큰 차수

		for (i = 0; i < num; i++)
			c.coef[i] = b.coef[i];
	}

	else if (a.degree > b.degree)
	{
		num = a.degree - b.degree;
		min = b.degree;// min: 작은 차수 
		c.degree = a.degree; // c.degree: 큰 차수

		for (i = 0; i < num; i++)
			c.coef[i] = a.coef[i];
	}

	else
	{
		c.degree = a.degree;
		min = a.degree;
	}

	for (int j = 0; j <= min; j++)
	{
		c.coef[i] = a.coef[j] + b.coef[i];
		i++;
	}

	return c;
}

void poly_print(char AX[], polynomial a)
{
	printf("%s = ", AX);

	for (int i = 0; i <= a.degree; i++)
	{
		if (i != a.degree)
			printf("%.fx^%d + ", a.coef[i], a.degree - i);
		else
			printf("%.f", a.coef[i]);
	}
	printf("\n");
}
int main(void)
{
	polynomial a;
	polynomial b;
	polynomial c;

	printf("<< C(x) = A(x) + B(x) >>\n");

	printf("Input the degree of items of A(X): ");
	scanf("%d", &a.degree);

	printf("Input the coefficients A(X): ");
	for (int i = 0; i <= a.degree; i++)
		scanf_s("%f", &a.coef[i]);
	
	printf("Input the degree of items of B(X): ");
	scanf("%d", &b.degree);

	printf("Input the coefficients B(X): ");
	for (int i = 0; i <= b.degree; i++)
		scanf_s("%f", &b.coef[i]);

	poly_print("A(X)", a);
	poly_print("B(X)", b);

	c = padd(a, b);
	poly_print("C(X)", c);
	return 0;
}