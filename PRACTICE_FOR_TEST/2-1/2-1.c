#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func1()
{

	return 0;
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
	scanf("%s", pChar);
	printf("pChar contents = %s\n");


	free(pNum);
	free(pChar);
	return 0;



	return 0;
}