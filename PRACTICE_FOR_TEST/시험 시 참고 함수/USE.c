
// ���� �ҷ����� & ȯ��ť
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


// ������ ��ġ ���
void fastTranspose(matrixA a[], matrixA b[]) 
{
	int rowTerms[10];
	int startingPos[10];
	startingPos[0] = 1;

	// ���� ù ��
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	//�ι�° �ٺ���
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

//�̷ο��� ����ϴ� �Լ� 
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

//���� ���Ҷ� ���ڿ� �Է¹ޱ�
gets(person1->name, sizeof(char) * 30);
getchar();