#include "betty.h"

void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void cocktail_sort_list(listint_t **list);
listint_t *create_node(int n);
void insert_node(listint_t **list, int n);
void print_list(listint_t *list);

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
if (a->prev)
a->prev->next = b;
else
*list = b;
if (b->next)
b->next->prev = a;

a->next = b->next;
b->prev = a->prev;

b->next = a;
a->prev = b;

listint_t *current = *list;
while (current)
{
printf("%d", current->n);
if (current->next)
printf(" <-> ");
current = current->next;
}
printf("\n");
}

void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *start = *list;
listint_t *end = NULL;

while (swapped)
{
swapped = 0;
listint_t *current = start;
while (current && current->next != end)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
swapped = 1;
}
else
{
current = current->next;
}
}
if (!swapped)
break;
end = current;
while (current && current->prev != start)
{
if (current->n < current->prev->n)
{
swap_nodes(list, current->prev, current);
swapped = 1;
}
else
{
current = current->prev;
}
}
start = current;
}
}

listint_t *create_node(int n)
{
listint_t *new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
{
fprintf(stderr, "Memory allocation failed\n");
exit(EXIT_FAILURE);
}
new_node->n = n;
new_node->prev = NULL;
new_node->next = NULL;
return new_node;
}

void insert_node(listint_t **list, int n)
{
listint_t *new_node = create_node(n);
if (*list == NULL)
{
*list = new_node;
}
else
{
listint_t *current = *list;
while (current->next != NULL)
{
current = current->next;
}
current->next = new_node;
new_node->prev = current;
}
}

void print_list(listint_t *list)
{
while (list)
{
printf("%d", list->n);
if (list->next)
printf(" <-> ");
list = list->next;
}
printf("\n");
}

int main()
{
listint_t *list = NULL;
insert_node(&list, 3);
insert_node(&list, 5);
insert_node(&list, 1);
insert_node(&list, 4);
insert_node(&list, 2);
printf("Original list: ");
print_list(list);
cocktail_sort_list(&list);
printf("Sorted list: ");
print_list(list);
return 0;
}

