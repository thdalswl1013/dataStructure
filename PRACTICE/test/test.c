
// 파일 불러오기 & 환형큐
char* word = NULL;
char input[80];

while (1)
{
	fgets(input, sizeof(input), fp);
	word = strtok(input, " \n");

	if (!strcmp(word, "add"))
	{
		if (isFull())
			printf("queue full\n");

		else
		{
			rear++;
			rear = rear % MAX_QUEUE_SIZE;
			sscanf(input + strlen(word) + 1, "%d%s", &(queue + rear)->id, (queue + rear)->name);
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
	}
}

int isFull()
{
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}


/*--------------------------------------------------------------------------------------------------*/


// 희소행렬 전치 행렬
void fastTranspose(matrixA a[], matrixA b[])
{
	int rowTerms[10];
	int startingPos[10];
	startingPos[0] = 1;

	// 제일 첫 줄
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	//두번째 줄부터
	if (a[0].value > 0)
	{
		for (int i = 0; i < a[0].col; i++)
			rowTerms[i] = 0;

		for (int i = 1; i <= a[0].value; i++)
			rowTerms[a[i].col]++;

		for (int i = 1; i < a[0].col; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

		// a(i,j) -> b(j,i)
		int j;
		for (int i = 1; i <= a[0].value; i++)
		{
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}
/*--------------------------------------------------------------------------------------------------*/

//미로에서 사용하는 함수 
offset move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

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

void push(element item);
element pop();

element stackempty()
{
	element item;
	item.row = -1;

	return item;
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
/*--------------------------------------------------------------------------------------------------*/
//이퀄 비교할때 문자열 입력받기
gets(person1->name, sizeof(char) * 30);
getchar();
/*--------------------------------------------------------------------------------------------------*/


//후위 연산자 계산
typedef enum
{
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} operation;

int eval(void)
{
	operation token;
	char symbol;
	int op1, op2;
	int n = 0;

	top = -1;
	token = getToken(&symbol, &n);

	while (token != eos)
	{
		if (token == operand)
			push(symbol - '0');

		else
		{
			op2 = pop();
			op1 = pop();
			switch (token)
			{
			case plus:
				push(op1 + op2);
				break;

			case minus, times, divide, mod..

			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

operation getToken(char* symbol, int* n)
{
	*symbol = expression[(*n)++];

	switch (*symbol)
	{
	case '(':
		return lparen;
	case ), +, -, /, *, %, '\0'..

	default:
		return operand;
	}
}
/*--------------------------------------------------------------------------------------------------*/
