#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
	char sentence[100];

	printf("문자열 입력 : ");
	gets(sentence,sizeof(sentence)); 	//scanf("%s", &sentence);



	printf("자음만 대문자로 변환 결과 : ");

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