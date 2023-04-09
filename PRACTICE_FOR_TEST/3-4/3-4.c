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
	polynomial c;

	int min = 0;
	int num = 0;

	int i, j;

	////////////////////////////////////////////////
	if (a.degree < b.degree)
	{
		num = b.degree - a.degree;
		min = a.degree;
		c.degree = b.degree;

		for (i = 0; i < num; i++)
			c.coef[i] = b.coef[i];
		
	}
	////////////////////////////////////////////////

	else if (a.degree > b.degree)
	{
		num = a.degree - b.degree;
		min = b.degree;
		c.degree = a.degree;

		for (i = 0; i < num; i++)
			c.coef[i] = a.coef[i];
	}

	else if (a.degree = b.degree)
	{
		c.degree = a.degree;
		min = a.degree;
	}

	for (j = 0; j <= min; j++)
	{
		c.coef[i] = a.coef[j] + b.coef[i];
		i++;
	}

	return c;

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
