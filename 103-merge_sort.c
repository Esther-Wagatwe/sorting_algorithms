/*
 * File:   103-merge_sort.c
 * Author: Oliver Maketso
 * 	   Esther Wagatwe
 * Description: This file contains the implementation of the Merge sort algorithm
 *              and a demonstration of its usage.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * merge - Merge two sub-arrays of array[]
 * @array: Pointer to the array to be sorted
 * @left: Pointer to the left sub-array
 * @right: Pointer to the right sub-array
 * @size_left: Size of the left sub-array
 * @size_right: Size of the right sub-array
 *
 * This function merges two sub-arrays of array[].
 * It assumes that array[l..m] and array[m+1..r] are sorted.
 */
void merge(int *array, int *left, int *right, size_t size_left, size_t size_right);

/*
 * merge_sort - Sorts an array of integers in ascending order using Merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * This function sorts an array of integers in ascending order using the Merge sort algorithm.
 * It recursively divides the array into halves, sorts them, and then merges the sorted halves.
 * It also allocates memory for temporary arrays.
 */
void merge_sort(int *array, size_t size);

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (size_t i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");

    merge_sort(array, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}

