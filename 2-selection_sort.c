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


/**
  * selection_sort -  function that sorts an array of integers in ascending
  * order using the Selection sort algorithm
  * @array: The array to perform selection sort on
  * @size: The size of the array
  * Return: Void
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_elem;
	size_t n = size;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < n - 1; i++)
	{
		min_elem = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[min_elem])
				min_elem = j;
		}
		if (min_elem != i)
		{
			swap(&array[min_elem], &array[i]);
			print_array(array, n);
		}
	}
}
