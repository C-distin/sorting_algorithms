#include "sort.h"
void quicksort_recursion(int array[], int low, int high);
/**
 * quick_sort - sorts an array of integers in ascending order using
 * @array: the list of values to be sorted
 * @size:  size of hte list
*/
void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size - 1);
}

/**
 * swap - swap two values
 * @x: first value
 * @y: second value
 */

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	 *y = tmp;
}

/**
 * quicksort_recursion - apply portion of the quicksort algorithm
 * @array: list to work on
 * @low: start point
 * @high: max at which we can traverse
*/

void quicksort_recursion(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high);

		quicksort_recursion(array, low, pivot_index - 1);
		quicksort_recursion(array, pivot_index + 1, high);
	}
}
/**
 * partition - partitions the array pivot value and returns
 * @array: list for the values
 * @low: starting point
 * @high: -
 * Return: the index
*/
int partition(int array[], int low, int high)
{
	int pivot_value = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return (i);
}
