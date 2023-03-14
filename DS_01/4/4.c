#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check(char aeiou) // 자음만 대문자로 변환하는 함수
{
	char consonant[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' };
	char vowel[] = { 'a', 'e', 'i', 'o', 'u' };

	for (int i = 0; i < sizeof(vowel); i++)

		if (aeiou == vowel[i])
			return 0;
		else if (aeiou == consonant[i])
			return 1;
}

char text[100], * p;

int main()
{
	p = text;

	printf("문자열 입력 : ");
	gets_s(text, sizeof(text));

	printf("자음만 대문자로 변환 결과 : ");

	while (*p != NULL)
	{
		if (check(*p))
			*p = toupper(*p);
		p++;
	}

	printf("%s", text);

}
