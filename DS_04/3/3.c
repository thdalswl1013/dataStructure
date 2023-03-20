#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC(p, s) \
		if(!(p=malloc(s))){ \
		fprintf(stderr, "insufficient memory"); \
		exit(EXIT_FAILURE);	}

int nfind(char* string, char* pat)
{
	int i, j, start = 0;
	int lasts = strlen(string) - 1;
	int lastp = strlen(pat) - 1;
	int endmatch = lastp;

	for (i = 0; endmatch <= lasts; endmatch++, start++) 
	{
		if (string[endmatch] == pat[lastp])
			for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++);

		if (j == lastp)
			return start;
	}
	return -1;
}

int main(void)
{
	char sentence[50];
	char pattern[20];

	printf("문자열을 입력하세요: ");
	gets(sentence, sizeof(sentence));

	printf("비교할 패턴을 입력하세요: ");
	gets(pattern, sizeof(pattern));

	if (nfind(sentence, pattern) == -1)
		printf("패턴 없음\n");
	else
		printf("문자열 %d번째부터 패턴이 시작됨..\n", nfind(sentence, pattern));

	return 0;
}