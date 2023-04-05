#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 3 

#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}


typedef struct {
	int class;
	int grade;
} element;

typedef struct stack* stackPointer;

typedef struct stack {
	element data;
	stackPointer link;
};
stackPointer top[MAX_STACKS] = { NULL };


void push(int i, element item);
element pop(int i);
element stackEmpty();


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
		push(course, student);
		fscanf_s(f, "%d%d%d", &course, &student.class, &student.grade);
	}

	printf("과목번호  학번  성적\n");

	for (i = 0; i < MAX_STACKS; i++)
	{
		printf("**********************\n");
		while (top[i])
		{
			student = pop(i);
			printf("%8d%6d%6d\n", i, student.class, student.grade);
		}
	}

	fclose(f);
	return 0;
}

void push(int i, element item)
{
	stackPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}

element pop(int i)
{
	stackPointer temp = top[i];
	element item;

	if (!temp)
		return stackEmpty();

	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}

element stackEmpty()
{
	element item;
	item.grade = -1;
	return item;
}
