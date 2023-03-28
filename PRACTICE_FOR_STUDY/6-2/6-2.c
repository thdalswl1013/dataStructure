#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

typedef struct // stack에 들어갈 값 (row, col, dir)
{
	short int row;
	short int col;
	short int dir;
}element;

typedef struct // 방향에 들어갈 값 ( vert, horiz)
{
	short int vert;
	short int horiz;
} offsets;
offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} }; //시계방향

void path(void);

int main(void) 
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int col_n, row_n;
	fscanf(fp, "%d %d", &col_n, &row_n); // 4, 5
	printf("%d %d", col_n, row_n);

	return 0;
}


/*

void path(void)
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

*/