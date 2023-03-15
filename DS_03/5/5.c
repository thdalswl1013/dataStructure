#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100


typedef struct 
{ 
	float coef;
	int expon;
}term;
term terms[MAX_TERMS];

int avail = 0;

void attach(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS)
	{
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}

	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void terms_print(char AX[], term* terms, int start, int item)
{
	printf("%s = ", AX);

	for (int i = start; i < item; i++)
	{
		if (terms[i].expon == 0)
			printf("%.0f", terms[i].coef);

		else if (i == item - 1)
			printf("%.0fx^%d", terms[i].coef, terms[i].expon);

		else
			printf("%.0fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("\n");
}

void padd(int itemA, int itemB)
{
	int start1 = 0;
	int start2 = itemA;
	int finish1 = itemA - 1;
	int finish2 = itemA + itemB - 1;

	avail = itemA + itemB;

	while (1) 
	{
		if (start1 == (finish1 + 1))
		{
			while (1) 
			{
				if (start2 == (finish2 + 1))
					break;

				attach(terms[start2].coef, terms[start2].expon);
				start2++;
			}
			break;
		}

		if (start2 == (finish2 + 1))
		{
			while (1) 
			{
				if (start1 == (finish1 + 1))
					break;

				attach(terms[start1].coef, terms[start1].expon);
				start1++;
			}
			break;
		}

		if (terms[start1].expon < terms[start2].expon)
		{
			attach(terms[start2].coef, terms[start2].expon);
			start2++;
		}

		else if (terms[start1].expon > terms[start2].expon)
		{
			attach(terms[start1].coef, terms[start1].expon);
			start1++;
		}

		else
		{
			attach(terms[start1].coef + terms[start2].coef, terms[start1].expon);
			start1++;
			start2++;
		}
	}
}


int main()
{
	int itemA = 0; // ±Ê¿Ã
	int itemB = 0;
	int i = 0, j = 0;

	printf("<< D(x) = A(x) + B(x) >>\n");
	printf("Input the number of items of A(x) : ");
	scanf("%d", &itemA);

	printf("Input the number of items of B(x) : ");
	scanf("%d", &itemB);

	printf("\ninput in descending order\n");
	printf("coefficient and exponent of A(x) = 10x^5+8x^3+7(10 5, 8 3, 7 0) : ");

	for (i = 0; i < itemA; i++)
	{
		if (i == itemA - 1)
			scanf("%f %d", &terms[i].coef, &terms[i].expon);
		else
			scanf("%f %d, ", &terms[i].coef, &terms[i].expon);
	}

	printf("coefficient and exponent of B(x) = 10x^5+8x^2+3(10 5, 8 2, 3 0) : ");

	for (j = 0; j < itemB; j++)
	{
		if (j == itemB - 1)
			scanf("%f %d", &terms[i + j].coef, &terms[i + j].expon);
		else
			scanf("%f %d, ", &terms[i + j].coef, &terms[i + j].expon);
	}
	printf("\n");
	terms_print("A(x)", terms, 0, itemA);
	terms_print("B(x)", terms, itemA, itemA + itemB);

	padd(itemA, itemB);
	terms_print("D(x)", terms, itemA + itemB, avail);
}