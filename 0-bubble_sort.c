#include "sort.h"

/**
  * bubble_sort - Function that  sorts an array of integers in ascending order
  * @array: Array to perform bubble sort on
  * @size: The size of the array
  *
  * Return: Void
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	bool swapped;

	for(i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j +1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
