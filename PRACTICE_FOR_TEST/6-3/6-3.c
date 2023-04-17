#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0


typedef struct
{
	int row;
	int col;
	int dir;
}element;
element stack[MAX_STACK_SIZE];

int top = -1;

typedef struct
{
	int vert;
	int horiz;
}offsets;
offsets move[8] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

int maze[10][10];
int mark[10][10] = { 0 };

int EXIT_ROW, EXIT_COL;


void path(void);
void push(element item);
void stackFull();
element pop();
element stackEmpty();
int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int nRow, nCol;
	fscanf(fp, "%d %d", &nRow, &nCol); //4, 5


	// 초기 미로 모양 만들기 (+ bound)
	for (int i = 0; i <= nRow+1; i++)
	{
		for (int j = 0; j <= nCol+1; j++)
		{
			if (i == 0 || j == 0 || i == nRow + 1 || j == nCol + 1)
				maze[i][j] = 1;

			else
				fscanf(fp, "%d  ", &maze[i][j]);

			printf("%d  ", maze[i][j]);
		}
		printf("\n");
	}

	EXIT_ROW = nRow;
	EXIT_COL = nCol;

	path();

	return 0;
}

void path(void)
{
	// 시작점 (1,1)
	mark[1][1] = 1;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;

	int i;
	int	found = FALSE;
	top = 0;
	int row, col, dir;
	int nextRow, nextCol;
	element position;

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
				found = TRUE;

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


void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
}

void stackFull()///////////////////////////////////////////////
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

element pop()
{
	if (top == -1)
		return stackEmpty();

	return stack[top--];
}

element stackEmpty()/////////////////////////////////////////////////
{
	element item;
	item.row = -1;
	
	return item;
}
