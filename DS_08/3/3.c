#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MALLOC(p, s) if((p = malloc(s)) == NULL) { \
						fprintf(stderr, "insufficient memory\n");\
						exit(EXIT_FAILURE); \
						}

typedef struct info* infoPointer;
typedef struct info 
{
	char name[30];
	char belong[50];
	char gender[30];
	infoPointer link;
}info;

infoPointer first = NULL;
infoPointer firstMale = NULL;
infoPointer firstFemale = NULL;

void insert(infoPointer* first, infoPointer x, info data);
void delete(infoPointer* first, infoPointer trail, infoPointer x);
void makeGenderlist();
void printList(infoPointer first);

int main()
{
	FILE* fp;
	fp = fopen("input.txt", "r");
	infoPointer x = NULL;
	info data;

	fscanf(fp, "%s %s %s\n", data.name, data.belong, data.gender);
	insert(&first, NULL, data);
	x = first;


	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s", data.name, data.belong, data.gender);
		insert(&first, x, data);
		x = x->link;
	}

	printf("전체 리스트\n");
	printList(first);
	makeGenderlist();
	printf("남자 리스트\n");
	printList(firstMale);
	puts("");
	printf("여자 리스트\n");
	printList(firstFemale);

	fclose(fp);
	return 0;
}
void insert(infoPointer* first, infoPointer x, info data)
{
	infoPointer temp;
	temp = (info*)malloc(sizeof(*temp));

	strcpy(temp->name, data.name);
	strcpy(temp->belong, data.belong);
	strcpy(temp->gender, data.gender);

	if (*first == NULL) 
	{
		temp->link = NULL;
		*first = temp;
	}

	else
	{
		if (x == NULL)
		{
			temp->link = *first;
			*first = temp;
		}

		else
		{
			temp->link = x->link;
			x->link = temp;
		}
	}
}

void delete(infoPointer* first, infoPointer trail, infoPointer x)
{
	if (trail)
		trail->link = x->link;
	else
		*first = (*first)->link;

	free(x);
}

void makeGenderlist()
{
	infoPointer temp = first;
	infoPointer male = NULL;
	infoPointer female = NULL;
	info data;

	while (temp) 
	{
		strcpy(data.name, temp->name);
		strcpy(data.belong, temp->belong);
		strcpy(data.gender, temp->gender);

		if (strcmp(temp->gender, "남자") == 0) 
		{
			if (firstMale == NULL) 
			{
				insert(&firstMale, NULL, data);
				male = firstMale;
			}
			else 
			{
				insert(&firstFemale, male, data);
				male = male->link;
			}
		}
		else
		{
			if (firstFemale == NULL)
			{
				insert(&firstFemale, NULL, data);
				female = firstFemale;
			}
			else
			{
				insert(&firstFemale, female, data);
				female = female->link;
			}
		}
		temp = temp->link;
	}
}

void printList(infoPointer first)
{

	infoPointer cur = first;
	int cnt = 1;
	while (cur != NULL)  
	{
		printf("(%8p, %6s, %10s, %5s, %8p) ", cur, cur->name, cur->belong, cur->gender, cur->link);
		cur = cur->link;

		if (cnt % 2 == 0)
			puts("");
		cnt++;
	}
	puts("");
}
