#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int data[100];
void inc_insertion_sort(int list[], int first, int last, int gap);
void shell_sort(int list[], int n);

int main(void)
{
    FILE* fp;
    fp=fopen("input.txt", "r");
    printf("list[] data\n");

    int keyNum;
    fscanf(fp, "%d", &keyNum);


    int x;
    for (int i = 0; i < keyNum; i++)
    {
        fscanf(fp, " %d", &x);
        printf("%4d", x);
        data[i] = x;
    }
    printf("\n\n");

    shell_sort(data, keyNum);
}

void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap)
    {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n)
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        if ((gap % 2) == 0) 
            gap++;
        printf("gap is %4d ====>\n", gap); //add

        for (i = 0; i < gap; i++)
            inc_insertion_sort(list, i, n - 1, gap);

        for (int i = 0; i < n; i++) //add
            printf("%4d", list[i]);
        printf("\n\n");
    }
}