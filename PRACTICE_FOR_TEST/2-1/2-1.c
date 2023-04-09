#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* func1() // int 크기만큼 동적할당 받아 10을 저장후 정수형 포인터 리턴
{
	int* pNum;
	pNum = malloc(sizeof(int));
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

char* func4(int num) // pChar 은 100byte 할당 받은 메모리에 키보드로부터 입력 받은 문자열 저장
{
	char* pChar;
	pChar = (char*)malloc(num);

	printf("\n입력할 문자열 : ");
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