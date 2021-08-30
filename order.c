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
		if (array[i + y - 1] > array[i + y])
			return (false);
	if (i < y)
		while (i--)
			ra();
	else
		while (y--)
			rra();
	return (true);
}
