#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check(char aeiou) // ������ �빮�ڷ� ��ȯ�ϴ� �Լ�
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

	printf("���ڿ� �Է� : ");
	gets_s(text, sizeof(text));

	printf("������ �빮�ڷ� ��ȯ ��� : ");

	while (*p != NULL)
	{
		if (check(*p))
			*p = toupper(*p);
		p++;
	}

	printf("%s", text);

}
