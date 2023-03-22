#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20

typedef struct {
	int id; // unique id
	char name[MAX_NAME_SIZE]; // last name
}element;

element queue[MAX_QUEUE_SIZE];
int rear, front;

int isFull()
{
    return ((rear + 1) % MAX_QUEUE_SIZE == front);
}


int main(void)
{
    element queue[MAX_QUEUE_SIZE];
    char* word = NULL;
    char input[80];

    FILE* fp;
    fp = fopen("input.txt", "r");

    printf("<< Circular queue operations where MAX_QUEUE_SIZE is 3 >>\n");
    printf("add 1 Jung\ndelete\n");
    printf("\n*************************************************\n");

    /*
    add id name // queue�� ������ ����, ť�� full�̸� full �޽����� ����ϰ�, ť ���� �����͸� �̵��ؾ� �� ��� ��data shift���޼����� ����ؾ� ��.
    delete // queue�� ������ ����, empty�� �� �����͸� �����ϸ� Queue empty �޽����� ����ϰ� ������.
    qprint // queue�� ������ ����Ʈ
    quit // ���α׷� ���� ����
    �߸��� ��ɾ� // �޽��� ������ ���
    */

    while (1)
    {
        fgets(input, sizeof(input), fp);
        word = strtok(input, " \n");

        if (!strcmp(word, "add"))
        {
            if (isFull())
            {
                printf("queue is full, not added\n");
            }
            else
            {
                rear++;
                rear = rear % MAX_QUEUE_SIZE;
                sscanf_s(input + strlen(word) + 1, "%d%s", &(queue + rear)->id, (queue + rear)->name, sizeof(queue->name));
            }

        }

        else if (!strcmp(word, "delete"))
        {
            if (rear == front)
            {
                printf("queue is empty\n");
                break;
            }
            front = (front + 1) % MAX_QUEUE_SIZE;
        }

        else if (!strcmp(word, "qprint"))
        {
            for (int i = front; i != rear; )
            {
                i = (i + 1) % MAX_QUEUE_SIZE;
                printf("%d, %s\n", queue[i].id, queue[i].name);
            }
            printf("\n");
        }

        else if (!strcmp(word, "quit"))
        {
            break;
        }

        else
        {
            printf("wrong command! try again!\n");
        }
    }

    fclose(fp);

    return 0;


}