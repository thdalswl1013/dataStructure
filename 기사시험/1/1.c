#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int arr[2][3] = { 1,2,3,4,5,6 };
	printf("%d ", arr[0][0]);
	printf("%d ", arr[0][1]);
	printf("%d ", arr[0][2]);
	printf("\n");
	printf("%d ", arr[1][0]);
	printf("%d ", arr[1][1]);
	printf("%d ", arr[1][2]);

	int(*p)[3] = NULL;

	return 0;
}