#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftChild;
	treePointer rightChild;
};


treePointer stack[100];
int top = -1;
void push(treePointer ptr); 
treePointer pop();

void iterinorder(treePointer ptr); //LVR


treePointer queue[100];
int front = 0;
int rear = 0;
void addq(treePointer ptr);
treePointer deleteq();

void levelOrder(treePointer ptr);

int main(void)
{
	printf("the length of input string should be less than 80\n");
	printf("input string (postfix expression) from input.txt : ");

	FILE* fp;
	fp = fopen("input.txt", "r");

	char input;
	while (EOF!=fscanf(fp, "%c", &input))
	{
		printf("%c", input);
		
		treePointer temp = NULL ;

		temp = malloc(sizeof(*temp));
		temp->data = input;
		temp->leftChild = NULL;
		temp->rightChild = NULL;

		if (input == "+" || input == "-" || input == "*" || input == "/" || input == "%")
		{
			temp->leftChild = pop();
			temp->rightChild = pop();
			push(temp);
		}

		else
			push(temp);
	}

	treePointer tree = NULL;
	tree = pop();

	printf("\ncreating its binary tree\n");

	printf("\niterative inorder traversal	: ");
	top = -1;
	iterinorder(tree);


	printf("\n스택에 들어가는 데이터의 순서	: ");
	top = -1;
	
	for (;;)
	{
		for (; tree; tree = tree->leftChild)
		{
			printf("%c", tree->data);
			push(tree);
		}

		if (top == -1)
			break;

		tree = pop();

		if (!tree)
			break;
		tree = tree->rightChild;
	}

	printf("\n\nlevel order traversal		: ");
	levelOrder(tree);

	printf("\n");
	return 0;
	
}


void push(treePointer ptr)
{
	stack[++top] = ptr;
}

treePointer pop()
{
	treePointer temp=NULL;
	if (top >= 0)
		temp=stack[top--];

	return temp;
}


void iterinorder(treePointer ptr) //LVR
{
	for (;;)
	{
		for (; ptr; ptr->leftChild)//L
			push(ptr);
		ptr = pop();

		if (!ptr)
			break;

		printf("%c", ptr->data);//V
		ptr = ptr->rightChild;//R
	}
}



void addq(treePointer ptr)
{
	queue[rear++] = ptr;
}

treePointer deleteq()
{
	return queue[front++];
}
void levelOrder(treePointer ptr)
{
	if(!ptr)
		return;

	add(ptr);

	for (;;)
	{
		ptr = deleteq();

		if (ptr) 
		{
			printf("%c ", ptr->data);
			if (ptr->leftChild)
				addq(ptr->leftChild);
			
			if (ptr->rightChild)
				addq(ptr->rightChild);
		}
		else 
			break;
	}
}