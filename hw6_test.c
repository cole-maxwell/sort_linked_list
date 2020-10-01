/*
 *
 * project: hw6
 * name: 
 * user??
 * date: 
 * file: hw6.c
 */


#include "hw6.h"


int randomInteger(int lo, int hi)
{
	srand(time(0));

	return rand() % (hi - lo) + lo;
}




void randArray(int a[], int len)
{
	srand(time(0));
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 100;	/* code */
	}
}


ArrayG arrInteger(int len)
{
	ArrayG arr = {NULL, len, sizeof(int)};
	arr.a = malloc(len*sizeof(int));

	randArray(arr.a,len);

	return arr;
}


void printAGInteger(ArrayG arr)
{
	int *a = (int *) arr.a;

	for (int i = 0; i < arr.size_n; ++i)
		printf("%d\t", a[i]);
	printf("\n");
}

void sortedAGInteger(ArrayG arr)
{
	int *a = (int *) arr.a;

	for (int i = 1; i < arr.size_n; ++i){
		if (a[i]<a[i-1]){
			printf("This integer array is not sorted\n");
			return;
		}
	}

		
	printf("This integer array is sorted\n");
}















void randArrayDouble(double a[], int len)
{
	srand48(time(0));
	for (int i = 0; i < len; ++i)
		a[i] = drand48();	/* code */
}


ArrayG arrDouble(int len)
{
	ArrayG arr = {NULL, len, sizeof(double)};
	arr.a = malloc(len*sizeof(double));

	randArrayDouble(arr.a,len);

	return arr;
}


void printAGDouble(ArrayG arr)
{
	double *a = (double *) arr.a;

	for (int i = 0; i < arr.size_n; ++i)
		printf("%g\t", a[i]);
	printf("\n");
}

void sortedAGDouble(ArrayG arr)
{
	double *a = (double *) arr.a;

	for (int i = 1; i < arr.size_n; ++i){
		if (a[i]<a[i-1]){
			printf("This double array is not sorted\n");
			return;
		}
	}

		
	printf("This double array is sorted\n");
}




/*
	Functions for testing insertSortNodeI()
*/



void printNodeI(NodeI *p)
{

	while (p!=NULL)
	{
		printf("%d\t", p->a);
		p=p->next;
	}
	printf("\n");
}

void sortedNodeI(NodeI *p)
{
	while (p->next!=NULL)
	{
		if(p->a > p->next->a)
			printf("This list is not sorted \n");
		p=p->next;
	}
	printf("This list is sorted\n ");

}
