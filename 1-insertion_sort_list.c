#include "sort.h"

/**
* swap_nodes - swap two adjacent nodes a and b in a doubly linked list
*
* @list : duble pointer to head of list
*
* @a : pointer to node a (immediatly before b)
*
* @b : pointer to node b (immediatly after a)
*
* Description: Swap nodes a and b in place by changing links only
*/
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
listint_t *prev = a->prev;
listint_t *next = b->next;

	if (prev)
	prev->next = b;
	else
	*list = b;

	if (next)
	next->prev = a;

	b->prev = prev;
	b->next = a;
	a->prev = b;
	a->next = next;
}

/**
* insertion_sort_list -  sort a doubly linked list of integers in ascending
* order using the insertion sort algorithm
*
* @list : double pointer to the head of the list
*
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *scan, *next_current;

	if (!list || !*list || !(*list)->next)
	return;

current = (*list)->next;
	while (current)
{
	next_current = current->next;
	scan = current->prev;

	while (scan && current->n < scan->n)
{
	swap_nodes(list, scan, current);
	print_list(*list);
	scan = current->prev;
}

current = next_current;
}
}
