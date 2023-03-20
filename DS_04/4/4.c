#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC(p, s) \
		if(!(p=malloc(s))){ \
		fprintf(stderr, "insufficient memory"); \
		exit(EXIT_FAILURE);	}


int failure[30];

int pmatch(char* string, char* pat)
{
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	while (i < lens && j < lenp) 
	{
		if (string[i] == pat[j]) 
		{
			i++; 
			j++;
		}
		else if (j == 0) 
			i++;

		else j = failure[j - 1] + 1;
	}

	return ((j == lenp) ? (i - lenp) : -1);
}

void fail(char* pat)
{
	int i, j;
	int n = strlen(pat);

	failure[0] = -1;

	for (j = 1; j < n; j++) 
	{
		i = failure[j - 1];

		while ((pat[j] != pat[i + 1]) && (i >= 0))
			i = failure[i];

		if (pat[j] == pat[i + 1])
			failure[j] = i + 1;

		else failure[j] = -1;
	}
}

int main(void)
{
	char sentence[50];
	char pattern[20];

	printf("문자열을 입력하세요: ");
	gets(sentence, sizeof(sentence));

	printf("비교할 패턴을 입력하세요: ");
	gets(pattern, sizeof(pattern));

	printf("\n");
	printf("pat의 위치 정보 값\n");

	fail(pattern);

	for (int i = 0; i < strlen(pattern); i++)
	{
		printf("failure[%d]=%3d  ", i, failure[i]);

		if (i % 5 == 4)
			printf("\n");
	}

	if (pmatch(sentence, pattern) == -1)
		printf("패턴 없음\n");
	else
		printf("문자열 %d 번째부터 패턴이 시작됨..\n", pmatch(sentence, pattern));



	return 0;
}