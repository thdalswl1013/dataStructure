#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nodePointer;
typedef struct node
{
    nodePointer llink;
    int data;
    nodePointer rlink;
} node;
nodePointer header = NULL;

void dinsert(nodePointer* node, nodePointer newnode);
void ddelete(nodePointer* node, nodePointer deleted);

int main(void)
{
    FILE* fp;
    fp=fopen("input.txt", "r");
    int d;
    header = (nodePointer)malloc(sizeof(node));
    fscanf(fp, "%d", &d);
    header->llink = header;
    header->rlink = header;
    header->data = d;
    nodePointer point;

    while (!feof(fp))
    {
        point = (nodePointer)malloc(sizeof(node));
        fscanf(fp, "%d", &d);
        point->data = d;
        dinsert(&header, point);
    }
    header = header->rlink;

    nodePointer forward;
    forward = header;
    int i = 0;
    printf("After creating a doubly linked circular list with a head node : \n");
    printf("forward\n");
    do 
    {
        printf("(%p %d %p)\t", forward->llink, forward->data, forward->rlink);
        i++;
        forward = forward->rlink;
        if ((i % 4) == 0)
            printf("\n");
    } 
    while (forward != header);
    printf("\nbackward\n");
    forward = forward->llink;
    do 
    {
        printf("(%p %d %p) ", forward->llink, forward->data, forward->rlink);
        i++;
        forward = forward->llink;
        if ((i % 4) == 0)
            printf("\n");
    } 
    while (forward != header);
    printf("(%p %d %p) ", forward->llink, forward->data, forward->rlink);


    printf("\nAfter deleting numbers less than and equal to 50 : \n");
    printf("forward\n");

    for (int i = 0; i < 20; i++)
    {
        if (forward->data <= 50)
        {
            ddelete(&header, forward);
            forward = forward->rlink;
        }
        else
        {
            forward = forward->rlink;
        }
    }
    forward = header;

    i = 0;
    do 
    {
        printf("(%p %d %p)\t", forward->llink, forward->data, forward->rlink);
        i++;
        forward = forward->rlink;
        if ((i % 4) == 0)
            printf("\n");
    } 
    while (forward != header);

    printf("backward\n");
    forward = forward->llink;
    i = 0;
    do 
    {
        printf("(%p %d %p) ", forward->llink, forward->data, forward->rlink);
        i++;
        forward = forward->llink;
        if ((i % 4) == 0)
            printf("\n");
    } 
    while (forward != header);
    printf("(%p %d %p) ", forward->llink, forward->data, forward->rlink);
    return 0;
}

void dinsert(nodePointer* node, nodePointer newnode)
{
    newnode->llink = *node;
    newnode->rlink = (*node)->rlink;
    (*node)->rlink->llink = newnode;
    (*node)->rlink = newnode;
    (*node) = newnode;
}

void ddelete(nodePointer* node, nodePointer deleted)
{
    if (*node == deleted)
    {
        (*node) = deleted->rlink;
        deleted->llink->rlink = deleted->rlink;
        deleted->rlink->llink = deleted->llink;
    }
    else
    {
        deleted->llink->rlink = deleted->rlink;
        deleted->rlink->llink = deleted->llink;
    }
}