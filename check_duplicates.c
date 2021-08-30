#include <unistd.h>
#include <stdlib.h>
#include "check_duplicates.h"

void	error_if_duplicates(struct s_fat_int *array, int nb_items)
{
	int	i;
	int	y;

	i = 0;
	while (i < nb_items)
	{
		y = 0;
		while (y < nb_items)
		{
			if (array[i].num == array[y].num && i != y)
			{
				free(array);
				write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
				exit(EXIT_FAILURE);
			}
			y++;
		}
		i++;
	}
}
