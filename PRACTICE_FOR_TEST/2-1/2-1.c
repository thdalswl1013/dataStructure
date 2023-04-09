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
	pNum = func1(); // int 크기만큼 동적할당 받아 10을 저장후 정수형 포인터 리턴
	printf("%d\n", *pNum);

	func2(pNum);// pNum이 가리키는 것을 100으로 수정
	printf("%d\n", *pNum);

	func3(&pNum); // pNum이 가리키는 것을 200으로 수정
	printf("%d\n", *pNum);

	pChar = func4(100); // pChar 은 100byte 할당 받은 메모리에 키보드로부터 입력 받은 문자열 저장
	scanf("%s", pChar);
	printf("pChar contents = %s\n");


	free(pNum);
	free(pChar);
	return 0;



	return 0;
}