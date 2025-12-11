#include "sort.h"

/**
* lomuto partition - partition array using lomuto scheme
*
* @array : pointer to array
*
* @size : size of array
*
* @low : starting index of the partition
*
* @high : ending of the partition
*
* Return: index where pivot ends
*/
static int lomuto_partition(int *array, size_t size, int low, int high)

{
	int pivot = array[high];
	int i = low;
	int j, tmp;

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
* quicksort_recursion - recursively sort arrays using quick sort
*
* @array : pointer to the array
*
* @size : size of the array
*
* @low : start index of partition
*
* @high : end index of partition
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
* quick_sort - sorts an array of integers in ascending order using quick sort
*
* @array : pointer to array
*
* @size : size of the array
*
* Description: uses lomuto partition sceme and prints on every swap
*/
void quick_sort(int *array, size_t size)

{
	if (!array || size < 2)
	return;

	quicksort_recursion(array, size, 0, (int)size - 1);
}
