#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;

	printf("������ �迭�� ���� �Է��ϼ���: ");
	scanf("%d", &num);

	int* arr = malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 100;
		printf("%4d", arr[i]);
	}

	//��������
	printf("\n\n�������� ���� ���\n");

	int temp = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
		printf("%4d", arr[i]);


	//��������
	printf("\n\n�������� ���� ���\n");

	temp = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
		printf("%4d", arr[i]);

	printf("\n");
	return 0;
}