#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 20
#define MAX_QUEUE_SIZE 2

typedef struct 
{
    int id;
    char name[MAX_NAME_SIZE];
}element;

element* queue;

int capacity = 2;

int rear = 0;
int front = 0;

void addq(element item);
void queueFull();
element deleteq();
element queueEmpty();
void copy(element* a, element* b, element* c);
void qprint();

int main(void)
{
    FILE* fp;
    fp = fopen("input.txt", "r");


    char input[80];
    char* context;
    char* word = NULL;// push or pop
    element student;

    printf("cilrcular queue operations using dynamic allocated array, where the initial capacity is 2\n");
    printf("add 1 Jung\n");
    printf("delete\n");
    printf("****************************************************************************************\n\n");

    queue = malloc(capacity * sizeof(element));

    while (1)
    {
        fgets(input, MAX_NAME_SIZE, fp);
        word = strtok(input, " ");

        if (!strcmp(word, "add"))
        {
            context = strtok(NULL, " ");
            student.id = atoi(context);
            context = strtok(NULL, " ");
            strcpy(student.name, context);
            addq(student);

        }

        else if (!strcmp(word, "delete\n"))
        {
            if (rear == front)
            {
                printf("Queue empty, cannot delete element.\n");
                break;
            }
            deleteq();
        }

        else if (!strcmp(word, "qprint\n"))
        {
            qprint();
        }

        else if (!strcmp(word, "quit")) 
        {
            printf("End of Program!\n\n");
            break;
        }

        else
        {
            printf("wrong command! try again!\n");
        }

    }

    fclose(fp);
    system("pause");
    return 0;

}

void addq(element item)
{
    rear = (rear + 1) % capacity;
    if (front == rear) 
    {
        queueFull();
        queue[++rear] = item;
        qprint();
    }
    else queue[rear] = item;
}

element deleteq()
{
    element item;
    if (front == rear)
        return queueEmpty();
    front = (front + 1) % capacity;

    return queue[front];
}

void queueFull()
{
    int start;

    element* newQueue;

    newQueue = malloc(2 * capacity * sizeof(*queue));
    start = (front + 1) % capacity;

    if (start < 2)
        copy(queue + start, queue + start + capacity - 1, newQueue);
    else
    {
        copy(queue + start, queue + capacity, newQueue);
        copy(queue, queue + rear + 1, newQueue + capacity - start);
    }

    front = 2 * capacity - 1;
    rear = capacity - 2;
    capacity *= 2;
    free(queue);
    queue = newQueue;

    printf("queue capacity is doubled,\n");
    printf("current queue capacity is %d.\n", capacity);

}

element queueEmpty()
{
    element item;
    item.id = -1;
    return item;
}

void copy(element* a, element* b, element* c)
{
    while (a != b)
        *c++ = *a++;
}

void qprint()
{
    int i, j;

    if (front > rear)
        j = front + 1 + rear + (capacity - front - 1);
    
    else
        j = rear;
    
    for (i = front + 1; i <= j; i++)
        printf("%d, %s", queue[i % capacity].id, queue[i % capacity].name);
    
    printf("\n");
}