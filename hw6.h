#ifndef HW6_H
#define HW6_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>   	// for clock_t, clock(), CLOCKS_PER_SEC
#ifndef TEST_FILE
#define TEST_FILE(f,s,s1) 	\
		if (NULL==f){		\
			fprintf(stderr, "%s: can't open %s\n", s,s1);\
			exit(1);}
#endif



typedef struct arrayG
{
	void *a;
	// size_n indicates the number of valid member
	// the size indicates the size of data type
	int size_n, size;
}ArrayG;


int comInt(const void *a, const void *b);
int comDouble(const void *a, const void *b);
void merge_sortAG(ArrayG , int (*com)(const void *, const void *));
void merge_helper(ArrayG a, ArrayG aux, int start, int end);
void merge(ArrayG arr, ArrayG aux, int start, int mid, int end);




/*
	Functions for testing merger_sortAG()
*/

int randomInteger(int,int);
ArrayG arrInteger(int len);
void printAGInteger(ArrayG arr);
void sortedAGInteger(ArrayG arr);

ArrayG arrDouble(int len);
void printAGDouble(ArrayG arr);
void sortedAGDouble(ArrayG arr);



/*
	
	Integer LinkedList
*/


typedef struct nodeI
{
	int a;
	struct nodeI *pre, *next;
}NodeI;




NodeI * newNodeI(ArrayG arr);
NodeI* swim(NodeI *a, NodeI *p);
NodeI* insertSortNodeI(NodeI *a);
/*
	Functions for testing insertSortNodeI()
*/

void printNodeI(NodeI *);
void sortedNodeI(NodeI *);

#endif