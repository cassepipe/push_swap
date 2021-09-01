#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "check_duplicates.h"

bool	error_if_duplicates_in_stack(t_stack *stack)
{
	t_dllnode	*compared;
	t_dllnode	*comparee;
	int			comparisons;

	compared = stack->top;
	comparee = stack->top->next;
	while (stack->size> 0)
	{
		comparisons = --stack->size;
		while (comparisons > 0)
		{
			if (compared->num == comparee->num)
				return (true);
			comparee = comparee->next;
			comparisons--;
		}
		compared = compared->next;
		comparee = compared->next;
	}
	return (false);
}

void	error_if_duplicates_in_fat_array(struct s_fat_int *array, int nb_items)
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
