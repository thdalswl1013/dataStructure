#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20

typedef struct {
	int id; // unique id
	char name[MAX_NAME_SIZE]; // last name
}element;

element queue[MAX_QUEUE_SIZE];
int rear, front;

int main(void)
{
	printf("<< Circulat queue operations where MAX_QUEUE_SIZE is 3 >>\n");
	




	return 0;
}