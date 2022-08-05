#include "main.h"

/**
 * free_tab - free's all the memory allocated in a pointer to pointer
 * @tab: the memory to be freed
 */

void free_tab(char **tab)
{
	int count = 0;

	while (tab[count] != NULL)
	{
		free(tab[count]);
		count++;
	}
	free(tab);
}
