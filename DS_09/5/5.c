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
polyPointer avail;

polyPointer getNode()
{
	polyPointer node;
	if (avail) {
		node = avail;
		avail = avail->link;
	}
	else
		MALLOC(node, *node);
	return node;
}

void getHead(polyPointer* ptr)
{
	polyPointer head;
	head = getNode();
	head->exp = -1;
	head->link = head;
	*ptr = head;
}

void retNode(polyPointer node)
{ //node를 avail에게 반환
	node->link = avail;
	avail = node;
}

void insertFront(polyPointer* ptr, int coef, int exp)
{
	polyPointer temp;
	temp = getNode();
	temp->coef = coef;
	temp->exp = exp;
	temp->link = NULL;
	if (*ptr == NULL) {
		*ptr = temp;
		temp->link = temp;
	}
	else {
		temp->link = (*ptr)->link;
		(*ptr)->link = temp;
	}
}

void insertLast(polyPointer* ptr, int coef, int exp)
{
	polyPointer temp;
	temp = getNode();
	temp->coef = coef;
	temp->exp = exp;

	if (*ptr == NULL) {
		*ptr = temp;
		temp->link = temp;
	}
	else {
		polyPointer cur = *ptr;
		while (cur->link != *ptr)
			cur = cur->link;
		temp->link = cur->link;
		cur->link = temp;
	}
}

void printPoly(polyPointer ptr)
{
	polyPointer temp;
	if (ptr == NULL)
		return;
	temp = ptr;
	do {
		if (temp->coef < 0)
			printf("(%p :  %dx^%d : %p)\n", temp, temp->coef, temp->exp, temp->link);
		else
			printf("(%p :  +%dx^%d : %p)\n", temp, temp->coef, temp->exp, temp->link);
		temp = temp->link;
	} while (temp != ptr);
}

void printList(polyPointer ptr)
{
	for (; ptr; ptr = ptr->link) {
		if (ptr->coef < 0)
			printf("(%p :  %dx^%d : %p)\n", ptr, ptr->coef, ptr->exp, ptr->link);
		else
			printf("(%p :  +%dx^%d : %p)\n", ptr, ptr->coef, ptr->exp, ptr->link);
	}
}

void cpadd(polyPointer* a, polyPointer* b, polyPointer* c)
{
	polyPointer startA, startB, lastC;
	int sum;
	int done = 0;
	startA = (*a)->link;
	startB = (*b)->link;
	//lastC = c;

	do {// a와 b가 둘 다 1일 때만 진행
		switch ((COMPARE(startA->exp, startB->exp))) {
		case -1: // a < b 차수
			insertLast(c, startB->coef, startB->exp);
			startB = startB->link;
			break;
		case 0: // a = b 차수
			if (startA == *a) done = 1;
			else {
				sum = startA->coef + startB->coef;
				if (sum)
					insertLast(c, sum, startA->exp);
				startA = startA->link;
				startB = startB->link;
			}
			break;
		case 1: // a > b 차수
			insertLast(c, startA->coef, startA->exp);
			startA = startA->link;
		}
	} while (!done);

}

void cerase(polyPointer* ptr)
{
	polyPointer temp;
	if (*ptr) {
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
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

	a = getNode();
	b = getNode();
	getHead(&a);
	getHead(&b);
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

	c = getNode();
	getHead(&c);
	cpadd(&a, &b, &c);
	//getHead(&c);

	printf("        a :\n");
	printPoly(a);
	puts("");

	printf("        b :\n");
	printPoly(b);
	puts("");

	printf("a + b = c :\n");
	printPoly(c);
	puts("");

	cerase(&a);
	cerase(&b);
	cerase(&c);

	printf("    avail :\n");
	printList(avail);
	erase(&avail);

}