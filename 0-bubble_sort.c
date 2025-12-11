#include "sort.h"

/**
* bubble_sort - Sort an array of integers in ascending order
* using the Bubble sorting algorithm
*
* @array : the array to sort
*
* @size : size of the array
*
* Description: Prints the array after each swapoperation
*/
void bubble_sort(int *array, size_t size)

{
size_t i, j;
int swap;
int swapped = 0;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
{
	for (j = 0; j < size - i - 1; j++)
{
	if (array[j] > array[j + 1])
{
	swap = array[j];
	array[j] = array[j + 1];
	array[j + 1] = swap;

	print_array(array, size);
	swapped = 1;
}
}
	if (!swapped)
	break;
}
}
