#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* func1()  // int 크기만큼 동적할당 받아 10을 저장후 정수형 포인터 리턴
{
	int* pNum = malloc(sizeof(int));
	*pNum = 10;

	return pNum;
}

void func2(int* pNum) // pNum이 가리키는 것을 100으로 수정
{
	*pNum = 100;
}

void func3(int** pNum) // pNum이 가리키는 것을 200으로 수정
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
