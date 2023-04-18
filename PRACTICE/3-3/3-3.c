#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct
{
	char name[30];
	int age;
	int salary;
}employee;


int humansEqual(employee* person1, employee* person2)
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
	employee *person1;
	employee *person2;

	person1 = malloc(sizeof(employee));	
	person2 = malloc(sizeof(employee));


	printf("Input person1's name, age, salary: \n");
	gets(person1->name, sizeof(char) * 30);
	scanf("%d", &person1->age);
	scanf("%d", &person1->salary);

	getchar();

	printf("Input person2's name, age, salary: \n");
	gets(person2->name, sizeof(char) * 30);
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