
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char sentence[100];

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", &sentence);

	int count = 0;

	for (int i = 0; i < strlen(sentence)-1; i++)
	{
		//printf("%c\n", sentence[i]);
		
		if (sentence[i] == 'a' && sentence[i+1] == 'b')
				count += 1;
	}

	printf("�ݺ� Ƚ�� : %d", count);

	return 0;
}
