#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define ROW_SIZE 10
#define COL_SIZE 10
#define TRUE 1
#define FALSE 0


int maze[ROW_SIZE + 2][COL_SIZE + 2];
int mark[ROW_SIZE + 2][COL_SIZE + 2] = { 0 };

typedef struct
{
	short int vert; //수직
	short int horiz; //수평
}offset;

offset move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

typedef struct
{
	int row;
	int col;
	int dir;
}element;
element stack[MAX_STACK_SIZE];

int top = -1;


//미로에서 사용하는 함수 
element stackempty();
void stackFull();
void push(element item);
element pop();
void path(void);

int EXIT_ROW, EXIT_COL;

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int nRow, nCol;
	fscanf(fp, "%d %d", &nRow, &nCol);
	

	for (int i = 0; i <= nRow+1 ; i++)
	{
		for ( int j = 0; j <= nCol+1 ; j++)
		{
			if (i == 0 || j == 0 || i == nRow + 1 || j == nCol + 1)
				maze[i][j] = 1;
			else
				fscanf(fp, "%d", &maze[i][j]);

			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}

	EXIT_ROW = nRow;
	EXIT_COL = nCol;

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
		return stackempty();
	return stack[top--];
}

element stackempty()
{
	element item;
	item.row = -1;
	return item;
}

void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	element item;
	fprintf(stderr, "stack full\n");

	while (top > -1)
	{
		item = pop();
		printf("%d %d %d\n", item.row, item.col, item.dir);
	}

	exit(EXIT_FAILURE);
}
