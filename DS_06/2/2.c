#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_ROW_SIZE 10
#define MAX_COL_SIZE 10

#define TRUE 1
#define FALSE 0

int maze[MAX_ROW_SIZE + 2][MAX_COL_SIZE + 2];
int mark[MAX_ROW_SIZE + 2][MAX_COL_SIZE + 2] = { 0 };


typedef struct
{
	short int vert;
	short int horiz;
} offsets;

offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

void path(void);

typedef struct 
{
	short int row;
	short int col;
	short int dir;
}element;

element stack[MAX_STACK_SIZE];

int top = -1;

void push(element item);
void stackFull();
element pop();
element stackEmpty();

int EXIT_ROW;
int EXIT_COL;

int main(void)
{
	int nRows, nCols;

	FILE* fp;

	fp=fopen("input.txt", "r");

	if (fp == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d %d", &nRows, &nCols);

	int r, c;

	for (r = 0; r <= nRows + 1; r++)
	{
		for (c = 0; c <= nCols + 1; c++)
		{
			if (r == 0 || r == nRows + 1 || c == 0 || c == nCols + 1) //가장자리 1로 둘러싸게하자!
				maze[r][c] = 1;

			else
				fscanf(fp, "%d", &maze[r][c]);
		}
	}

	EXIT_ROW = nRows;
	EXIT_COL = nCols;

	path();

	return 0;
}

void path(void) //3.12
{
	int i, row, col, nextRow, nextCol, dir, found = FALSE;
	element position;
	mark[1][1] = 1;
	top = 0;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;

	while (top > -1 && !found)
	{
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;

		while (dir < 8 && !found)
		{
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;

			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
			{
				found = TRUE;
			}

			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
			{
				mark[nextRow][nextCol] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				push(position);
				row = nextRow;
				col = nextCol;
				dir = 0;
			}

			else ++dir;
		}
	}

	if (found) 
	{
		printf("The path is: \n");
		printf("row col\n");

		for (i = 0; i <= top; i++)
			printf("%2d %5d\n", stack[i].row, stack[i].col);

		printf("%2d %5d\n", row, col);
		printf("%2d %5d\n", EXIT_ROW, EXIT_COL);
	}

	else printf("The maze does not have a path\n");
}


element pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];

}

element stackEmpty()
{
	element item;
	item.row = -1;
	return item;
}

void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1)
	{
		stackFull();
	}
	stack[++top] = item;

}

void stackFull()
{
	element item;

	fprintf(stderr, "stack is full, cannot add element\n");
	printf("current stack elenets: \n");

	while (top > -1)
	{
		item = pop();

		printf("%d %d %d\n", item.row, item.col, item.dir);
	}

	exit(EXIT_FAILURE);
}