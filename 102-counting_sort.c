#include "sort.h"

/**
 * max_elem - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max_elem(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max, *count_arr, *sorted_arr, i;

	if (array == NULL || size < 2)
		return;

	max = max_elem(array, size);

	count_arr = malloc((max + 1) * sizeof(int));
	if (count_arr == NULL)
		return;
	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
	{
		free(sorted_arr);
		return;
	}

	for (i = 0; i <= max; i++)
		count_arr[i] = 0;
	/* Count the occurrences of each element in the input array */
	for (i = 0; i < (int)size; i++)
		count_arr[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];
	free(sorted_arr);
	free(count_arr);
}
