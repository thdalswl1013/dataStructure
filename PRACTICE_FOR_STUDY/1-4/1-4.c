#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
	char sentence[100];

	printf("���ڿ� �Է� : ");
	gets(sentence,sizeof(sentence)); 	//scanf("%s", &sentence);



	printf("������ �빮�ڷ� ��ȯ ��� : ");

	for (int i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u')
			sentence[i] = sentence[i];

		else
			sentence[i] = toupper(sentence[i]);
	}

	printf("%s", sentence);

	return 0;
}