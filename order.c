#include <stdbool.h>
#include <stdlib.h>
#include "order.h"


bool	check_for_some_order(int *array, int nb_items, int min)
{
	int	i;
	int	y;

	if (array[0] != min && array[0] < array[nb_items - 1])
		return (false);
	i = 0;
	while (array[++i] != min)// && i < nb_items)
		if (array[i - 1] > array[i])
			return (false);
	if (i == nb_items)
		return (true);
	y = 0;
	while (i + ++y < nb_items)
	{
		if (array[i + y - 1] > array[i + y])
			return (false);
	}
	if (i < y)
		while (i--)
			ra();
	else
		while (y--)
			rra();
	return (true);
}

/*static int	*check_order_until_value_or_end(int *array, int *nb_items, int value)*/
/*{*/
/*    int i;*/
/*    i = 1;*/
/*    while (i < *nb_items && array[i] != value)*/
/*    {*/
/*        if (array[i] < array[i - 1])*/
/*                return (NULL);*/
/*        i++;*/
/*    }*/
/*    *nb_items -= i;*/
/*    return &array[i];*/
/*}*/

/*bool	check_for_some_order(int *array, int nb_items, int min)*/
/*{*/
/*    int *min_index;*/
/*    int *min_revindex;*/

/*    if (array[0] != min && array[0] < array[nb_items - 1])*/
/*        return (false);*/
/*    array = check_order_until_value_or_end(array, &nb_items, min);*/
/*    if (!array)*/
/*        return (false);*/
/*    min_index = array;*/
/*    min_revindex = check_order_until_value_or_end(array, &nb_items, min);*/
/*    if (!array)*/
/*        return (false);*/
/*    return (true);*/
/*}*/

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
