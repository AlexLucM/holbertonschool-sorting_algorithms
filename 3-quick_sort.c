#include "sort.h"

/**
* lomuto_partition - partitions array using Lomuto scheme
*
* @array : pointer to array
*
* @size : size of array
*
* @low : starting index of partition
*
* @high : ending index of partition
*
* Return: index where pivot ends
*/
static int lomuto_partition(int *array, size_t size, int low, int high)

{
	int pivot = array[high];
	int i = low, j, tmp;

	for (j = low; j < high; j++)
{
	if (array[j] < pivot)
{
	if (i != j)
{
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}
	i++;
}
}

	if (i != high)
{
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	print_array(array, size);
}

	return (i);
}

/**
* quicksort_recursion - recursively sorts array using quicksort
*
* @array : pointer to array
*
* @size : size of array
*
* @low : starting index
*
* @high : ending index
*/
static void quicksort_recursion(int *array, size_t size, int low, int high)

{
	int pivot_index;

	if (low < high)
{
	pivot_index = lomuto_partition(array, size, low, high);
	quicksort_recursion(array, size, low, pivot_index - 1);
	quicksort_recursion(array, size, pivot_index + 1, high);
}
}

/**
* quick_sort - sorts array of integers in ascending order
* using the Quick sort algorithm (Lomuto partition)
*
* @array : pointer to array
*
* @size : size of array
*/
void quick_sort(int *array, size_t size)

{

	if (!array || size < 2)
	return;

	quicksort_recursion(array, size, 0, (int)size - 1);
}
