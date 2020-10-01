/*
 * project:     hw6
 * name:        Cole Maxwell
 * user?        01876872
 * date:        7/2 /2020
 * file:        hw6.c
 */


#include "hw6.h"



// Comparator for comparing two integer references (10 Points)
int comInt(const void *a, const void *b)
{
    int *a1 = (int *) a;
	int *b1 = (int *) b;

	return *a1 - *b1;

}

// Comparator for comparing two double references (10 Points)
int comDouble(const void *a, const void *b)
{
    double *a1 = (double *) a;
	double *b1 = (double *) b;

	return *a1 - *b1;

}

// Merge sorting for ArrayG varible (30 Points)
// If the sorting is not merge sort, there will be no points earned for this function
void merge_sortAG(ArrayG arr, int (*com)(const void *, const void *))
{
	ArrayG aux = {NULL, arr.size_n, arr.size};
	aux.a = malloc(arr.size * arr.size);	
	merge_helper(arr, aux, 0, arr.size_n - 1);
}

// 
void merge_helper(ArrayG arr, ArrayG aux, int start, int end)
{
	if (arr.size == 4)
	{
		int *ax = (int *) aux.a;
		if (start >= end)
			return;
		int mid = start + (end-start) / 2;
		merge_helper(arr, aux, start,mid);
		merge_helper(arr, aux, mid+1, end);
		if(ax[mid + 1] > ax[mid])
			return;
		merge(arr, aux, start, mid, end);
	}
	else
	{
		double *ax = (double *) aux.a;		
		if (start >= end)
			return;
		int mid = start + (end-start) / 2;
		merge_helper(arr, aux, start,mid);
		merge_helper(arr, aux, mid+1, end);
		if(ax[mid + 1] > ax[mid])
			return;
		merge(arr, aux, start, mid, end);
	}
}

void merge(ArrayG arr, ArrayG aux, int start, int mid, int end)
{
	int *a = (int *) arr.a;
	int *ax = (int *) aux.a;
	for (int i = start; i <= end; ++i)
	{
		ax[i] = a[i];
	}
	int i=start, j=mid+1;
	for (int k = start; k <=end; ++k)
	{	
		if(i>mid) 
		{
			a[k] = ax[j++];
			continue;
		}
		if(j>end) 
		{
			a[k] = ax[i++];
			continue;
		}
		a[k] = ax[i] < ax[j] ? ax[i++]: ax[j++];
	}
}


//Create a linkedlist from a ArrayG (20 points)

NodeI * newNodeI(ArrayG arr)
{

	if (arr.size == 4)
	{
		int *a = (int *) arr.a;
		NodeI *node = NULL;
		NodeI *current = NULL;
		for(int i = 0; i < arr.size_n; i++)
		{
			NodeI *item =(NodeI*)malloc(sizeof (NodeI));
			item->a = a[i];
			if (NULL == current)
			{
				current = item;
				current->pre = NULL;
				current->next = NULL;
				node = current;
			}
			else
			{
				current->next = item;
				item->pre = current;
				item->next = NULL;
				current = item;
			}
		}
		return node;
	}
	else
	{
		double *a = (double *) arr.a;
		NodeI *node = NULL;
		NodeI *current = NULL;
		for(int i = 0; i < arr.size_n; i++)
		{
			NodeI *item =(NodeI*)malloc(sizeof (NodeI));
			item->a = a[i];
			if (NULL == current)
			{
				current = item;
				current->pre = NULL;
				current->next = NULL;
				node = current;
			}
			else
			{
				current->next = item;
				item->pre = current;
				item->next = NULL;
				current = item;
			}
		}
		return node;
	}

}





// swim up the vaule of node p up to the linkedlist a until
// the value is bigger or equal to the vaule come before it or
// reaches to null

// swim() is used for insertSortNodeI (15 points)
NodeI * swim(NodeI *a, NodeI *p)
{
	while ((a->next != NULL) && (a->a < a->pre->a))
	{
		p->a = p->next->a;
	}
	return p;	
}



// insertSort the linkedlist a.  (15 points)
// if you do not use insertion sort, then there will be no points earned.
NodeI* insertSortNodeI(NodeI *a)
{
	NodeI *p = NULL;
	NodeI *temp = NULL;
	NodeI *node = NULL;
	while (swim(a, p) != NULL)
	{
		node = swim(a, p);
		temp->a = node->a;
		node->a = p->a;
		p->a = temp->a;
	}
	return node;
}
