#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC(p,s)\
		if (!(p = malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
		}\

#define FALSE 0
#define TRUE 1

typedef struct
{
	char name[30];
	int age;
	int salary;
}humanBeing;

int humansEqual(humanBeing* person1, humanBeing* person2)
{
	if (strcmp(person1->name, person2->name))
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;
	return TRUE;
}

int main(void)
{
	humanBeing* person1;
	humanBeing* person2;

	MALLOC(person1, sizeof(humanBeing));
	MALLOC(person2, sizeof(humanBeing));

	printf("Input Person1's name, age, salary: \n");
	gets(person1->name, sizeof(char) * 30);
	scanf("%d", &person1->age);
	scanf("%d", &person1->salary);
	getchar();

	printf("Input Person2's name, age, salary: \n");
	gets(person1->name, sizeof(char) * 30);
	scanf("%d", &person2->age);
	scanf("%d", &person2->salary);


	if (humansEqual(person1, person2))
		printf("The two humanbeings are the same.\n");
	else
		printf("The two humanbeings are not the same.\n");

	free(person1);
	free(person2);


	return 0;
}