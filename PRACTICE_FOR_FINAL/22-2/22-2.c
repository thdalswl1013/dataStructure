// Random Probing

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct element
{
	int key;
	int empty;
}element;
element hash_table[11];


int main(void)
{
	element hashTable;

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("Key sequence from file: ");
	while (!feof(fp))
	{
		fscanf(fp, "%d", &hashTable.key);
		printf("%d ", hashTable.key);
	}

	int seed;
	printf("\ninput seed >> ");
	scanf("%d", &seed);

	srand(seed); // �� Ž������ ������ seed�� ����ؾ� ��

	int randNum[8]; // 1~(b-1) ������ ������ �� ���� �����ؾ� ��
	for (int i = 0; i < 8; i++)
	{
		randNum[i] = rand() % 7 + 1;

		for (int j = 1; j < i; j++)
		{
			if (randNum[i] == randNum[j])
				i--;
		}
	}

	for (int i = 1; i < 8; i++)
		printf("randNum[%d] : %d\n", i, randNum[i]);
	printf("\n\n");

	return 0;
}