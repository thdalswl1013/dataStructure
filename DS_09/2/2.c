#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUES 3 

#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}


typedef struct {
	int class;
	int grade;
} element;

typedef struct queue* queuePointer;

typedef struct queue {
	element data;
	queuePointer link;
} Node;

queuePointer front[MAX_QUEUES] = { NULL };
queuePointer rear[MAX_QUEUES] = { NULL };

void addq(int i, element item);
element deleteq(int i);
element queueEmpty();


int main(void)
{
	element student;
	int course, i;

	FILE* f;
	fopen_s(&f, "input.txt", "r");

	if (f == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(f, "%d%d%d", &course, &student.class, &student.grade);
	while (!feof(f))
	{
		addq(course, student);
		fscanf_s(f, "%d%d%d", &course, &student.class, &student.grade);
	}

	printf("과목번호  학번  성적\n");

	for (i = 0; i < MAX_QUEUES; i++)
	{
		printf("**********************\n");
		while (front[i])
		{
			student = deleteq(i);
			printf("%8d%6d%6d\n", i, student.class, student.grade);
		}
	}

	fclose(f);
	return 0;
}

void addq(int i, element item)
{
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = NULL;
	if (front[i])
		rear[i]->link = temp;
	else
		front[i] = temp;
	rear[i] = temp;
}

element deleteq(int i)
{
	queuePointer temp = front[i];
	element item;

	if (!temp)
		return queueEmpty();

	item = temp->data;
	front[i] = temp->link;
	free(temp);
	return item;
}

element queueEmpty()
{
	element item;
	item.grade = -1;
	return item;
}
