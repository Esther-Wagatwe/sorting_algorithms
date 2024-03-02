#include "sort.h"

/**
*swap_array - function to swap the positions of two elements into an array
*@array: array
*@elem1: array element to swap
*@elem2: array element to swap with
*/
void swap_array(int *array, int elem1, int elem2)
{
	int temp;

	temp = array[elem1];
	array[elem1] = array[elem2];
	array[elem2] = temp;
}


/**
  * shell_sort - function to sort an array using shell sort
  * @array: The array to perfom shell sort on
  * @size: The size of the array
  * Return: void
  */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j = 0;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap &&
					(array[j] < array[j - gap]); j -= gap)
			{
				swap_array(array, j, j - gap);
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
