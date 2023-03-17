#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC(p,s)\
		if (!(p = malloc(s))) {\
		fprintf(stderr, "insufficient memory");\
		exit(EXIT_FAILURE);\
		}\

#define MAX_DEGREE 101

typedef struct
{
	int degree;//지수
	float coef[MAX_DEGREE];//계수
}polynomial;

polynomial add(polynomial a, polynomial b)
{
	polynomial c;

	int num = 0;
	int min = 0;
	int i = 0;
	if (a.degree < b.degree) 
	{
		num = b.degree - a.degree;
		min = a.degree; // 작은 차수
		c.degree = b.degree; // 가장 큰 차수

		for (i = 0; i < num; i++)
			c.coef[i] = b.coef[i];
	}

	else if(a.degree > b.degree)
	{
		num = a.degree - b.degree;
		min = b.degree; // 작은 차수
		c.degree = a.degree; // 가장 큰 차수

		for (i = 0; i < num; i++)
			c.coef[i] = a.coef[i];
	}

	else if (a.degree==b.degree)
	{
		c.degree = a.degree;
		num = a.degree;
	}


	for (int j = 0; j <= min; j++)
	{
		c.coef[i] = a.coef[j] + b.coef[i];
		i++;
	}

	return c;

}


void poly_print(char ax[], polynomial a)
{
	printf("%s = ", ax);

	for (int i = 0; i <= a.degree; i++)
	{
		if (i != a.degree)
			printf("%.fx^%d + ", a.coef[i], a.degree - i);
		else //상수부분
			printf("%.f", a.coef[i]);
	}
	printf("\n");
}
int main(void)
{
	polynomial a;
	polynomial b;

	printf("<<C(X) = A(X) + B(X)>>\n");

	printf("INPUT THE DEGREE OF ITEMS OF A(X): ");
	scanf("%d", &a.degree);
	printf("INPUT THE COEFFICIENTS A(X): ");
	for (int i = 0; i <= a.degree; i++)
		scanf("%f", &a.coef[i]);


	printf("INPUT THE DEGREE OF ITEMS OF B(X): ");
	scanf("%d", &b.degree);
	printf("INPUT THE COEFFICIENTS B(X): ");
	for (int i = 0; i <= b.degree; i++)
		scanf("%f", &b.coef[i]);


	poly_print("A(X)", a);
	poly_print("B(X)", b);

	return 0;
}