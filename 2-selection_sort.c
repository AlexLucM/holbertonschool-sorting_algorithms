#include "sort.h"

/**
* selection_sort - sort an array of integers in ascending order
* using the selection sort algorithm
*
* @array : pointer to the array to sort
*
* @size :  size of the array
*
* Description: prints the array every time two elements are xwapped
*/
void selection_sort(int *array, size_t size)

{
	size_t i, j, min_idx;
	int swap;

	if (!array || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
{
	min_idx = i;

	for (j = i + 1; j < size; j++)
{
	if (array[j] < array[min_idx])
	min_idx = j;
}

	if (min_idx != i)
{
	swap = array[i];
	array[i] = array[min_idx];
	array[min_idx] = swap;
	print_array(array, size);
}
}
}
