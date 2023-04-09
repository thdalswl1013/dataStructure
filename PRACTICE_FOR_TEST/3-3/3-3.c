#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct 
{
	char name[20];
	int age;
	int salary;
}humanBeing;

int humansEqual(humanBeing *person1, humanBeing *person2)
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
	humanBeing *person1, *person2;
	person1 = malloc(sizeof(humanBeing));
	person2 = malloc(sizeof(humanBeing));

	printf("Input person1's name, age, salary: \n");
	gets(person1->name);
	scanf("%d", &person1->age);
	scanf("%d", &person1->salary);
	getchar();

	printf("Input person2's name, age, salary: \n");
	gets(person2->name);
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

// ¿øº»
/*
int humanEqual(humanBeing person1, humanBeing person2)
{
	if (strcmp(person1.name, person2.name))
		return FALSE;
	if (person1.age != person2.age)
		return FALSE;
	if (person1.salary != person2.salary)
		return FALSE;

	return TRUE;
}

int main(void)
{
	humanBeing person1, person2;

	printf("Input person1's name, age, salary: \n");
	gets(person1.name);
	scanf("%d", &person1.age);
	scanf("%d", &person1.salary);
	getchar();

	printf("Input person2's name, age, salary: \n");
	gets(person2.name);
	scanf("%d", &person2.age);
	scanf("%d", &person2.salary);

	if (humansEqual(person1, person2))
		printf("The two humanbeings are the same.\n");
	else
		printf("The two humanbeings are not the same.\n");

	return 0;
}
*/
