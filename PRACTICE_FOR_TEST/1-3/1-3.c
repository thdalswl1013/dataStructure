#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct person
{
	int height;
	int weight;
	char name[10];
	float bmi;
};

struct person people[10];

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");


	int numberofBMI;
	printf("BMI 값을 쓰시오 : ");
	scanf("%d", &numberofBMI);
	
	printf("\n\n");
	printf("     키     몸무게    이름     BMI     \n");
	printf("===============================================\n");

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d %d %s", &people[i].height, &people[i].weight, &people[i].name);
		people[i].bmi = (float)people[i].weight / pow((float)(people[i].height) / 100, 2);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%8d %8d %8s %8.2f\n", people[i].height, people[i].weight, people[i].name, people[i].bmi);
	}


	return 0;
}

