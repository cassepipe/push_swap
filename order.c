#include <stdbool.h>
#include "order.h"

bool	check_for_some_order(int *array, int nb_items, int min)
{
	int	i;
	int	y;

	if (array[0] != min && array[0] > array[nb_items - 1])
		return (false);
	i = -1;
	while (array[++i] != min)
		if (array[i + 1] < array[i])
			return (false);
	y = i + 1;
	while (y < nb_items)
	{
		if (array[y] < array[y - 1])
			return (false);
		y++;
	}
	if (i < y)
		while (i--)
			ra();
	else
		while (y--)
			rra();
	return (true);
}

/*void	fewest_rotations(int to_rotate, int nb_items)*/
/*{*/
/*    if ((float)to_rotate <= (float)nb_items / 2.0)*/
/*        while (to_rotate--)*/
/*            ra();*/
/*    else*/
/*    {*/
/*        to_rotate -= nb_items;*/
/*        while (to_rotate++)*/
/*            rra();*/
/*    }*/
/*}*/

/*void	print_best_rotation(int to_rotate, int nb_items)*/
/*{*/
/*    if ((float)to_rotate <= (float)nb_items / 2.0)*/
/*        while (to_rotate--)*/
/*            ra();*/
/*    else*/
/*    {*/
/*        to_rotate -= nb_items;*/
/*        while (to_rotate++)*/
/*            rra();*/
/*    }*/
/*}*/
