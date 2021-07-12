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

struct fat_int *parse_numbers(char **num_strings, int nb_items, bool *parse_error)
{
	struct fat_int *array;
	int i;
	int num;

	array = malloc(nb_items * sizeof(struct fat_int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < nb_items && *parse_error == false)
	{
		num = atoi_error(*num_strings++, parse_error);
		array[i].num = num;
		array[i].offset = i;
		i++;
	}
	return (array);
}

int 	main(int argc, char **argv)
{
	int	i;
	int	max;
	struct fat_int*fat_array;
	int	*int_array;
	int	to_rotate;
	t_stack	A;
	bool	error;

	argv++;
	argc--;

	fat_array = parse_numbers(argv, argc, &error);
	if (!fat_array || are_there_duplicates(fat_array, argc) || error)
	{
			free(fat_array);
			write(STDERR_FILENO, "Error\n", sizeof("Error\n"));
			return (-1);
	}

	fat_array = radix_sort_int(fat_array, argc);

	int_array = malloc(argc * sizeof(int));
	i = 0;
	while (i < argc)
	{
		int_array[fat_array[i].offset] = i;
		i++;
	}
	free(fat_array);
	if (check_for_some_order(int_array, argc, 0, &to_rotate))
	{
		if ((float)to_rotate <= (float)argc / 2.0)
			while (to_rotate--)
				ra();
		else
		{
			to_rotate -= argc;
			while (to_rotate++)
				rra();
		}
	}
	else if (argc < 50)
	{
		A = (t_stack){.top = NULL, .size = 0};
		i = 0;
		while(i < argc)
		{
			stack_append(&A, dll_new_node(int_array[i]));
			i++;
		}
		stack_sort(&A);
		empty_stack(&A);
	}
	else
	{
		max = argc - 1;
		i = 0;
		while (max >> i)
			i++;

		int_array = bit_sort_raw(int_array, argc, i);

	}

	free(int_array);

	return (0);
}
