#include "sort.h"

void quick_sort(int *array, size_t size);
int partition(int *array, size_t size, int start, int stop);
void lomuto_sort(int *array, size_t size, int start, int stop);

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
  * quick_sort - function that sorts an array of integers in ascending order
  * using the Quick sort algorithm
  * @array: An array of integers to perform quick sort on.
  * @size: The size of the array.
  *
  * Return: void
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}


/**
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @stop: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int start, int stop)
{
	int pivot, high, low;

	pivot = array[stop];
	for (high = low = start; low < stop; low++)
	{
		if (array[low] < pivot)
		{
			if (high < low)
			{
				swap(&array[low], &array[high]);
				print_array(array, size);
			}
			high++;
		}
	}
	if (array[high] > pivot)
	{
		swap(&array[high], &array[stop]);
		print_array(array, size);
	}
	return (high);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @stop: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int start, int stop)
{
	int pivot_loc;

	if (stop - start > 0)
	{
		pivot_loc = partition(array, size, start, stop);
		lomuto_sort(array, size, start, pivot_loc - 1);
		lomuto_sort(array, size, pivot_loc + 1, stop);
	}
}
