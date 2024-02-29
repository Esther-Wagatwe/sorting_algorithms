#include "sort.h"

/**
  * swap - function used to swap values
  * @n: value of index inside an array
  * @m: value of index in an array after n
  *
  * Return: void
  */
void swap(int *n, int *m)
{
	int temp;

	temp = *n;
	*n = *m; 
	*m = temp;
}
