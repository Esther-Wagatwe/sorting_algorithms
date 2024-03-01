#include "sort.h"

/**
  * swap - function used to swap two integers in an array
  * @n: first integer to swap
  * @m: second integer to swap
  * Return: void
  */
void swap(int *n, int *m)
{
	int temp;

	temp = *n;
	*n = *m;
	*m = temp;
}
