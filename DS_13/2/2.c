//5-3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct threadedTree* threadedPointer;//18
typedef struct threadedTree 
{
	short int leftThread;
	threadedPointer leftChild;
	char data;
	threadedPointer rightChild;
	short int rightThread;
};

threadedPointer insucc(threadedPointer tree)//21
{
	threadedPointer temp;
	temp = tree->rightChild;

	if (!tree->rightThread)
		while (!temp->leftThread)
			temp = temp->leftChild;

	return temp;
}

void tinorder(threadedPointer tree)//22
{
	threadedPointer temp = tree;
	for(;;)
	{
		printf("%p (%d, %p,   %c,   %d, %p)\n",
			temp, temp->leftThread, temp->leftChild, temp->data, temp->rightThread, temp->rightChild);
		
		temp = insucc(temp);
		if (temp == tree)
			break;
	}
}

threadedPointer createBin(char data, int a, int b);

int main()
{
	threadedPointer root = NULL;
	threadedPointer r, a, b, c, d, e, f, g, h, i;

	r = createBin(NULL, FALSE, FALSE);
	a = createBin('A', FALSE, FALSE);
	b = createBin('B', FALSE, FALSE);
	c = createBin('C', FALSE, FALSE);
	d = createBin('D', FALSE, FALSE);
	e = createBin('E', TRUE, TRUE);
	f = createBin('F', TRUE, TRUE);
	g = createBin('G', TRUE, TRUE);
	h = createBin('H', TRUE, TRUE);
	i = createBin('I', TRUE, TRUE);

	r->leftChild = a; r->rightChild = r;
	a->leftChild = b; a->rightChild = c;
	b->leftChild = d; b->rightChild = e;
	c->leftChild = f; c->rightChild = g;
	d->leftChild = h; d->rightChild = i;
	e->leftChild = b; e->rightChild = a;
	f->leftChild = a; f->rightChild = c;
	g->leftChild = c; g->rightChild = r;
	h->leftChild = r; h->rightChild = d;
	i->leftChild = d; i->rightChild = b;

	root = r;
	tinorder(root);
}



threadedPointer createBin(char data, int a, int b)
{
	threadedPointer temp;
	temp = malloc(sizeof(*temp));

	temp->leftThread = a;
	temp->rightThread = b;
	temp->data = data;
	temp->leftChild = NULL;
	temp->rightChild = NULL;

	return temp;
}
