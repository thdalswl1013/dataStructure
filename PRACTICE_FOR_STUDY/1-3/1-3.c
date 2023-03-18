#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct person
{
	int height;
	int weight;
	char name[5];
	float bmi;
};

float bmi_function(int height, int weight)
{
	return (float)weight / pow((float)(height) / 100, 2);
}

int main(void)
{
	struct person student[10];

	FILE* fp;
	fp = fopen("input.txt", "r");

	printf("        키      몸무게     이름        BMI\n");
	printf("=======================================================\n");

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d %d %s", &student[i].height, &student[i].weight, &student[i].name);
		student[i].bmi = bmi_function(student[i].height, student[i].weight);
	}

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d %d %s", &student[i].height, &student[i].weight, &student[i].name);
		printf("%10d %10d %10s %10.2f\n", student[i].height, student[i].weight, student[i].name, student[i].bmi);
	}


	float num;
	printf("\nBMI 값을 쓰시오 : ");
	scanf("%f", &num);


	printf("\nBMI 값이 %.2f에 가장 근접한 사람: \n", (float)num);

	float temp = student[0].bmi;

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d %d %s", &student[i].height, &student[i].weight, student[i].name);

		if (fabs(temp - num) > fabs(student[i].bmi - num))
			temp = student[i].bmi;
	}

	for (int i = 0; i < 10; i++)
	{
		if (temp == student[i].bmi)
			printf("키: %d, 몸무게: %d, 이름: %s, BMI: %.2f\n", student[i].height, student[i].weight, student[i].name, student[i].bmi);
	}


	
	
	
	return 0;
}