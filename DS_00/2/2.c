#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char text[30];
	int i, cnt;

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%[^\n]", text);

	cnt = 0;

	for (i = 0; i < strlen(text)-1; i++)
	{
		if (text[i] == 'a' & text[i+1] == 'b')
			cnt++;
	}

	printf("\n�ݺ� Ƚ�� : %d", cnt);

	return 0;
}