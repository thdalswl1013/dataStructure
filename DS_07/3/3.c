#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_NAME_SIZE 30
#define MEMORY_SIZE 10
#define MAX_STACKS 10

typedef struct 
{
    int id;
    char name[MAX_NAME_SIZE];
}element;

element memory[100];
int top[MAX_STACKS];
int boundary[MAX_STACKS];
int n;

void isFull(int i);
element isEmpty(int i);
int numCheck(int i);
void push(int i, element item);
element pop(int i);
void sprint(int n);

FILE* fp;
int main()
{
    fp = fopen("input.txt", "r");

    char* delimiter = " \n";
    char* context;
    char* operation = NULL;

    element student;
    char line[MAX_LEN];
    int temp = 0;

    printf("How many stacks? : ");
    scanf("%d", &n);

    printf(" C language program to implement the Multiple stacks\n");

    printf("add stack_num(0_2) name: add 0 kim\n");
    printf("delete stack_num(0_2): delete 0\n");
    printf("sprint stack_num(0_2): sprint 0\n");

    printf("quit\n");
    printf("****************************************************\n");

    top[0] = -1;
    boundary[0] = -1;

    for (int i = 1; i < n; i++)
        top[i] = boundary[i] = ((MEMORY_SIZE / n) * i - 1);

    boundary[n] = MEMORY_SIZE - 1;

    while (1) 
    {
        if (!(fgets(line, MAX_LEN, fp)))
            break;

        operation = strtok_s(line, delimiter, &context);

        if (strcmp(operation, "add") == 0) 
        {
            sscanf_s(context, "%d %s", &temp, student.name, MAX_NAME_SIZE);
            push(temp, student);
        }

        else if (strcmp(operation, "delete") == 0) 
        {
            sscanf_s(context, "%d", &temp);
            pop(temp);
        }

        else if (strcmp(operation, "sprint") == 0)
        {
            sscanf_s(context, "%d", &temp);
            sprint(temp);
            printf("\n");
        }

        else if (strcmp(operation, "quit") == 0)
        {
            printf("\nProgram end\n\n");
            for (int i = 0; i < n; i++) 
            {
                printf("stack %d : ", i);
                sprint(i);
                printf("\n");
            }
            break;
        }

        else
            printf("Wrong command! try again!!\n");
    }
}

void isFull(int i)
{
    printf("stack %d is full.\n", i);
}

element isEmpty(int i)
{
    printf("stack is empty\n");
}

int numCheck(int i)
{
    if (i < 0 || i > n - 1) 
    {
        printf("stack number error, try again.\n");
        return 1;
    }

    else
        return 0;
}

void push(int i, element item)
{
    if (numCheck(i))
        return;

    else 
    {
        if (top[i] == boundary[i + 1])
            isFull(i);

        else 
        {
            memory[++top[i]] = item;
            printf("%s is pushed in stack No. %d\n", item.name, i);
        }
    }
}

element pop(int i)
{
    if (numCheck(i)) 
        return;

    else 
    {
        if (top[i] == boundary[i])
            return isEmpty(i);

        else 
        {
            printf("%s is popped from stack No. %d\n", memory[top[i]].name, i);
            return memory[top[i]--];
        }
    }
}

void sprint(int n)
{
    if (numCheck(n)) 
        return;

    else 
    {
        printf("\n");

        for (int i = top[n]; i > boundary[n]; i--) 
            printf("%s\n", memory[i].name);
    }
}