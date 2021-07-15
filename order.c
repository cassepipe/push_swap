#include <stdbool.h>
#include "order.h"

bool	check_for_some_order(int *array, int nb_items, int min, int *to_rotate)
{
	bool	found_min;
	int		i;

	i = 1;
	*to_rotate = 0;
	if (array[0] == min)
		found_min = true;
	else
		found_min = false;
	while (i < nb_items)
	{
		if (array[i] != min && array[i] < array[i - 1])
			return (false);
		if (!found_min)
		{
			(*to_rotate)++;
			if (array[i] == min)
				found_min = true;
		}
		i++;
	}
	return (true);
}

void	fewest_rotations(int to_rotate, int nb_items)
{
	if ((float)to_rotate <= (float)nb_items / 2.0)
		while (to_rotate--)
			ra();
	else
	{
		to_rotate -= nb_items;
		while (to_rotate++)
			rra();
	}
}

void	print_best_rotation(int to_rotate, int nb_items)
{
	if ((float)to_rotate <= (float)nb_items / 2.0)
		while (to_rotate--)
			ra();
	else
	{
		to_rotate -= nb_items;
		while (to_rotate++)
			rra();
	}
}
