#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
	char major[20];
	int  grade;
	char name[10];
	int score;
};

int main(void)
{
	FILE* fp;
	fp = fopen("input1.txt", "r");
	struct person person_4[4];

	/*
	for (int i = 0; i < 4; i++)
	{
		fscanf_s(fp, "%s %d %s %d", person_4[i].major, sizeof(person_4[i].major), &person_4[i].grade, &person_4[i].name, sizeof(person_4[i].name), &person_4[i].score);
		printf("%20s %5d %5s %5d\n", person_4[i].major, person_4[i].grade, person_4[i].name, person_4[i].score);
	}
	*/

	printf("평균 성적: ");
	float average;
	float sum=0;

	for (int i = 0; i < 4; i++)
	{
		fscanf_s(fp, "%s %d %s %d", person_4[i].major, sizeof(person_4[i].major), &person_4[i].grade, &person_4[i].name, sizeof(person_4[i].name), &person_4[i].score);

		sum += person_4[i].score;
	}

	printf("%.2f\n", sum/4);


	printf("성적이 가장 낮은 학생 : ");	
	
	char c1;
	int max = 0;

	for (int i = 0; i < 4; i++)
	{
		fscanf_s(fp, "%s %d %s %d", person_4[i].major, sizeof(person_4[i].major), &person_4[i].grade, &person_4[i].name, sizeof(person_4[i].name), &person_4[i].score);

		fscanf_s(fp, "%c", &c1, 1);
		if (person_4[max].score > person_4[i].score)
			max = i;
	}
	printf("%-20s %10d %10s %10d\n", person_4[max].major, person_4[max].grade, person_4[max].name, person_4[max].score);


	printf("성적이 가장 높은 학생 : ");
	
	char c2;
	int min = 0;

	for (int i = 0; i < 4; i++)
	{
		fscanf_s(fp, "%s %d %s %d", person_4[i].major, sizeof(person_4[i].major), &person_4[i].grade, &person_4[i].name, sizeof(person_4[i].name), &person_4[i].score);

		fscanf_s(fp, "%c", &c2, 1);
		if (person_4[min].score < person_4[i].score)
			min = i;
	}
	printf("%-20s %10d %10s %10d\n", person_4[min].major, person_4[min].grade, person_4[min].name, person_4[min].score);

	

	
	return 0;
}