#include "sort.h"

/**
 * get_max_hld - gets the a largest Knuth Sequence
 * @size: the size of the array
 * Return: the hld size
 */
size_t get_m_hld(size_t sz)
{
	size_t a;

	a = 1;
	while (a < sz)
		a = a * 3 + 1;
	return ((a - 1) / 3);
}

/**
 * shell_sort - shell_sort
 * @array: the integer array to sort
 * @size: the size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t hld, i, j;
	int temp;

	if (!array || !size)
		return;


	for (hld = get_m_hld(size); hld; hld = (hld - 1) / 3)
	{
		for (i = hld; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > hld - 1 && array[j - hld] > hld; j -= hld)
			{
				array[j] = array[j - hld];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
