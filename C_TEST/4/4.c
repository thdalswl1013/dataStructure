#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	
	printf("������ �迭�� ���� �Է��ϼ���: ");

	int num;
	scanf_s("%s", &num);

	int* arr;
	arr = (int*)malloc(sizeof(int) * num); //�����Ҵ�

	if (arr = NULL)
	{
		fprintf(stderr, "�޸𸮰� �����Ͽ� �Ҵ��� �� �����ϴ�\n");
		exit(1);
	}

	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < num; i++)
	{
		printf("%4d\n", arr[i]);
	}


	return 0;
}