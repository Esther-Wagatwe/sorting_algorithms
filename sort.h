#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Comparison direction macros for bitonic sort*/
#define UP 0
#define DOWN 1


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap(int *n, int *m);
listint_t *swap_current(listint_t *current, listint_t **list);
listint_t *create_listint(const int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int partition(int *array, size_t size, int start, int stop);
void lomuto_sort(int *array, size_t size, int start, int stop);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_array(int *array, int elem1, int elem2);
int max_elem(int *array, size_t size);
void counting_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t step,
	char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t step,
	char flow);
void swap_bitonic(int *n, int *m);
void quick_sort_hoare(int *array, size_t size);
void swap_quick_sort(int *item1, int *item2);
#endif
