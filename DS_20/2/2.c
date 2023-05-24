#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y)=(temp))

typedef struct element
{
    int key;
}element;
element list[100];

int cnt = 0;
int n;

void quickSort(element a[], int left, int right);
void printList(element a[], int n);

int main(void)
{
    int input;
    FILE* fp;
    fp=fopen("input.txt", "r");
    fscanf(fp, "%d", &n);

    printf("<<<<< Input List >>>>>\n");

    int i = 1;
    while (!feof(fp))
    {
        fscanf(fp, "%d", &input);
        list[i].key = input;
        printf("%d ", input);
        i++;
    }

    printf("\n\n");
    printf("execution of quick sort ...\n");
    quickSort(list, 1, n);

    printf("\ncalls of quick sort: %d \n\n", cnt);
    printf("<<<<< Sorted List >>>>>\n");

    for (int i = 1; i <= n; i++)  
        printf("%d ", list[i].key);
    printf("\n");


    return 0;
}


void quickSort(element a[], int left, int right)
{
    int pivot, i, j;
    element temp;

    if (left < right)
    {
        i = left; 
        j = right + 1;

        pivot = a[left].key;
        printf("pivot = %d : ", a[left].key); //add
        cnt++;

        do 
        {
            do 
                i++; 
            while (a[i].key < pivot);

            do 
                j--;
            while (a[j].key > pivot);

            if (i < j) 
                SWAP(a[i], a[j], temp);

        } while (i < j);

        SWAP(a[left], a[j], temp);
        printList(a, n);
        quickSort(a, left, j - 1);
        quickSort(a, j + 1, right);
    }
}

void printList(element a[], int n)
{
    for (int i = 1; i <= n; i++)
        printf("%3d", a[i].key);
    printf("\n");
}