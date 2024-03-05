#include "sort.h"

void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t step,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t step,
		char flow);
void swap_bitonic(int *n, int *m);

/**
  * swap_bitonic - function used to swap two integers in an array
  * @n: first integer to swap
  * @m: second integer to swap
  * Return: void
  */
void swap_bitonic(int *n, int *m)
{
	int temp;

	temp = *n;
	*n = *m;
	*m = temp;
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @step: The step size for merging
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t step, char flow)
{
	size_t cut = step / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (step > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", step, size, str);
		print_array(&array[start], step);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, step, flow);

		printf("Result [%lu/%lu] (%s):\n", step, size, str);
		print_array(&array[start], step);
	}
}
/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in the array
 * @step: The step size for merging.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t step,
		char flow)
{
	size_t i, jump = step / 2;

	if (step > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
				(flow == DOWN && array[i] < array[i + jump]))
				swap_bitonic(&array[i], &array[i + jump]);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
  */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
