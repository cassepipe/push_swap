#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "check_duplicates.h"

void	error_if_duplicates_in_stack(t_stack *stack)
{
	t_dllnode	*compared;
	t_dllnode	*comparee;
	int			left_to_check;
	int			comparisons;

	compared = stack->top;
	comparee = stack->top->next;
	left_to_check = stack->size;
	while (left_to_check > 0)
	{
		comparisons = --left_to_check;
		while (comparisons > 0)
		{
			if (compared->num == comparee->num)
			{
				free_stack(stack);
				write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
				exit(EXIT_FAILURE);
			}
			comparee = comparee->next;
			comparisons--;
		}
		compared = compared->next;
		comparee = compared->next;
	}
}

void	error_if_duplicates_in_fat_array(t_fat_int *array, int nb_items)
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
