#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "push_swap.h"

bool are_there_duplicates(struct fat_int *array, int nb_items)
{
	int i;
	int y;

	i = 0;
	while (i < nb_items)
	{
		y = 0;
		while (y < nb_items)
		{
			if (array[i].num == array[y].num && i != y)
			{
				return (true);
			}
			y++;
		}
		i++;
	}
	return (false);
}

bool	check_for_some_order(int *array, int nb_items, int min, int *to_rotate)
{
	bool found_min;
	int i;

	i = 1;
	*to_rotate = 0;
	found_min = array[0] == min ? true : false;
	while (i < nb_items)
	{
		if (array[i] != min && array[i] < array[i-1])
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

struct fat_int *parse_numbers(char **num_strings, int nb_items, int *parse_error)
{
	struct fat_int *array;
	int i;
	int num;

	array = malloc(nb_items * sizeof(struct fat_int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < nb_items && *parse_error == 0)
	{
		num = atoi_error(*num_strings++, parse_error);
		array[i].num = num;
		array[i].offset = i;
		i++;
	}
	return (array);
}

t_stack *create_stack_from_int_array(int *int_array, int nb_items)
{
		t_stack *stack;
		int i;

		stack = new_stack(NULL, 0);
		if (!stack)
			return (NULL);
		i = 0;
		while(i < nb_items)
		{
			if (!stack_append(stack, dll_new_node(int_array[i])))
			{
				free_stack(stack);
				free(int_array);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		return (stack);
}

int	*create_positive_array(struct fat_int *fat_array, int nb_items)
{
	int	*int_array;
	int i;

	int_array = malloc(nb_items * sizeof(int));
	if (!int_array)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < nb_items)
	{
		int_array[fat_array[i].offset] = i;
		i++;
	}
	return (int_array);
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

int 	main(int argc, char **argv)
{
	int	i;
	struct fat_int	*fat_array;
	int	*int_array;
	t_stack	*A;

	argv++;
	argc--;
	fat_array = parse_numbers(argv, argc, &i);
	if (!fat_array || are_there_duplicates(fat_array, argc) || i)
	{
			free(fat_array);
			write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
			return (EXIT_FAILURE);
	}
	fat_array = fat_int_radix_sort(fat_array, argc);
	int_array = create_positive_array(fat_array, argc);
	free(fat_array);
	if (check_for_some_order(int_array, argc, 0, &i))
		print_best_rotation(i, argc);
	else if (argc < 50)
	{
		A = create_stack_from_int_array(int_array, argc);
		stack_sort(A);
		free_stack(A);
	}
	else
		int_array = bit_sort_raw(int_array, argc, argc - 1);
	free(int_array);
	return (EXIT_SUCCESS);
}
