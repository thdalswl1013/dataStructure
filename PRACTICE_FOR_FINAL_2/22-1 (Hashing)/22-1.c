//Linear Probing

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct element // hash: (key, item)
{
	int key;
	char item[10];
	int empty; // 있는지 없는지
}element;
element ht[11];

unsigned int stringToint(char* key);
int HashAdd(element temp, element* ht);

int main(void)
{
	element temp;

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("input strings: ");
	while (!feof(fp))
	{
		fscanf(fp, "%s", &temp.item);
		HashAdd(temp, ht);
		printf("%s  ", temp.item);
	}
	printf("\n\n");

	printf("             item      key\n");
	for (int i = 0; i < 11; i++)
	{
		if (ht[i].empty == 0) // 해시 테이블이 비어있으면
			printf("ht[%2d]:\n", i);
		else
			printf("ht[%2d]: %8s %8d\n", i, ht[i].item, ht[i].key);
	}

}
unsigned int stringToint(char* key)
{
	int number = 0;
	while (*key)
		number += *key++;

	return number;
}

int HashAdd(element temp, element* ht)
{
	int i, value;
	value = i = stringToint(temp.item) % 11;

	while (ht[i].empty == 1) // 해시 테이블이 채워져있으면
	{
		i = (i + 1) % 11; // 옆 칸으로 이동 후 버킷 수 만큼 나눠
	}

	temp.key = stringToint(temp.item);
	temp.empty = 1; // temp 값이 채워져있다고 바꿔준 후
	ht[i] = temp; // ht[i]에 집어넣어

	return 1;
}
