#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftchild;
	treePointer rightchild;
};
treePointer stack[80];
treePointer queue[80];

int top = -1;
int front = 0;
int rear = 0;

void levelOrder(treePointer ptr);
void iterinorder(treePointer node);
void printiterInorder(treePointer node);
void insert(char ch);
treePointer createTree(treePointer ptr, char ch);
void push(treePointer ptr);
treePointer pop();
void addq(treePointer ptr);
treePointer deleteq();

int main()
{
	treePointer tree = NULL;
	char ch;
	FILE* fp;
	fp = fopen("input.txt", "r");


	while (1)
	{
		fscanf(fp, "%c", &ch);
		if (feof(fp))
			break;
		insert(ch);
	}

	tree = pop();


	printf("the length of input string should be less than 80\n");
	printf("input string (postfix expresstion) from input.txt : AB/C*D*E+\n");
	printf("creating its binary tree\n\n");

	printf("\niterative inorder traversal		: ");
	top = -1;
	iterinorder(tree);
	printf("\n스택에 들어가는 데이터의 순서		: ");
	top = -1;
	printiterInorder(tree);
	printf("\n\nlevel order traversal			: ");
	levelOrder(tree);
	printf("\n");
}

void push(treePointer ptr)
{
	stack[++top] = ptr;
}

treePointer pop()
{
	treePointer temp = NULL;

	if (top >= 0)
		temp = stack[top--];
	return temp;
}

treePointer createTree(treePointer ptr, char ch)
{
	treePointer temp;
	temp = malloc(sizeof(*temp));
	temp->data = ch;
	temp->leftchild = NULL;
	temp->rightchild = NULL;

	return temp;
}

void insert(char ch)
{
	treePointer temp = NULL;

	if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%') {
		temp = createTree(temp, ch);
		temp->rightchild = pop();
		temp->leftchild = pop();
		push(temp);
	}
	else {
		temp = createTree(temp, ch);
		push(temp);
	}
}

void iterinorder(treePointer node)
{
	for (;;) {
		for (; node; node = node->leftchild) {
			push(node);
		}
		node = pop();
		if (!node) break;
		printf("%c ", node->data);
		node = node->rightchild;
	}
}

void printiterInorder(treePointer node)
{
	for (;;) {
		for (; node; node = node->leftchild) {
			printf("%c ", node->data);
			push(node);
		}
		if (top == -1)
			break;
		node = pop();
		if (!node) break;
		node = node->rightchild;
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
	if (!ptr) return;
	addq(ptr);
	for (;;) {
		ptr = deleteq();
		if (ptr) {
			printf("%c ", ptr->data);
			if (ptr->leftchild) {
				addq(ptr->leftchild);
			}
			if (ptr->rightchild) {
				addq(ptr->rightchild);
			}
		}
		else break;
	}
}
