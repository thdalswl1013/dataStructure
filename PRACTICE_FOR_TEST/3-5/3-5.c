#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DEGREE 101
#define MAX_TERMS 100

typedef struct
{
	int degree; // ����  
	float coef[MAX_DEGREE]; //���
}polynomial;

typedef struct
{
	float coef;
	int expon;
}term;
term terms[MAX_TERMS];