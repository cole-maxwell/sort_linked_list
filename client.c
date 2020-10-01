/*
 *
 * project: hw6
 * name: 
 * user??
 * date: 
 * file: driver.c
 */


#include "hw6.h"





ArrayG testArrayG()
{

	int n = randomInteger(10,20);
	printf("length is:%d\n", n);

	ArrayG arrInts = arrInteger(n);
	printAGInteger(arrInts);
	sortedAGInteger(arrInts);

//  Sorting the arrInts using mergeSort
	printf("After mergeSort\n");
	merge_sortAG(arrInts, comInt);
	printAGInteger(arrInts);
	sortedAGInteger(arrInts);


	printf("-------------------------------\n");
	printf("Testing mergeSort for double array:\n\n");
	ArrayG arrDoubles = arrDouble(n);
	printAGDouble(arrDoubles);
	sortedAGDouble(arrDoubles);

//  Sorting the arrDoubles using mergeSort
	printf("After mergeSort\n");
	merge_sortAG(arrDoubles, comDouble);
	printAGDouble(arrDoubles);
	sortedAGDouble(arrDoubles);


	return arrInts;
}


void testNodeI()
{
	printf("Tesing Double-Linked List:\n");
	int n = randomInteger(10,20);
	ArrayG arr = arrInteger(n);

	NodeI *node = newNodeI(arr);
	printNodeI(node);
	node = insertSortNodeI(node);
	printNodeI(node);
    sortedNodeI(node);
}




int main(int argc, char* argv[])
{
  	
	testArrayG();
  	printf("\n\n\n\n");

  	testNodeI();

	return 0;
}
