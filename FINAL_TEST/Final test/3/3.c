#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct element* linked;
typedef struct element
{
	char data[4];
	linked link;

};

linked a[100];
linked sorted[100];
linked queuef[12];
linked queuer[12];

void insert(int key, linked temp);
int digit(linked temp, int i);
void radix(int r, int n, int d);

int main(void)
{
	FILE* f;
	fopen_s(&f, "input.txt", "r");
	int n;
	fscanf(f, "%d", &n);
	printf("input data ---\n");
	linked temp;
	for (int i = 0; i < n; i++)
	{
		temp = (linked)malloc(sizeof(*temp));
		fscanf(f, "%s", temp->data);
		printf(" %s ", temp->data);
		a[i] = temp;
	}
	printf("\nstep 1 번째 자리 문자 처리");
	radix(3, 12, 2);
	for (int i = 0; i < 12; i++)
	{
		queuef[i] = NULL;
		queuer[i] = NULL;
		a[i] = sorted[i];
	}
	printf("\n\nstep2 번째 자리 문자 처리");
	radix(3, 12, 1);
	for (int i = 0; i < 12; i++)
	{
		queuef[i] = NULL;
		queuer[i] = NULL;
		a[i] = sorted[i];
	}
	printf("\nstep 3 번째 자리 문자 처리");
	radix(3, 12, 0);
	printf("\nresult ---\n");
	for (int i = 0; i < 12; i++)
	{
		printf(" %s ", sorted[i]->data);
	}
}

void radix(int r, int n, int d)
{
	

	for (int i = 0; i < n; i++)
	{
		int key = digit(a[i], d);
		insert(key, a[i]);
	}
	printf("\n\nQueue 의 내용 ---\n");
	for (int i = 0; i < n; i++)
	{
		printf("\n%d", i);
		if (queuer[i])
		{
			for (linked ptr = queuef[i]; ptr != queuer[i]; ptr = ptr->link)
			{
				printf(" %s", ptr->data);
			}
			printf(" %s", queuer[i]->data);
		}
			

	}
	int index = 0;
	for (int i = 0;i < n;)
	{
		if (queuef[index])
		{
			while (queuef[index] != queuer[index])
			{
				sorted[i++] = queuef[index];
				queuef[index] = queuef[index]->link;
			}
			sorted[i++] = queuef[index++];
		}
		else
			index++;
	}
}

void insert(int key, linked temp)
{
	if (!queuef[key])
	{
		temp->link = NULL;
		queuef[key] = temp;
		queuer[key] = temp;
	}
	else
	{
		queuer[key]->link = temp;
		queuer[key] = temp;
	}
}

/*
int radix(int d, int r, int n)
{
	int i, bin, current, first, last;
	first = 1;
	for (i = 1; i < n; i++) link[i] = i + 1;
	link[n] = 0;

	for (i = d - 1; i >= 0; i--)
	{
		for (bin = 0; bin < r; bin++) front[bin] = 0;
		for (current = first; current; current = link[current])
		{
			bin = digit(a[current], i, r);
			if (front[bin] == 0) front[bin] = current;
			else link[rear[bin]] = current;
			rear[bin] = current;
		}

		for (bin = 0; !front[bin]; bin++);
		first = front[bin]; last = rear[bin];
		for (bin++; bin < r; bin++)
		{
			if (front[bin])
			{
				link[last] = front[bin];
				last = rear[bin];
			}
		}
		link[last] = 0;
		printf("\nQueue 의 내용 ---\n");
		for (int i = 0; i < 12; i++)
		{
			sorted[i] = a[first];
			first = front[first];
			while (front[first] != rear[first])
				first = first[link];
		}

	}
}*/

int digit(linked temp,int i)
{
	int key = *(temp->data + i) - 'a';
	return key;
}

