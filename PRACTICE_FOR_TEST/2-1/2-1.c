#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* func1() // int ũ�⸸ŭ �����Ҵ� �޾� 10�� ������ ������ ������ ����
{
	int* pNum;
	pNum = malloc(sizeof(int));
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

char* func4(int num) // pChar �� 100byte �Ҵ� ���� �޸𸮿� Ű����κ��� �Է� ���� ���ڿ� ����
{
	char* pChar;
	pChar = (char*)malloc(num);

	printf("\n�Է��� ���ڿ� : ");
	scanf("%s", pChar);

	return pChar;
}


int main(void)
{
	int* pNum;
	char* pChar;
	pNum = func1(); 
	printf("%d\n", *pNum);

	func2(pNum);
	printf("%d\n", *pNum);

	func3(&pNum); 
	printf("%d\n", *pNum);

	pChar = func4(100); 
 	printf("pChar contents = %s\n", pChar);

	free(pNum);
	free(pChar);


	return 0;



	return 0;
}