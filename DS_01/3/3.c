#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct person
{
	int height;
	int weight;
	char name[10];
	float bmi;
};

int main(void) 
{
	int input_bmi;
	printf("BMI ���� ���ÿ� : ");
	scanf("%d", &input_bmi);

	FILE* fp;
	fp = fopen("input.txt", "r");
	struct person all[10];

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d %d %s", &all[i].height, &all[i].weight, all[i].name); 

		all[i].bmi = (float)all[i].weight / pow((float)(all[i].height)/100, 2);
	}

	printf("\nŰ    ������    �̸�      BMI\n");
	printf("====================================\n");

	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d %d %s", &all[i].height, &all[i].weight, all[i].name);
		printf("%d     %d     %s    %.2f\n", all[i].height, all[i].weight, all[i].name, all[i].bmi);
	}


	printf("\nBMI ���� %.2f�� ���� ������ ���: \n", (float)input_bmi);

	float temp = all[0].bmi;

	for (int i = 0; i < 10; i++)
	{
		//printf("%f", temp);
		
		fscanf(fp, "%d %d %s", &all[i].height, &all[i].weight, all[i].name);

		if (fabs(temp - input_bmi) > fabs(all[i].bmi - input_bmi))
			temp = all[i].bmi;
	}

	for (int i = 0; i < 10; i++)
	{
		if (temp==all[i].bmi)
			printf("Ű : %d, ������ : %d, �̸� : %s, BMI : %.2f\n", all[i].height, all[i].weight, all[i].name, all[i].bmi);
	}



	return 0;
}


