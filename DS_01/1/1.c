#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* func1()
{
	int* p;
	p = (int*)malloc(sizeof(int));
	*p = 10;
	return p;
}

void func2(int* pNum)
{
	*pNum = 100;
}

void func3(int** pNum)
{
	**pNum = 200;
}

char* func4(int mem)
{
	char* pChar;
	pChar = (char*)malloc(mem);


	printf("\n�Է��� ���ڿ� : ");
	scanf_s("%s", pChar, sizeof(pChar) * 100);

	return pChar;
}

int main(void)
{
	int* pNum;
	char* pChar;

	pNum = func1(); // int ũ�⸸ŭ �����Ҵ� �޾� 10�� ������ ������ ������ ����
	printf("%d\n", *pNum);

	func2(pNum);// pNum�� ����Ű�� ���� 100���� ����
	printf("%d\n", *pNum);

	func3(&pNum); // pNum�� ����Ű�� ���� 200���� ����
	printf("%d\n", *pNum);

	pChar = func4(100); // pChar �� 100byte �Ҵ� ���� �޸𸮿� Ű����κ��� �Է� ���� ���ڿ� ����

	printf("pChar contents = %s\n", pChar);


	free(pNum);
	free(pChar);

	return 0;
}