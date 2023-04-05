#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) if (!(p = malloc(sizeof(s)))) { \
						fprintf(stderr, "Insufficient memory\n"); \
						exit(1); }
#define COMPARE(a, b) (a < b ? -1 : a == b ? 0 : 1)

typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef; //계수
	int exp; //지수
	polyPointer link;
}polyNode;
polyPointer a, b, c;

void insertFront(polyPointer* ptr, int coef, int exp)
{
	polyPointer temp;
	MALLOC(temp, *temp);
	temp->coef = coef;
	temp->exp = exp;
	temp->link = NULL;
	if (*ptr == NULL)
		*ptr = temp;
	else {
		temp->link = *ptr;
		*ptr = temp;
	}
}

polyPointer insertLast(polyPointer* ptr, int coef, int exp)
{
	polyPointer temp;
	MALLOC(temp, *temp);
	temp->coef = coef;
	temp->exp = exp;
	temp->link = NULL;
	if (*ptr == NULL)
		*ptr = temp;
	else {
		polyPointer cur;
		cur = *ptr;
		while ((cur)->link != NULL)
			cur = cur->link;
		cur->link = temp;
	}
}

void padd(polyPointer* a, polyPointer* b, polyPointer* c)
{
	polyPointer Apos = *a;
	polyPointer Bpos = *b;
	int sum;

	while (Apos && Bpos) {// a와 b가 둘 다 1일 때만 진행
		switch ((COMPARE(Apos->exp, Bpos->exp))) {
		case -1: // a < b 차수
			insertLast(c, Bpos->coef, Bpos->exp);
			Bpos = Bpos->link;
			break;
		case 0: // a = b 차수
			sum = Apos->coef + Bpos->coef;
			insertLast(c, sum, Apos->exp);
			Apos = Apos->link;
			Bpos = Bpos->link;
			break;
		case 1: // a > b 차수
			insertLast(c, Apos->coef, Apos->exp);
			Apos = Apos->link;
		}
	}
	for (; Apos; Apos = Apos->link)
		insertLast(c, Apos->coef, Apos->exp);
	for (; Bpos; Bpos = Bpos->link)
		insertLast(c, Bpos->coef, Bpos->exp);

}

void printPoly(polyPointer ptr)
{
	for (; ptr; ptr = ptr->link) {
		if (ptr->coef < 0)
			printf("(%p :  %dx^%d : %p)\n", ptr, ptr->coef, ptr->exp, ptr->link);
		else
			printf("(%p :  +%dx^%d : %p)\n", ptr, ptr->coef, ptr->exp, ptr->link);
	}
}

void erase(polyPointer* ptr)
{
	polyPointer temp;
	while (*ptr) {
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}

int main()
{
	FILE* fa = NULL;
	FILE* fb = NULL;
	int coef, exp;
	char orderA, orderB;
	fopen_s(&fa, "a.txt", "r");
	fopen_s(&fb, "b.txt", "r");

	if (fa == NULL)
		return 0;
	if (fb == NULL)
		return 0;

	fscanf(fa, "%c", &orderA);
	if (orderA == 'a') {
		while (!feof(fa)) {
			fscanf(fa, "%d %d", &coef, &exp);
			insertFront(&a, coef, exp);
		}
	}
	else if (orderA == 'd') {
		while (!feof(fa)) {
			fscanf(fa, "%d %d", &coef, &exp);
			insertLast(&a, coef, exp);
		}
	}

	fscanf(fb, "%c", &orderB);
	if (orderB == 'a') {
		while (!feof(fb)) {
			fscanf(fb, "%d %d", &coef, &exp);
			insertFront(&b, coef, exp);
		}
	}
	else if (orderB == 'd') {
		while (!feof(fb)) {
			fscanf(fb, "%d %d", &coef, &exp);
			insertLast(&b, coef, exp);
		}
	}

	printf("   a :\n");
	printPoly(a);
	puts("");

	printf("   b :\n");
	printPoly(b);
	puts("");

	padd(&a, &b, &c);
	printf("   a + b = c :\n");
	printPoly(c);

	erase(&a);
	erase(&b);
	erase(&c);
}