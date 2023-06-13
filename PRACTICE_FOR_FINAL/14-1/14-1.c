#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int key; 
}element;
element heap[100];
element  temp;

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int num;

 	while (!feof(fp))
	{
		fscanf(fp, "%d", &num);
		temp.key = num;
		//printf("%d ", temp.key); // 10 40 30 5 12 6 15 9 60

	}






	return 0;
}