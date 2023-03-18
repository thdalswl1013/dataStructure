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
	fp = fopen("input.txt", "r");

	struct person person_4[4];

	for (int i = 0; i < 4; i++)
	{
		fscanf(fp, "%s %d %s %d", &person_4[i].major, &person_4[i].grade, &person_4[i].name, &person_4[i].score);
		printf("%-15s %3d %s %d\n", person_4[i].major, person_4[i].grade, person_4[i].name, person_4[i].score);
	}
	printf("\n");

	// 성적 평균
	float sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum += person_4[i].score;
	}
	
	printf("평균 성적: %.2f", sum/4);
	printf("\n\n");

	// 성적이 가장 높은 학생
	int max = person_4[0].score;
	for (int i = 0; i < 4; i++)
	{
		if (max < person_4[i].score)
			max = person_4[i].score;
	}
	int max_i;
	for (int i = 0; i < 4; i++)
	{
		if (max == person_4[i].score)
			max_i = i;
	}

	printf("성적이 가장 높은 학생 : %-15s %3d %s %d\n", person_4[max_i].major, person_4[max_i].grade, person_4[max_i].name, person_4[max_i].score);


	// 성적이 가장 낮은 학생
	int min = person_4[0].score;
	for (int i = 0; i < 4; i++)
	{
		if (min > person_4[i].score)
			min = person_4[i].score;
	}
	int min_i;
	for (int i = 0; i < 4; i++)
	{
		if (min == person_4[i].score)
			min_i = i;
	}

	printf("성적이 가장 낮은 학생 : %-15s %3d %s %d\n", person_4[min_i].major, person_4[min_i].grade, person_4[min_i].name, person_4[min_i].score);

	return 0;
}