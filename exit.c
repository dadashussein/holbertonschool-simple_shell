#include "main.h"

/**
 * free_arr - freeing array.
 * @arr: array for free.
 */

void free_arr(char **arr)
{
	int j = 0;

	if (arr == NULL)
		return;

	while (arr != NULL && arr[j] != NULL)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}
