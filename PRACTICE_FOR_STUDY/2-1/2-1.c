#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* func1()  // int ũ�⸸ŭ �����Ҵ� �޾� 10�� ������ ������ ������ ����
{
	int* pNum = malloc(sizeof(int));
	*pNum = 10;

	return pNum;
}

void func2(int* pNum) // pNum�� ����Ű�� ���� 100���� ����
{
	*pNum = 100;
}

void func3(int** pNum) // pNum�� ����Ű�� ���� 200���� ����
{
	**pNum = 200;
}

int main(void)
{
	int* pNum;


	pNum = func1();
	printf("%d\n", *pNum);

	
	func2(pNum);
	printf("%d\n", *pNum);


	func3(&pNum);
	printf("%d\n", *pNum);


	free(pNum);


	return 0;
}
